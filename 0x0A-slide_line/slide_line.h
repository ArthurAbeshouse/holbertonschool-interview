#ifndef SLIDELINE
#define SLIDELINE

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

int slide_line(int *line, size_t size, int direction);
int to_the_left(int *line, size_t size);
int to_the_right(int *line, size_t size);

#endif /*SLIDELINE*/
