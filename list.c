#include "main.h"

void initList(pNode *list) {
	if (*list) {
		atStartList(list);
		removeNodesList(list, NULL);
	}
	*list = (pNode)calloc(1, sizeof(Node));
	(*list)->nav = (pNodeNav)malloc(sizeof(NodeNav));
	(*list)->nav->first = *list;
	(*list)->nav->last = *list;
}

void pushBackList(pString str, pNode list) {
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->nav = list->nav;
	newNode->prev = list->nav->last;
	newNode->next = NULL;
	newNode->prev->next = newNode;

	getStr(str, &(newNode->value));

	newNode->nav->last = newNode;
}

bool nextNodeList(pNode *list) {
	if (*list != (*list)->nav->last) {
		*list = (*list)->next;
		return true;
	}
	return false;
}

void atStartList(pNode *list) {
	*list = (*list)->nav->first;
}

void removeNodesList(pNode *start, pNode *finish) {
	pNode backup = *start;
	pNode endNode;
	if (*start == (*start)->nav->first)
		if (!nextNodeList(start))
			return;

	if (finish != LAST_NODE) {
		(*finish)->prev = (*start)->prev;
		(*start)->prev->next = *finish;
		endNode = *finish;	
	}
	else {
		(*start)->nav->last = (*start)->prev;
		(*start)->prev->next = NULL;
		endNode = NULL;
	}
	
	while (*start != endNode) {
		pNode remove = *start;
		*start = (*start)->next;
		free(remove->value);
		free(remove);
	}

	if (!(*start))
		*start = backup;
}

void listToArray(pNode list, char ***array) {
	atStartList(&list);
	int nodeNum;
	for (nodeNum = 0; nextNodeList(&list); ++nodeNum);
	*array = (char **)calloc(1, (nodeNum + 1) * sizeof(char *));

	atStartList(&list);
	for (nodeNum = 0; nextNodeList(&list); ++nodeNum) {
		getNodeValueList(list, &((*array)[nodeNum]));
	}
}

void getNodeValueList(pNode list, char **str) {
	if (*str) {
		free(*str);
	}

	*str = (char *)malloc((strlen(list->value) + 1) * sizeof(char));
	strcpy(*str, list->value);
}
