#include "main.h"

void exec(pNode list) {
	if (!list)
		return;

	atStartList(&list);
	nextNodeList(&list);

	if (!strcmp(list->value, "cd")) {
		nextNodeList(&list);
		return execCD(list->value);
	}

	if (!strcmp(list->value, "exit"))
		Xexit();

	if (fork())
		return execParent();

	execChild(list);
}

void execParent(void) {
	wait(0);
}

void execChild(pNode list) {
	bool isBackground = false;
	
	cutServiceSymbolsAndCheckErrors(&list, &isBackground);
	if (isBackground) {
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

	char **argv = NULL;
	listToArray(list, &argv);
	execvp(argv[0], argv);
	perror("Wrong input");
	
	exit(EXIT_FAILURE);
}

void execCD(char *path) {
	switch (chdir(path)) {
		case 0: //Directory changed
			break;
		default:
			perror("Error path");
	}
}

void cutServiceSymbolsAndCheckErrors(pNode *list, bool *isBackground) {
	*isBackground = false;
	atStartList(list);

	while (nextNodeList(list)) {
		if (!strcmp((*list)->value, "&")) {
			if (nextNodeList(list)) {
				perror("Wrong request");
				exit(EXIT_FAILURE);
			}
			*isBackground = true;
			removeNodesList(list, LAST_NODE);
			return;
		}
	}
}

void listToArray(pNode list, char ***array) {
	atStartList(&list);
	int nodeNum;
	for (nodeNum = 0; nextNodeList(&list); ++nodeNum);
	*array = (char **)malloc((nodeNum + 1) * sizeof(char *));
	(*array)[nodeNum] = NULL;

	atStartList(&list);
	for (nodeNum = 0; nextNodeList(&list); ++nodeNum) {
		(*array)[nodeNum] = (char *)malloc((strlen(list->value) + 1) * sizeof(char));
		strcpy((*array)[nodeNum], list->value);
	}
}
