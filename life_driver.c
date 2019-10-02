//life_driver.c
//
//Life Driver program
//Roger Priebe 9/5/2018
//EE 312

/* Student information for project:
 *
 * On my honor, Justine, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Justine Le
 * email address: justinele99@utexas.edu
 * UTEID: JL65773
 * Section 5 digit ID: 16015
 *
 */

//This file is a driver program for the life.c module.
//This program must work with your implementations life.h and life.c
//Do not change the function definitions for populateWorld, showWorld or
//iterateGeneration.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "life.h"

int main(int argc, char *argv[]) {

    //char fName[] = "world.txt";
    //const int numGenerations = 5;

    char fName[strlen(argv[1])];
    strcpy(fName, argv[1]);
    const int numGenerations = atoi(argv[2]);

    const int MAX_ROWS = 80;
    char *world[MAX_ROWS];
    int numRows;
    int numCols;

    populateWorld(fName, world, &numRows, &numCols);

    showWorld(world, numRows, numCols);

    for (int iteration = 0; iteration < numGenerations; iteration++) {

        system("clear"); //Linux only

        iterateGeneration(world, numRows, numCols);

        showWorld(world, numRows, numCols);
    }

    return 0;
}
