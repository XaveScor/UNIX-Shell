#ifndef FLAG_H

#define FLAG_H
#include "main.h"

typedef bool flag_t

#define FLAG_ERROR      0
#define FLAG_NORMAL     1
#define FLAG_BACKGROUND 2

flag_t getFlag(pNode);
bool isFlag(flag_t, flag_t);
void addFlag(flag_t *, flag_t);

#endif
