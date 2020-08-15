#ifndef SANDPILE_H_
#define SANDPILE_H_

#include "stdio.h"
#include "stdlib.h"
#include "stddef.h"
#include "string.h"

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_matrix(int grid[3][3]);
void add_sandpiles(int grid1[3][3], int grid2[3][3]);
int verify_if_stable(int grid[3][3]);
void collapse_sandpile(int grid1[3][3], int grid2[3][3]);

#endif
