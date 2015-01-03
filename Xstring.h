#ifndef XSTRING_H

#define XSTRING_H
#include "systemHeaders.h"

#define MULTIPLYER 1.6

typedef struct sstr* pString;
typedef struct sstr {
	char *data;
	size_t length;
	size_t mem_alloc;
} String;

void addSymbol(char, pString);
void initStr(pString *);
void clearStr(pString *);
void printHello(void);
void setBackgroundStr(pString *);
void getStr(pString, char **);

#endif