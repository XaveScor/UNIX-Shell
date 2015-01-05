#include "unity.h"

#include "exec.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_cutServiceSymbolsAndCheckErrors(void) {
	pNode list = NULL;
	pService service = NULL;
	char *str = "test > test1 < test2&\n";
	int fd[2];
	pipe(fd);
	dup2(fd[0], 0);
	write(fd[1], str, strlen(str) * sizeof(char));
	input(&list);
	cutServiceSymbolsAndCheckErrors(&list, &service);
	TEST_ASSERT_NOT_NULL(service);
	TEST_ASSERT_EQUAL_INT(service->background, 1);
	TEST_ASSERT_NOT_NULL(service->output);
	TEST_ASSERT_EQUAL_STRING(service->output, "test1");
	TEST_ASSERT_NOT_NULL(service->input);
	TEST_ASSERT_EQUAL_STRING(service->input, "test2");
}
