#include "main.h"

void clearList(pNode *list) {
	pNode next;
	while (*list) {
		next = (*list)->next;
		free((*list)->value);
		free(*list);
		(*list) = next;
	}
}

void pushList(pString str, pNode *list) {
	if (!strlen(str->data) || !str)
		return;

	pNode el = (pNode)malloc(sizeof(Node));
	assert(el);
	el->value = (char *)malloc(sizeof(char) * (str->length + 1));
	assert(el->value);
	el->next = NULL;

	strcpy(el->value, str->data);

	if (!(*list)) {
		*list = el;
		return;
	}

	pNode temp = *list;
	while (temp->next) {
		temp = temp->next;
	}
	temp->next = el;
}

void listToArray(pNode list, char ***argv) {
	dropTrushEl(&list);
	size_t i = 0;
	pNode temp = list;
	while(temp) {
		++i;
		temp = temp->next;
	}

	*argv = (char **)malloc(sizeof(char *) * (i + 1)); // Last pointer is NULL
	i = 0;
	temp = list;
	while(temp) {
		(*argv)[i] = (char *)malloc(sizeof(char) * (strlen(temp->value) + 1)); // strlen not calculate a last '\0' symbol
		strcpy((*argv)[i], temp->value);
		temp = temp->next;
		++i;
	}
	(*argv)[i] = NULL;

}

void dropTrushEl(pNode *list) {
	pNode temp = *list;
	while (temp) {
		if (!strcmp(BACKGROUND_STR, temp->value)) {
			dropEl(&temp);
		}
		temp = temp->next;
	}
}

void dropEl(pNode *el) {
	pNode backup = (*el)->next;
	free((*el)->value);
	free(*el);
	*el = backup;
}
