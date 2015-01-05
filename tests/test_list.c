#include "unity.h"

#include "list.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void addStr2String(const char *oldStr, pString str) {
	int i;
	for (i = 0; oldStr[i] != '\0'; ++i)
		addSymbol(oldStr[i], str);
}

void test_initList(void) {
	pNode list = NULL;
	initList(&list);
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NULL(list->next);
	TEST_ASSERT_NULL(list->prev);
	TEST_ASSERT_NOT_NULL(list->nav);
	TEST_ASSERT_EQUAL_PTR(list->nav->first, list);
	TEST_ASSERT_EQUAL_PTR(list->nav->last, list);
	TEST_ASSERT_NULL(list->value);
}

void test_pushBackList(void) {
	pNode list = NULL;
	pString str = NULL;
	initList(&list);
	initStr(&str);

	addStr2String("Test", str);
	pushBackList(str, list);
	addSymbol('1', str);
	pushBackList(str, list);	

	TEST_ASSERT_NOT_NULL(list->next);
	TEST_ASSERT_NOT_NULL(list->next->next);
	TEST_ASSERT_NULL(list->next->next->next);

	TEST_ASSERT_EQUAL_PTR(list->next->prev, list);
	TEST_ASSERT_EQUAL_PTR(list->next->next->prev, list->next);
	TEST_ASSERT_EQUAL_PTR(list->next->nav, list->next->next->nav);
	TEST_ASSERT_EQUAL_PTR(list->next->nav, list->nav);
	TEST_ASSERT_EQUAL_PTR(list->nav->first, list);
	TEST_ASSERT_EQUAL_PTR(list->nav->last, list->next->next);

	TEST_ASSERT_EQUAL_STRING(list->next->value, "Test");
	TEST_ASSERT_EQUAL_STRING(list->next->next->value, "Test1");
}

void test_atStartList(void) {
	pNode list = NULL;
	pString str = NULL;
	initList(&list);
	initStr(&str);
	
	addStr2String("Test", str);
	pushBackList(str, list);
	list = list->next;
	atStartList(&list);

	TEST_ASSERT_EQUAL_PTR(list, list->nav->first);
	TEST_ASSERT_NULL(list->prev);
	TEST_ASSERT_NULL(list->value);

	TEST_ASSERT_NOT_NULL(list->next);
	TEST_ASSERT_EQUAL_STRING(list->next->value, "Test");
}

void test_nextNodeList(void) {
	pNode list = NULL;
	pString str = NULL;
	initList(&list);
	initStr(&str);
	
	addStr2String("Test", str);
	pushBackList(str, list);

	nextNodeList(&list);
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_EQUAL_STRING(list->value, "Test");
	
	nextNodeList(&list);
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_EQUAL_STRING(list->value, "Test");
}

void test_removeNodesList(void) {
	pNode list = NULL;
	pString str = NULL;
	initList(&list);
	initStr(&str);

	addStr2String("Test", str);
	pushBackList(str, list);
	addSymbol('1', str);
	pushBackList(str, list);

	//Test 1. start = first; remove first node
	removeNodesList(&list, &(list->next->next));
	atStartList(&list);
	TEST_ASSERT_NOT_NULL(list->next);
	TEST_ASSERT_EQUAL_STRING(list->next->value, "Test1");


	//Test 2. finish = LAST_NODE
	addSymbol('2', str);
	pushBackList(str, list);
	atStartList(&list);
	removeNodesList(&list, LAST_NODE);
	TEST_ASSERT_EQUAL_PTR(list, list->nav->last);
	TEST_ASSERT_NULL(list->next); 
}

void test_listToArray(void) {
	pNode list = NULL;
	pString str = NULL;
	char *ans[] = {"Test", "Test1", "Test12"};	

	initList(&list);
	initStr(&str);
	
	addStr2String("Test", str);
	pushBackList(str,list);
	addSymbol('1', str);
	pushBackList(str, list);
	addSymbol('2', str);
	pushBackList(str, list);

	char **array = NULL;
	listToArray(list, &array);
	int i;
	for (i = 0; i < 3; ++i) {
		TEST_ASSERT_NOT_NULL(array[i]);
		TEST_ASSERT_EQUAL_STRING(array[i], ans[i]);
	}
	TEST_ASSERT_NULL(array[3]);
}

void test_getNodeValueList(void) {
	pNode list = NULL;
	pString str = NULL;
	char *ans[] = {"Test", "Test1", "Test12"};	

	initList(&list);
	initStr(&str);
	
	addStr2String("Test", str);
	pushBackList(str,list);
	addSymbol('1', str);
	pushBackList(str, list);
	addSymbol('2', str);
	pushBackList(str, list);

	char *testStr = NULL;
	int i;
	for (i = 0; i < 3; ++i) {
		nextNodeList(&list);
		getNodeValueList(list, &testStr);
		TEST_ASSERT_NOT_NULL(testStr);
		TEST_ASSERT_EQUAL_STRING(testStr, ans[i]);
	}
}
