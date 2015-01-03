#ifndef INPUT_H

#define INPUT_H
#include "main.c"

#define DELIMITER '\n'
#define EOS '\0'
#define SEPARATOR ' '
#define BORDER '"'
#define BACKGROUND '&'

#define BACKGROUND_STR "$"

char input(pNode *);
void Xexit();

#endif
