#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

int _strlen(char *s);

int _isdigit(int c);

int main(int argc, char **argv);

int _putchar(char c);

char *multi(int len, int len1, int len2, char *top, char *bottom, char *res);

void error_msg(void);

void *_calloc(unsigned int nmemb, unsigned int size);

#endif
