#ifndef LIST_H

#define LIST_H
#include "systemHeaders.h"
#include "Xstring.h"

#define LAST_NODE (pNode *)NULL

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
bool nextNodeList(pNode *);
void atStartList(pNode *);
void removeNodesList(pNode *, pNode *);

#endif
