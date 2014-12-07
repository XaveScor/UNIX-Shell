#include "main.h"

void exec(pNode list) {
	if (list == NULL)
		return;

	if (!strcmp(list->value, "cd"))
		return execCD(list->next);

	if (!strcmp(list->value, "exit"))
		Xexit();

	if (fork())
		return execParent();

	execChild(list);
}

void execParent() {
	wait(0);
}

void execChild(pNode list) {
	flag_t flag = getFlag(list);

	if (isFlag(flag, FLAG_ERROR)) {
		perror("Wrong input");
		exit(EXIT_FAILURE);
	}
	
	if (isFlag(flag, FLAG_BACKGROUND)) {
		//Отвязываемся от консоли
		if (fork()) {
			exit(EXIT_SUCCESS);
		}
		setsid();

		pid_t childPid;
		// Выводим сообщение о завершении
		if (childPid = fork()) {
			int status;
			wait(&status);

			putchar('\n');
			printf("---------------------\n");
			printf("Process closed.\n");
			printf("pid = %d\n", childPid);
			printf("exit status = %d\n", status);
			printf("---------------------\n");
			exit(EXIT_SUCCESS);
		}

		close(0);
		close(1);
		close(2);
	}

	char **argv;
	listToArray(list, &argv);
	execvp(list->value, argv);
	perror("Wrong input");
	
	exit(EXIT_FAILURE);
}

void execCD(pNode child) {
	if (!child)
		return;

	chdir(child->value);
}
