/*  Name: Ezra Nestel
    UVicID: V00906949
    Date: 2018/11/14
    Assignment: Assignment 6, Part 3
    File name: V00906949A6P3
    Description: Rotation of vector rows
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VECMAX (6)
#define LOW (7)
#define HIGH (27)
#define NPOS (3)
typedef int Item;
typedef int Index;
typedef Item Vector[VECMAX];

// prototypes for CSC 111 Vector API
// functions for testing Vector API
int main(void);
void printVector(char *msg, Index len, const Vector v);
int prngInt(int iLow, int iHigh);
float prngFloat(float fLow, float fHigh, float precision);
void setRandomVector(Index len, Vector v, Item low, Item high);
void reverseRotateVectors(void);

// reverse and rotate vectors
void reverseVector(Index len, Vector v);
void rotateOneLeft(Index len, Vector v);
void rotateOneRight(Index len, Vector v);
void rotateNleft(Index len, Vector v, Index pos);
void rotateNright(Index len, Vector v, Index pos);

int main(void) {
    printf("Welcome to Linear Algebra\n");
    reverseRotateVectors();
    printf("End Linear Algebra\n");
    return EXIT_SUCCESS;
}//main

void reverseRotateVectors(void) {
    printf("Begin reverseRotateVectors\n");
    Index len = VECMAX;
    Item v[VECMAX];
    setRandomVector(len, v, LOW, HIGH);
    printVector("Before reverseVector", len, v);
    reverseVector(len, v);
    printVector("After reverseVector", len, v);
    rotateOneLeft(len, v);
    printVector("After rotateOneLeft", len, v);
    rotateOneRight(len, v);
    printVector("After rotateOneRight", len, v);
    rotateNleft(len, v, NPOS);
    printVector("After rotateNleft", len, v);
    rotateNright(len, v, NPOS);
    printVector("After rotateNright", len, v);
    printf("End reverseRotateVectors\n");
}//reverseRotateVectors

void printVector(char *msg, Index len, const Vector v) {
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
    int iLow = (int) (fLow * precision);
    int iHigh = (int) (fHigh * precision);
    int mod = iHigh - iLow + 1;
    int irn = rand() % mod + iLow;
    return ((float) (irn)) / precision;
}//prngFloat

void setRandomVector(Index len, Vector v, Item low, Item high) {
    // initialize each component of 'v' with a pseudo
    // random numbers in the range of 'low' to 'high'
    v[0] = 8;

    v[1] = 11;
    v[2] = 16;
    v[3] = 26;
    v[4] = 15;
    v[5] = 17;
}//setRandomVector

void reverseVector(Index len, Vector v) {
    // reverse the elements in the array
    // Ex: [1 7 6 2 4] ==> [4 2 6 7 1]
    for (int i = 0; i < len/2; i++) {
        int temp = v[i];
        v[i] = v[len - 1 - i];
        v[len - 1 - i] = temp;
    }
}//reverseVector

void rotateOneLeft(Index len, Vector v) {
    // rotate all array elements one position
    // to the left without losing any elements
    // move the first element into the last
    // Ex: [1 7 6 2 4] ==> [7 6 2 4 1]
    int temp = v[0];
    int i = 0;
    for (i; i < len - 1; i++) {
        v[i] = v[i+1];

    }
    v[i] = temp;
}//rotateOneLeft

void rotateNleft(Index len, Vector v, Index pos) {
    // rotate all array elements N positions
    // to the left without losing any elements
    // the elements that fall of the front
    // are moved to the end of the array
    for (int i = 0; i < pos; i++) {
        rotateOneLeft(len, v);
    }

}//rotateNleft

void rotateOneRight(Index len, Vector v) {
    // rotate all array elements one position
    // to the right without losing any elements
    // move the first element into the last
    // Ex: [1 7 6 2 4] ==> [4 1 7 6 2]
    int rotated[len];
    rotated[0] = v[len - 1];
    for (int i = 0; i < len; i++) {
       rotated[i+1] = v[i];
    }
    for (int i = 0; i < len; i++) {
        v[i] = rotated[i];
    }
}//rotateOneRight

void rotateNright(Index len, Vector v, Index pos) {
    // rotate all array elements N positions
    // to the right without losing any elements
    // the elements that fall of the front
    // are moved to the end of the array
    for (int i = 0; i < pos; i++) {
        rotateOneRight(len, v);
    }
}//rotateNright