#include "main.h"

char input(pNode *list) {
	char ch = EOS;
	pString str = NULL, backgroundStr = NULL;
	bool state = false;

	initList(list);
	initStr(&str);
	setBackgroundStr(&backgroundStr);

	while (ch = getchar()) {
		if (state)
			switch(ch) {
				case EOF:
				case DELIMITER:
				case BORDER:
					state = false;
					if (ch == BORDER)
						continue;
					break;
				default:
					addSymbol(ch, str);
					continue;
			}

		switch (ch) {
			case BORDER:
				state = true;
				break;

			default:
				addSymbol(ch, str);
				break;

			case BACKGROUND:
			case DELIMITER:
			case EOF:
			case SEPARATOR:
				if (str->length)
					pushBackList(str, *list);

				initStr(&str);
				if (ch == BACKGROUND) {
					pushBackList(backgroundStr, *list);
					continue;
				}
				if (ch == SEPARATOR)
					continue;
				return ch;
		}
	}
	return 0;
}

void Xexit(void) {
	printf("!!Custom UNIX shell closed!!\n\n");
	exit(EXIT_SUCCESS);
}
