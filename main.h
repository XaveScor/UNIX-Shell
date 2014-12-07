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

#define BACKGROUND_STR "$"

#define FLAG_ERROR      0
#define FLAG_NORMAL     1
#define FLAG_BACKGROUND 2

#define MULTIPLYER 1.6

typedef size_t flag_t;

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
void listToArray(pNode, char ***);
void dropTrushEl(pNode *);
void dropEl(pNode *);

void addSymbol(char, pString);
void clearStr(pString *);
void printHello();
void setBackgroundStr(pString *);

void exec(pNode);
void execParent();
void execChild(pNode);
void execCD(pNode);

flag_t getFlag(pNode);
bool isFlag(flag_t, flag_t);
void addFlag(flag_t *, flag_t);
