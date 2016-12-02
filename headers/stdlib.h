#ifndef UTILITY_H
#define UTILITY_H

#include "types.h"

void memcpy(char *source, char *dest, int nbytes);
void memset(uint8 *dest, uint8 val, uint32 len);
void int_to_ascii(int n, char str[]);
string itoa(int n);
int atoi(string ch)  ;
void * malloc(int nbytes);
#endif
