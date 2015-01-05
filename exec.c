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

void cutServiceSymbolsAndCheckErrors(pNode *list, pService *service) {
	*service = (pService)calloc(1, sizeof(service_t));
	atStartList(list);

	while (nextNodeList(list)) {
		if (!strcmp((*list)->value, "&")) {
			if (nextNodeList(list)) {
				errorRequest("Wrong Request");
			}
			(*service)->background = true;
			removeNodesList(list, LAST_NODE);
			return;
		}
		getStreamFromNode(list, "<", &((*service)->input));
		getStreamFromNode(list, ">", &((*service)->output));
	}
}

void execChild(pNode list) {
	pService service = NULL;
	
	cutServiceSymbolsAndCheckErrors(&list, &service);
	if (service->output) {
		int fd = open(service->output, O_CREAT, 0664);
		dup2(fd, 1);
	}
	if (service->input) {
		if (access(service->input, R_OK) == -1)
			errorRequest("Input file error");
		int fd = open(service->input, O_RDONLY);
		dup2(fd, 0);
	}

	if (service->background) {
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
	
	errorRequest("Wrong Input");
}

void execCD(char *path) {
	switch (chdir(path)) {
		case 0: //Directory changed
			break;
		default:
			perror("Error path");
	}
}



void errorRequest(const char *error) {
	perror(error);
	exit(EXIT_FAILURE);
}

void getStreamFromNode(pNode *from, const char *sign, char **to) {
	if (!(*from))
		return;

	if (!strcmp((*from)->value, sign)) {
		if (!(*from)->next) {
			errorRequest("WrongRequest");
		}
		getNodeValueList((*from)->next, to);
		removeNodesList(from, &((*from)->next));
	}
}
