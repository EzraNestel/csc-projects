/*
 * Name: Ezra Nestel
 * UVicID: V00906949
 * Date: 2018/09/20
 * Assignment: Assignment 2, Part 3
 * File Name: V00906949A2P3.c
 * Description: Prints values of arithmetic and Leonardo sequences
 */

#include <stdio.h>
#include <stdlib.h>

void artithmeticSequence(int start, int diff, int end){
    int k = start;

    printf("ArithmeticSequence:_");

    while(k <= end){
        printf("%d_",k);
        k = k+ diff;
     }
    printf("\n");
}//arithmeticSequence

int leoValue(int n){
    if (n == 0 ||n == 1){
        return 1;
    } else{
        return leoValue(n-1) + leoValue(n-2) + 1;
    }

}


void leonardoSequence(int start, int end){
    int k = start;
    printf("LeonardoSequence:_");

    while(leoValue(k-1) <= end && k <= 12){
        printf("%d_", leoValue(k-1));
        k = k + 1;
    }
    printf("\n");
}//leonardoSequence

int main() {

    artithmeticSequence(3, 2, 17);
    artithmeticSequence(-17, 7, 37);
    artithmeticSequence(0, 29, 199);
    leonardoSequence(1, 137);
    leonardoSequence(2, 69);
    leonardoSequence(5, 177);


    return EXIT_SUCCESS;
}