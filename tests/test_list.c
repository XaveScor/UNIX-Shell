#include "unity.h"

#include "list.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_initList(void) {
	pNode list = NULL;
	initList(&list);
	TEST_ASSERT_EQUAL_INT(1, 1);
}
