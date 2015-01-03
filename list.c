#include "list.h"

void initList(pNode *list) {
	*list = (pNode)calloc(1, sizeof(Node));
	(*list)->nav = (pNodeNav)malloc(sizeof(NodeNav));
	(*list)->nav->first = *list;
	(*list)->nav->last = *list;
}

void pushBackList(pString str, pNode list) {
}

void changeNodeList(pString str, pNode list) {
}

void nextNodeList(pNode *list) {
}

void atStartList(pNode *list) {
}

void removeNodesList(pNode *start, pNode *finish) {
}

void getValueList(pNode list, char **str) {
}



