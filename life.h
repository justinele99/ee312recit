// life.h
// -- EE 312 Project 2

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

#ifndef UNTITLED1_LIFE_H
#define UNTITLED1_LIFE_H

#endif //UNTITLED1_LIFE_H

/* Function: populateWorld
 * Objective: Load .txt file into an array and find parameters
 * Input: .txt file name, pointer to array, address to store number of rows and columns
 * Output: void
 */
void populateWorld(char fname[], char *grid[], int *numRows, int *numCols);

/* Function: showWorld
 * Objective: Print values from array into console
 * Input: pointer to array, max number of rows and columns for array
 * Output: void
 */
void showWorld(char *grid[], int numRows, int numCols);

/* Function: iterateGeneration
 * Objective: Check the neighbors of the cells in an array to determine new state
 * Input: pointer to array, max number of rows and columns for array
 * Output: void
 */
void iterateGeneration(char *grid[], int numRows, int numCols);

/* Function: copy
 * Objective: Copy the values from an array into another array of similar size
 * Input: pointer to array, pointer to second array, max number of rows and columns for array
 * Output: void
 */
void copy(char *grid[], char *origGrid[], int numRows, int numCols);

/* Function: checkNeighbors
 * Objective: Given a cell search and count the number of living cells nearby
 * Input: pointer to array, row and column of given cell, max number of rows and columns for array
 * Output: number of neighbors
 */
int  checkNeighbors(char *grid[], int row, int numRows, int cols, int numCols);
