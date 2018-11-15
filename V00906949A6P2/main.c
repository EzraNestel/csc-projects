/*
    Name: Ezra Nestel
    UVicID: V00906949
    Date: 2018/11/14
    Assignment: Assignment 6, Part 2
    File name: V00906949A6P2.c
    Description: More advanced linear algebra functions
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define VECMAX (6)
#define LOW (7)
#define HIGH (27)
#define SPECINDEX (3)
#define WILLNOTBEFOUND (-77)
#define NOTFOUND (-1)
typedef int Item;
typedef int Index;
typedef Item Vector[VECMAX];

// prototypes for CSC 111 Vector API
// functions for testing Vector API
int main(void);
void printVector(char* msg, Index len, const Vector v);
void printValueFound(bool found, Item val, Item fidx);
int prngInt(int iLow, int iHigh);
float prngFloat(float fLow, float fHigh, float precision);
void calculateFindVectorValues(void);

// initialize or set vectors
void setRandomVector(Index len, Vector v, Item low, Item high);

// calculate for vectors and find values in vectors
Item sumVector(Index len, const Vector v);
Item dotProductVectors(Index len, const Vector v1, const Vector v2);
Item findMaxInVector(Index len, const Vector v);
Item findMinInVector(Index len, const Vector v);
bool findValueInVector(Index len, const Vector v, Item val, Index* fidx);

int main(void) {
    printf("Welcome to Linear Algebra\n");
    calculateFindVectorValues();
    printf("End Linear Algebra\n");
    return EXIT_SUCCESS;
}//main

void calculateFindVectorValues(void){
    printf("Begin calculateFindVectorValues\n");
    Vector v1;
    Vector v2;
    setRandomVector(VECMAX, v1, LOW, HIGH);
    printVector("setRandomVector v1", VECMAX, v1);
    setRandomVector(VECMAX, v2, LOW, HIGH);
    printVector("setRandomVector v2", VECMAX, v2);
    Item dot = dotProductVectors(VECMAX, v1, v2);
    printf("dotProductVectors = %d\n", dot);
    Item sum = sumVector(VECMAX, v1);
    printf("sumVector = %d\n", sum);
    Item max = findMaxInVector(VECMAX, v1);
    printf("findMaxInVector = %d\n", max);
    Item min = findMinInVector(VECMAX, v1);
    printf("findMinInVector = %d\n", min);
    Index fidx = NOTFOUND;
    Item val = v1[SPECINDEX];
    bool found = findValueInVector(VECMAX, v1, val, &fidx);
    printValueFound(found, val, fidx);
    fidx = NOTFOUND;
    val = WILLNOTBEFOUND;
    found = findValueInVector(VECMAX, v1, val, &fidx);
    printValueFound(found, val, fidx);
    printf("End calculateFindVectorValues\n\n");
}//calculateFindVectorValues

void printValueFound(bool found, Item val, Item fidx) {
    if (found) printf("Value %d found in Vector v1 at index %d\n", val, fidx);
    else printf("Value %d not found in Vector v1\n", val);
}//printValueFound

void printVector(char* msg, Index len, const Vector v) {
    // print all values of 'v' onto one console line
    printf("%s ", msg);
    for (Index k = 0; k < len; k++) printf("%d ", v[k]);
    printf("\n");
}//printVector

int prngInt(int iLow, int iHigh) {
    int mod = iHigh - iLow + 1;
    return rand() % mod + iLow;
}//prngInt

float prngFloat(float fLow, float fHigh, float precision) {
    int iLow = (int)(fLow*precision);
    int iHigh = (int)(fHigh*precision);
    int mod = iHigh - iLow + 1;
    int irn = rand()%mod + iLow;
    return ((float)(irn)) / precision;
}//prngFloat

void setRandomVector(Index len, Vector v, Item low, Item high){
    // initialize each component of 'v' with a pseudo
    // random numbers in the range of 'low' to 'high'
    for (Index k=0; k<len; k++) v[k] = prngInt(low, high);
}//setRandomVector

Item sumVector(Index len, const Vector v){
    int sum = 0;
    for (Index i = 0; i < len; i++) {
        sum = v[i] + sum;
    }
    return sum;
}//sumVector

Item dotProductVectors(Index len, const Vector v1, const Vector v2) {
    // return dot product of v1 and v2
    // Ex: dot product of [1 7 6 2 4] and [3 1 2 1 4] is 40
    int product = 0;
    for (Index i = 0; i < len; i++) {
        product += (v1[i]*v2[i]);
    }
    return product;
}//dotProductVectors

Item findMinInVector(Index len, const Vector v) {
    // find and return min array element
    // Ex: min of [1 7 6 2 4] is 1
    int min = v[0];
    for (Index i = 0; i < len; i++) {
        if (min > v[i]) {
            min = v[i];
        }
    }
    return min;
}//findMinInVector

Item findMaxInVector(Index len, const Vector v) {
    // find and return min array element
    // Ex: max of [1 7 6 2 4] is 7
    int max = v[0];
    for (Index i = 0; i < len; i++) {
        if (max < v[i]) {
            max = v[i];
        }
    }
    return max;
}//findMaxInVector

bool findValueInVector(Index len, const Vector v, Item val, Index* fidx){

    for (Index i = 0; i < len; i++) {
        if (v[i] == val) {
            *fidx = i;
            return true;
        }
    }
    return false;
}//findValueInVector