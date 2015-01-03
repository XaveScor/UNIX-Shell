#include "unity.h"

#include "Xstring.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_initStr(void) {
	pString str = NULL;
	initStr(&str);
	TEST_ASSERT_EQUAL_STRING(str->data, "");
	TEST_ASSERT_EQUAL_INT(str->length, 0);
	TEST_ASSERT_EQUAL_INT(str->mem_alloc, sizeof(char));
}

void test_clearStr(void) {
	pString str = NULL;
	initStr(&str);
	clearStr(&str);
	TEST_ASSERT_NULL(str);
}

void test_addSymbol(void) {
	pString str = NULL;
	initStr(&str);
	addSymbol('T', str);
	addSymbol('e', str);
	addSymbol('s', str);
	addSymbol('t', str);
	
	TEST_ASSERT_EQUAL_STRING(str->data, "Test");
}

void test_getStr(void) {
	pString str = NULL;
	initStr(&str);
	addSymbol('T', str);
	addSymbol('e', str);
	addSymbol('s', str);
	addSymbol('t', str);
	
	char *cmp = NULL;
	getStr(str, &cmp);
	TEST_ASSERT_EQUAL_STRING(cmp, "Test");
}

void test_setBackgroundStr(void) {
	pString str = NULL;
	setBackgroundStr(&str);
	TEST_ASSERT_EQUAL_STRING(str->data, "&");
}
