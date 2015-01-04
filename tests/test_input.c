#include "unity.h"

#include "Xstring.c"
#include "list.c"
#include "input.h"

#define STDIN 0

void setUp(void)
{
}

void tearDown(void)
{
}

void test_input(void) {
	int fd[2];
	pipe(fd);
	dup2(fd[0], STDIN);
	char *str[] = {
		"test test1 test2\n",
		"test    test1                        test2        \n",
		"test    \"test2   test3\"     test4\n",
		"test    \"  test2           \n",
		"test &test2\n",
		NULL
	};
	char *ans[][250] = {
		{"test", "test1", "test2", NULL},
		{"test", "test1", "test2", NULL},
		{"test", "test2   test3", "test4", NULL},
		{"test", "  test2           ", NULL},
		{"test", "&", "test2"}
	};
	pNode list = NULL;
	int i = 0;
	while (str[i] != NULL) {
		write(fd[1], str[i], strlen(str[i]) * sizeof(char));
		printf("%s", str[i]);
		char out = input(&list);
		int j = 0;
		atStartList(&list);	
		while(ans[i][j] != NULL) {
			list = list->next;
			printf("--(%s)\n", list->value);
			TEST_ASSERT_EQUAL_STRING(list->value, ans[i][j]);
			++j;
		}
		++i;
	} 
}
