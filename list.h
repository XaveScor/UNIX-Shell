#ifndef LIST_H

#define LIST_H
#include "systemHeaders.h"
#include "Xstring.h"

typedef struct sNode* pNode;
typedef struct sNodeNav* pNodeNav;

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

void initList(pNode *);
void pushBackList(pString, pNode);
void changeNodeList(pString, pNode);
void nextNodeList(pNode *);
void atStartList(pNode *);
void removeNodesList(pNode *, pNode *);
void getValueList(pNode, char **);

#endif
