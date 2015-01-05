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

#define EOS '\0'
#define DELIMITER '\n'
#define SEPARATOR ' '
#define BORDER '"'
#define BACKGROUND '&'

#define LAST_NODE (pNode *)NULL
#define MULTIPLYER 1.6


typedef struct sNode* pNode;
typedef struct sNodeNav* pNodeNav;
typedef struct sStr* pString;


typedef struct sNodeNav {
	pNode first;
	pNode last;
} NodeNav;

typedef struct sNode {
	char *value;
	pNode next;
	pNode prev;
	pNodeNav nav;
} Node;

typedef struct sStr {
	char *data;
	size_t length;
	size_t mem_alloc;
} String;


char input(pNode *);
void Xexit(void);

void initList(pNode *);
void pushBackList(pString, pNode);
bool nextNodeList(pNode *);
void atStartList(pNode *);
void removeNodesList(pNode *, pNode *);

void addSymbol(char, pString);
void initStr(pString *);
void clearStr(pString *);
void printHello(void);
void setBackgroundStr(pString *);
void getStr(pString, char **);

void exec(pNode);
void execParent(void);
void execChild(pNode);
void execCD(char *);
void cutServiceSymbolsAndCheckErrors(pNode *, bool *);
void listToArray(pNode, char ***);
