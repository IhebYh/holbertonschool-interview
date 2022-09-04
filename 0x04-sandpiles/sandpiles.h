#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stdlib.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void calculate(int grid1[3][3], int grid2[3][3]);
void topple(int grid1[3][3], int grid2[3][3]);
int isUnstable(int grid[3][3]);
void print_sandpile(int grid[3][3]);


#endif /* _SANDPILES_H_ */
