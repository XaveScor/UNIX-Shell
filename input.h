#ifndef INPUT_H

#define INPUT_H
#include "list.h"
#include "Xstring.h"
#include "systemHeaders.h"

#define DELIMITER '\n'
#define SEPARATOR ' '
#define BORDER '"'
#define BACKGROUND '&'

char input(pNode *);
void Xexit(void);

#endif
