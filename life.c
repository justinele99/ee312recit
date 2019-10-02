//
// Created by justi on 9/10/2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "life.h"

void populateWorld(char fname[], char *grid[], int *numRows, int *numCols) {

    FILE *pFile = fopen(fname, "r");
    *numRows = 0; *numCols = 0;
    char buf[BUFSIZ];

    while( fgets(buf, sizeof(buf), pFile) ) {
        char *str = (char *) malloc(strlen(buf));
        grid[*numRows] = strcpy(str,buf);
        (*numRows)++;
    }

    while( grid[0][*numCols] )
        (*numCols)++;

    fclose(pFile);
}

void showWorld(char *grid[], int numRows, int numCols) {

    int i,j;
    for(i = 0; i < numRows; i++) {
        for(j = 0; j < numCols; j++) {
            if(grid[i][j] == '1') {
                printf("*");
            }
            else if(grid[i][j] == '0'){
                printf(".");
            }
            else{
                printf("%c", grid[i][j]);
            }
        }
    }
    printf("\n");
}

void iterateGeneration(char *grid[], int numRows, int numCols) {

    int i, j;
    int neighbors = 0;
    char *newGrid[numRows];

    for(i = 0; i < numRows; i++)
       newGrid[i] = malloc(numCols*sizeof(char));

    copy(newGrid, grid, numRows, numCols);

    for(i = 0; i < numRows; i++) {
        for(j = 0; j < numCols; j++) {
            neighbors = checkNeighbors(grid, i, numRows, j, numCols);

            if((grid[i][j] == '0') && (neighbors > 2 && neighbors < 4)) {
                newGrid[i][j] = '1';
            }
            if((grid[i][j] == '1') && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = '0';
            }
        }
    }

    copy(grid, newGrid, numRows, numCols);

    for(i = 0; i< numRows; i++)
        free(newGrid[i]);
}

void copy(char *grid[], char *origGrid[], int numRows, int numCols) {

    int i;
    for(i = 0; i < numRows; i++)
        memcpy(grid[i], origGrid[i], numCols);
}

int checkNeighbors(char *grid[], int row, int numRows, int cols, int numCols) {

    int neighbors;
    neighbors = 0;

    if((grid[row-1][cols-1] == '1') && (row != 0 && cols != 0)) {
        neighbors++;
    }
    if((grid[row-1][cols] == '1') && row != 0) {
        neighbors++;
    }
    if((grid[row-1][cols+1] == '1') && (row != 0 && cols != numCols)) {
        neighbors++;
    }
    if((grid[row][cols-1] == '1') && cols != 0) {
        neighbors++;
    }
    if((grid[row][cols+1] == '1') && cols != numCols) {
        neighbors++;
    }
    if((grid[row+1][cols-1] == '1') && (row != numRows && cols != 0)) {
        neighbors++;
    }
    if((grid[row+1][cols]  == '1') && row != numRows) {
        neighbors++;
    }
    if((grid[row+1][cols+1] == '1') && (row != numRows && cols != numCols)) {
        neighbors++;
    }

    return neighbors;
}
