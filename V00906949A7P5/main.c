/*
Name: Ezra Nestel
UVicID: V00906949
Date: 2018/11/23
Assignment: Assignment 7, Part 5
File name: V00906949A7P5.c
Description: Shifts column matrix to the right
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE (8)
#define LOW (10)
#define HIGH (99)

typedef int Index;
typedef int Item;
typedef Item Matrix[SIZE][SIZE];
typedef Item Vector[SIZE];

int main(void);
void testRotateColumnsRight(void);
void printMatrix(Matrix A, Index rows, Index cols);
void copyMatrixColumnToVector(Matrix A, Vector V, Index rows, Index cols, Index colf);
void copyMatrixColumnRight(Matrix A, Index rows, Index cols, Index colf, Index colt);
void copyVectorToMatrixColumn(Vector V, Matrix A, Index rows, Index cols, Index colt);
void rotateMatrixColumnsRight(Matrix A, Index rows, Index cols);
void genMatrix(Matrix A, Index rows, Index cols);
void seedPRNG(void);
int prngInt(int iLow, int iHigh);

int main(void) {
    printf("Shift matrix columns right\n");
    testRotateColumnsRight();
    return EXIT_SUCCESS;
}//main

/* ==================================================
   Rotate the columns of a matrix one position to the right.

   Parameters:
     A - matrix
     rows - number of matrix rows
     cols - number of matrix columns
     The function
            Rotate the columns of a matrix one
            position to the right.
            28  51  27      27 28 51
            51  62  84 ==>  84 51 62
            73  35  72      72 73 35
   ==================================================
*/
void rotateMatrixColumnsRight(Matrix A, Index rows, Index cols) {
   // replace with your code
}//rotateMatrixColumnsRight

void testRotateColumnsRight(void){
    Matrix A;
    Vector V;
    genMatrix(A, SIZE, SIZE);
    printMatrix(A, SIZE, SIZE);
    rotateMatrixColumnsRight(A, SIZE, SIZE);
    printMatrix(A, SIZE, SIZE);
}//testRotateColumnsRight

void genMatrix(Matrix A, Index rows, Index cols) {
    for (int row=0; row<rows; row++){
        for (int col=0; col<cols; col++){
            A[row][col] = prngInt(LOW, HIGH);
        }//for
    }//for
}//genMatrix

void printMatrix(Matrix A, Index rows, Index cols) {
    for (int row=0; row<rows; row++){
        for (int col=0; col<cols; col++){
            printf("%4d", A[row][col]);
        }//for
        printf("\n");
    }//for
    printf("\n");
}//printMatrix

void printVector(Vector V, Index rows) {
    for (int row=0; row<rows; row++){
        printf("%4d\n", V[row]);
    }//for
    printf("\n");
}//printVector

void copyMatrixColumnToVector(Matrix A, Vector V, Index rows, Index cols, Index colt){
    for (int k=0; k<rows; k++) V[k] = A[k][colt];
}//copyMatrixColumnToVector

void copyMatrixColumnRight(Matrix A, Index rows, Index cols, Index colf, Index colt){
    for (int k=0; k<rows; k++) A[k][colt] = A[k][colf];
}//copyMatrixColumnRight

void copyVectorToMatrixColumn(Vector V, Matrix A, Index rows, Index cols, Index colt){
    for (int k=0; k<rows; k++) A[k][colt] = V[k];
    printf("colt = %d\n", colt);
}//copyVectorToMatrixColumn

void seedPRNG(void) {
    // a seed, so we control the output in iLeap
    int seed;
    printf("Enter seed:_");
    scanf("%d", &seed);
    srand(seed);
}//seedPRNG

int prngInt(int iLow, int iHigh) {
    int mod = iHigh - iLow + 1;
    return rand() % mod + iLow;
}//prngInt