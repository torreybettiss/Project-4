/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   matrixAnalysis.h
 * Author: Ashley Miller / Torrey Bettis
 * Info: COP4634 P4
 * Created on October 31, 2016, 8:00 PM
 */

#ifndef MATRIXANALYSIS_H
#define MATRIXANALYSIS_H

#define MAX_ROWS 20480
#define MAX_COLUMNS 4096
#define LOOP 10

char matrix[MAX_ROWS][MAX_COLUMNS];

/*
 * Writes a '!' value to each element in the array
 * using row-major order.
 * @param: nothing
 * @returns: nothing
 */
void writeRow();

/*
 * Writes a '!' value to each element in the array
 * using column-major order.
 * @param: nothing
 * @returns: nothing
 */
void writeColumn();

/*
 * Reads the elements of the matrix in 
 * row-major order.
 * @param: nothing
 * @returns: nothing
 */
void readRow();

/*
 * Reads the elements of the matrix in
 * column-major order.
 * @param: nothing
 * @returns: nothing
 */
void readColumn();

/*
 * Runs the runtime experiment where the elements
 * in the matrix is being read from and written to.
 * @param: nothing
 * @return: nothing
 */
void runtimeExperiment();

/*
 * Prints the results from the runtime experiment
 * @param: array of times
 * @returns: nothing
 */
void printRuntimeResults(double *);







#endif /* MATRIXANALYSIS_H */

