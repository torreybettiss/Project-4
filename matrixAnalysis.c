/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <time.h>
#include <stdio.h>
#include "matrixAnalysis.h"

void writeRow()
{
    int i, j;
    
    //Row-Major-Order
    for(i = 0; i < MAX_ROWS; i++)
    {
        for(j = 0; j < MAX_COLUMNS; j++)
        {
            matrix[i][j] = 'A';
        }
    }
}

void writeColumn()
{
    int i, j;
    
    //Column-Major-Order
    for(i = 0; i < MAX_COLUMNS; i++)
    {
        for(j = 0; j < MAX_ROWS; j++)
        {
            matrix[j][i] = 'A';
        }
    }
}

void readRow()
{
    int i,j;
    char read;
    
    //Row-Major-Order
    for(i = 0; i < MAX_ROWS; i++)
    {
        for(j = 0; j < MAX_COLUMNS; j++)
        {
            read = matrix[i][j];
	    read++;
        }
    }
}

void readColumn()
{
    int i, j;
    char read;
    
    //Column_Major-Order
    for(i = 0; i < MAX_COLUMNS; i++)
    {
        for(j = 0; j < MAX_ROWS; j++)
        {
            read = matrix[j][i];
	    read++;
	}
    }
}

void runtimeExperiment()
{
    struct timespec start, finish;
    double times[4] ={0};
   //double wRow[10]={0}; double wCol[10]= {0}; double rRow[10]= {0}; double rCol[10]={0};
    int i;
    
    //Start time
       for(i = 0; i < LOOP; i++)
    {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);   
        writeRow();
        //End time
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);
        //Sum Average
        times[0] += (((double)(finish.tv_sec - start.tv_sec)) + ((double)(finish.tv_nsec - start.tv_nsec)) / 1000000000)/ LOOP;
        //wRow[i] = (((double)(finish.tv_sec - start.tv_sec)) + ((double)(finish.tv_nsec - start.tv_nsec)) / 1000000000);
    }
 
    //Start time
      
    for(i = 0; i < LOOP; i++)
    {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start); 
        writeColumn();
        //End time
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);
        //Sum average
        times[1] += (((double)(finish.tv_sec - start.tv_sec)) + ((double)(finish.tv_nsec - start.tv_nsec)) / 1000000000)/LOOP;
        //wCol[i] = (((double)(finish.tv_sec - start.tv_sec)) + ((double)(finish.tv_nsec - start.tv_nsec)) / 1000000000);
    }
    
    //Start time
      
    for(i = 0; i < LOOP; i++)
    {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start); 
        readRow();
        //End time
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);
        //Sum average
        times[2] += (((double)(finish.tv_sec - start.tv_sec)) + ((double)(finish.tv_nsec - start.tv_nsec)) / 1000000000)/LOOP;
        //rRow[i] = (((double)(finish.tv_sec - start.tv_sec)) + ((double)(finish.tv_nsec - start.tv_nsec)) / 1000000000);

    }
    
    //Start time
   
    for(i = 0; i < LOOP; i++)
    {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start); 
        readColumn();
        //End time
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &finish);
        //Sum average
        times[3] += (((double)(finish.tv_sec - start.tv_sec)) + ((double)(finish.tv_nsec - start.tv_nsec)) / 1000000000)/LOOP;
        //rCol[i] = (((double)(finish.tv_sec - start.tv_sec)) + ((double)(finish.tv_nsec - start.tv_nsec)) / 1000000000);
    }    

    //for(i=0;i<10;i++)
    //{
    //     printf("%.6f,%.6f,%.6f,%.6f\n", wRow[i], wCol[i], rRow[i], rCol[i]);
    //}
    
    //Print results to console
    printRuntimeResults(times);
    
}

void printRuntimeResults(double aveTimes[])
{
    printf("\n\nTest Name    \t Average Time\n");
    printf("-------------\t--------------\n");
    printf("Write Row    \t %.6f\n", aveTimes[0]);
    printf("Write Column \t %.6f\n", aveTimes[1]);
    printf("Read Row     \t %.6f\n", aveTimes[2]);
    printf("Read Column  \t %.6f\n", aveTimes[3]);            
}
