#include "unity.h"

#include "list.c"
#include "Xstring.c"

#include "input.h"

#define STDIN 0

void setUp(void)
{
}

void tearDown(void)
{
}

void test_input(void) {
	char *str[] = {
		"test test1 test2\n",
		"test    test1                        test2        \n",
		"test    \"test2   test3\"     test4\n",
		"test    \"  test2           \n",
		NULL
	};
	char *ans[][250] = {
		{"test", "test1", "test2", NULL},
		{"test", "test1", "test2", NULL},
		{"test", "test2   test3", "test4", NULL},
		{"test", "  test2           ", NULL},
		{NULL}
	};
	pNode list = NULL;
	int i = 0;
	while (str[i] != NULL) {
		write(STDIN, str[i], strlen(str[i]) * sizeof(char) + 1);
		write(1, str[i], strlen(str[i]) * sizeof(char));
		char out = input(&list);
		TEST_ASSERT_EQUAL_INT8(out, DELIMITER);
		int j = 0;
		
		while(ans[i][j] != NULL && false) {
			TEST_ASSERT_EQUAL_STRING(list->value, ans[i][j]);
			nextNodeList(&list);
			++j;
		}
		++i;
	} 
}
