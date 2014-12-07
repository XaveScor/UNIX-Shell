#include "main.h"

flag_t getFlag(pNode list) {
	flag_t flag = FLAG_NORMAL;
	while (list) {
		if (!strcmp("&", list->value)) {
			addFlag(&flag, FLAG_BACKGROUND);
			if (list->next)
				addFlag(&flag, FLAG_ERROR);
		}
		list = list->next;
	}
	return flag;
}

bool isFlag(flag_t flag, flag_t current) {
	return (flag & current);
}

void addFlag(flag_t *flag, flag_t additional) {
	if (additional == FLAG_ERROR) {
		*flag = FLAG_ERROR;
	}
	else {
		*flag |= additional;
	}
}
