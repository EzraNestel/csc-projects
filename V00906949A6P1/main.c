/*  Name: Ezra Nestel
    UVicID: V00906949
    Date: 2018/11/14
    Assignment: Assignment 6, Part 1
    File name: V00906949A6P1
    Description: Functions to manipulate vectors
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VECMAX (6)
#define VALUE (17)
#define LOW (7)
#define HIGH (27)
#define SCALAR1 (5)
#define SCALAR2 (3)
#define SCALAR3 (2)
typedef int Item;
typedef int Index;
typedef Item Vector[VECMAX];

// prototypes for CSC 111 Vector API
// functions for testing Vector API
int main(void);
void printVector(char *msg, Index len, const Vector v);
int prngInt(int iLow, int iHigh);
float prngFloat(float fLow, float fHigh, float precision);
void setVectors(void);
void manipulateVectors(void);

// initialize or set vectors
void setValVector(Index len, Vector v, Item val);
void setIdxVector(Index len, Vector v);
void setRandomVector(Index len, Vector v, Item low, Item high);

// manipulate vectors
void squareVector(Index len, Vector v);
void addScalarVector(Index len, Vector v, Item scalar);
void mulScalarVector(Index len, Vector v, Item scalar);
void divScalarVector(Index len, Vector v, Item scalar);
void addVectors(Index len, const Vector v1, const Vector v2, Vector v3);
void mulVectors(Index len, const Vector v1, const Vector v2, Vector v3);

int main(void) {
    printf("Welcome to Linear Algebra\n");
    setVectors();
    manipulateVectors();
    printf("End Linear Algebra\n");
    return EXIT_SUCCESS;
}//main

void setVectors(void) {
    printf("Begin setVectors\n");
    Vector v1;
    Vector v2;
    Vector v3;
    setValVector(VECMAX, v1, VALUE);
    printVector("setValVector", VECMAX, v1);
    setIdxVector(VECMAX, v2);
    printVector("setIdxVector", VECMAX, v2);
    setRandomVector(VECMAX, v3, LOW, HIGH);
    printVector("setRandomVector", VECMAX, v3);
    printf("End setVectors\n\n");
}//setVectors

void manipulateVectors(void) {
    printf("Begin manipulateVectors\n");
    Vector v1;
    Vector v2;
    Vector v3;
    setRandomVector(VECMAX, v1, LOW, HIGH);
    printVector("setRandomVector v1", VECMAX, v1);
    setRandomVector(VECMAX, v2, LOW, HIGH);
    printVector("setRandomVector v2", VECMAX, v2);
    squareVector(VECMAX, v1);
    printVector("squareVector v1", VECMAX, v1);
    addScalarVector(VECMAX, v2, SCALAR1);
    printVector("addScalarVector v2", VECMAX, v2);
    mulScalarVector(VECMAX, v2, SCALAR2);
    printVector("addScalarVector v2", VECMAX, v2);
    divScalarVector(VECMAX, v2, SCALAR3);
    printVector("divScalarVector v2", VECMAX, v2);
    setRandomVector(VECMAX, v1, LOW, HIGH);
    printVector("setRandomVector v1", VECMAX, v1);
    setRandomVector(VECMAX, v2, LOW, HIGH);
    printVector("setRandomVector v2", VECMAX, v2);
    addVectors(VECMAX, v1, v2, v3);
    printVector("addVectors v3=v1+v2", VECMAX, v3);
    mulVectors(VECMAX, v1, v2, v3);
    printVector("mulVectors v3=v1*v2", VECMAX, v3);
    printf("End manipulateVectors\n\n");
}//manipulateVectors

void printVector(char *msg, Index len, const Vector v) {
    // print all values of 'v' onto one console line
    printf("%s ", msg);
    for (Index k = 0; k < len; k++) printf("%d ", v[k]);
    printf("\n");
}//printVector

void setValVector(Index len, Vector v, Item val) {
    // initialize each component of 'v' with 'val'
    for (Index k = 0; k < len; k++) v[k] = val;
}//setValVector

void setIdxVector(Index len, Vector v) {
    // initialize each component of 'v' with its index
    for (Index j = 0; j < len; j++) {
        v[j] = j;
    }
}//setIdxVector

int prngInt(int iLow, int iHigh) {
    int mod = iHigh - iLow + 1;
    return rand() % mod + iLow;
}//prngInt

float prngFloat(float fLow, float fHigh, float precision) {
    int iLow = (int) (fLow * precision);
    int iHigh = (int) (fHigh * precision);
    int mod = iHigh - iLow + 1;
    int irn = rand() % mod + iLow;
    return ((float) (irn)) / precision;
}//prngFloat

void setRandomVector(Index len, Vector v, Item low, Item high) {
    // initialize each component of 'v' with a pseudo
    // random numbers in the range of 'low' to 'high'
    for (Index k = 0; k < len; k++) v[k] = prngInt(low, high);
}//setRandomVector


void addScalarVector(Index len, Vector v, Item scalar) {
    // add 'scalar' to each component of 'v’
    for (Index j = 0; j < len; j++) {
        v[j] += scalar;
    }
}//addScalarVector

void mulScalarVector(Index len, Vector v, Item scalar) {
    // multiply each component of 'v' by 'scalar'
    for (Index j = 0; j < len; j++) {
        v[j] = v[j]*scalar;
    }
}//mulScalarVector

void divScalarVector(Index len, Vector v, Item scalar) {
    // multiply each component of 'v' by 'scalar'
    for (Index j = 0; j < len; j++) {
        v[j] = v[j]/scalar;
    }
}//divScalarVector

void squareVector(Index len, Vector v) {
    // v[k] = v[k] * v[k]
    for (Index j = 0; j < len; j++) {
        v[j] = v[j] * v[j];
    }
}//squareVector

void addVectors(Index len, const Vector v1, const Vector v2, Vector v3) {
    // v3[k] = v1[k] + v2[k]
    for (Index j = 0; j < len; j++) {
        v3[j] = v1[j] + v2[j];
    }
}//addVectors

void mulVectors(Index len, const Vector v1, const Vector v2, Vector v3) {
    // v3[k] = v1[k] * v2[k]
    for (Index j = 0; j < len; j++) {
        v3[j] = v1[j] * v2[j];
    }
}//mulVectors