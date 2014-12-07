# pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <assert.h>
#include <sys/wait.h>
#include <sys/types.h>

#define DELIMITER '\n'
#define EOS '\0'
#define SEPARATOR ' '
#define BORDER '"'
#define BACKGROUND '&'

#define MULTIPLYER 1.6

typedef struct sstr* pString;
typedef struct sstr {
	char *data;
	size_t length;
	size_t mem_alloc;
} String;

typedef struct sNode* pNode;
typedef struct sNode{
	char *value;
	pNode next;
} Node;

char input(pNode *);
void Xexit();

void clearList(pNode *);
void pushList(pString, pNode *);

void addSymbol(char, pString);
void clearStr(pString *);
void printHello();
void setBackgroundStr(pString *);

void exec(pNode);
void execParent();
void execChild(pNode);
void execCD(pNode);
