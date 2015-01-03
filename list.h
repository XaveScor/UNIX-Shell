#ifndef LIST_H

#define LIST_H
#include "Xstring.h"

typedef struct Node* pNode;
typedef struct sNode {
	char *value;
	pNode next;
} Node;

void initList(pNode *);
void pushBackList(pString, pNode);
void changeNodeList(pString, pNode);
void nextNodeList(pNode *);
void atStartList(pNode *);
void removeNodesList(pNode *, pNode *);
void getValueList(pNode, char **);

#endif
