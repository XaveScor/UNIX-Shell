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
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NOT_NULL(list->nav);
	TEST_ASSERT_NULL(list->next);
	TEST_ASSERT_NULL(list->prev);
	TEST_ASSERT_EQUAL_PTR(list->nav->first, list);
	TEST_ASSERT_EQUAL_PTR(list->nav->last, list);
}
