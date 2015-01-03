#include "Xstring.h"

void addSymbol(char ch, pString str) {
	if (str->mem_alloc == str->length + 1) {
		str->mem_alloc = (size_t)(MULTIPLYER * str->mem_alloc + 1.0);
		str->data = (char *)realloc(str->data, sizeof(char) * str->mem_alloc);
	}
	str->data[str->length++] = ch;
	str->data[str->length] = EOS;
}

void clearStr(pString *str) {
	if (*str) {
		free((*str)->data);
		free(*str);	
	}
	*str = NULL;
}

void initStr(pString *str) {
	clearStr(str);
	*str = (pString)malloc(sizeof(String));
	assert(*str);
	(*str)->data = (char *)calloc(1, sizeof(char));
	assert((*str)->data);
	(*str)->length = 0;
	(*str)->mem_alloc = sizeof(char);
}

void printHello(void) {
	char *cwd = malloc(sizeof(char) * 256);
	getcwd(cwd, 256);
	printf("%s: ", cwd);
	free(cwd);
}

void setBackgroundStr(pString *str) {
	clearStr(str);
	*str = (pString)malloc(sizeof(String));
	assert(*str);
	
	(*str)->mem_alloc = 2 * sizeof(char);
	(*str)->data = (char *)malloc((*str)->mem_alloc);
	assert((*str)->data);	

	(*str)->data[0] = '&';
	(*str)->data[1] = '\0';
	(*str)->length = 1;
}

void getStr(pString str, char **value) {
	free(*value);
	*value = (char *)malloc((1 + str->length) * sizeof(char));
	memcpy(*value, str->data, (str->length + 1) * sizeof(char));
}
