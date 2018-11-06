
#include <stdlib.h>
#include <stdio.h>


#define SIZE 5

void printArray(int A[], size) {
    for(int k = 0; k < size; k++) {
        printf("%d\n",A[k]);
    }
}

void initArray(int A[], int size) {

    for (int k = 0; k < size; k++) {
        A[k] = k*k;
    }

}

int sumArray(int A[], int size) {
    int sum = 0;
    for (int k = 0; k < size; k++) {
        sum += A[k];
    }
    return sum;
}

int findArraySize(int A[], int searchNumber, int size) {
    int occurNum = 0;
    for (int k = 0; k < size; k++) {
        if (A[k] == searchNumber) {
            occurNum++;
        }
    }

    return occurNum;
}

int findArray(int A[], int searchNumber, int B[], int size) {
    int bIndex = 0;
    for (int k = 0; k < size; k++) {
        if (A[k] == searchNumber) {
            B[bIndex] = k;
            bIndex++;
        }
    }
}

int findMin(int A[], int size) {
    int currentLow = A[0];
    for(int k = 0; k < size; k++) {
        if (currentLow > A[k]) {
            currentLow = A[k];
        }
    }
    return currentLow;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int A[]) {

    int start = SIZE-1;

    for (int k = 0; k < SIZE/2; k++) {
        swap(&A[k],&A[start]);
        start--;
    }


}

int main(void) {
    int A[SIZE];
    A[0] = 1;
    A[1] = 2;
    A[2] = 3;
    A[3] = 1;
    A[4] = 5;
    int B[99];

    //findArray(A, 4, B, SIZE);
    //initArray(&A, SIZE);
    reverse(A);
    printArray(A, SIZE);
    //int min = findMin(A, SIZE);
    //printf("%d", min);
}