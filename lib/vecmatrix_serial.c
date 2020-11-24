// ##-------------------------------- vecmatrix_serial file------------------------------------
// ## Copyright (C) 2020 by
// ## Belinda Brown Ramírez
// ## timna.brown@ucr.ac.cr
// ##	Multiplication of vectors and matrices - Serial
// ##-----------------------------------------------------------------------------

// ##########   IMPORTING  PACKAGES ##########
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ##########DEFINITIONS OF NECESSARY FUNCTIONS##########
// Characteristics
clock_t start, end;

// ########## DEFINITION ##########
//1. Create random matriz and random vector
//2. nx1 X nxn, where n in range of [3, 8]
int vecmatrix_serial()
{
    // ########## VARIABLES ##########
    int i = 0;
    int j = 0;
    int n = 0;

    start = clock(); // begin time mark
    int rand_values = rand() % start;

    // Random dimension [3, 8]
    // example int x =(rand() % 10)+10; from 10 - 20
    int n3 = rand_values % 3; // 0 - 3
    int n8 = rand_values % 8; // 0 - 8
    if (abs(n8 - n3) != 0)
    {
        n = abs(n8 - n3);
    }
    else
    {
        n = 2;
    }

    printf("\nDimension:               %d\n", n);

    ///////////////////////
    int matrix[n][n];
    int vector[n][1];
    int matrix_result[n][n]; // mxn X nxm =  mxm
    ///////////////////////

    // Matrix created
    for (i = 0; i < n; i++) // row
    {
        for (j = 0; j < n; j++) // column
        {
            int value = rand() % start;
            matrix[i][j] = value;
            printf("matrix[%d][%d] = %d \n", i, j, matrix[i][j]);
        }
    }

    printf("\n***************************\n");
    printf("		MATRIX	");
    printf("\n***************************\n");

    for (i = 0; i < n; i++) // row
    {
        for (j = 0; j < n; j++) // column
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    ////////////////////////////////
    printf("\n\n\n\n");
    ////////////////////////////////

    // Vector created
    for (i = 0; i < n; i++) // row
    {
        for (j = 0; j < 1; j++) // column
        {
            int value = rand() % start;
            vector[i][j] = value;
            printf("vector[%d][%d] = %d \n", i, j, vector[i][j]);
        }
    }

    printf("\n***************************\n");
    printf("		Vector 	");
    printf("\n***************************\n");

    for (i = 0; i < n; i++) // row
    {
        for (j = 0; j < 1; j++) // column
        {
            printf("%d ", vector[i][j]);
        }
        printf("\n");
    }

    ////////////////////////////////////
    /////// MULTIPLICATION OF MATRIX
    ///////////////////////////////////
    for (int a = 0; a < 1; a++) // columns vector
    {
        for (int i = 0; i < n; i++) // rows matrix
        {
            int sum = 0;
            for (int j = 0; j < n; j++) // column matrix
            {
                // multiply and sum
                sum += matrix[i][j] * vector[j][a];
            }

            matrix_result[i][a] = sum;
        }
    }

    printf("\n***************************\n");
    printf("		MULTIPLICATION RESULT 	");
    printf("\n***************************\n");

    for (int i = 0; i < n; i++) // row vector
    {
        for (int j = 0; j < n; j++) // column vector
        {
            printf("%d ", matrix_result[i][j]);
        }
        printf("\n");
    }

    return matrix_result[i][j];
}
