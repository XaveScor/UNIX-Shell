#include "main.h"

int main() {
	pNode list = NULL;
	char ch;

	printf("\n\n!!Custom UNIX shell!!\n");
	printHello();
	while (ch = input(&list)) {
		if (ch == EOF)
			break;
		//exec(list);
		pNode temp = list;
		while (temp) {
			printf("(%s) ", temp->value);
			temp = temp->next;
		}
		putchar('\n');
		printHello();
	}
	return 0;
}
