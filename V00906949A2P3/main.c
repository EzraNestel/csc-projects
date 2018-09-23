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


}


void leonardoSequence(int start, int end){
    int k = start;

    printf("LeonardoSequence:_%d_",k);

    while(leoValue(k) <= end){

        if (k == 0 || k == 1) {
            k = 1;
        }else{
            k = leoValue(k-1) + (leoValue(k-2) + 1);
        }

    }//while
    printf("Fin\n");
}//leonardoSequence

int main() {

    //artithmeticSequence(3, 2, 17);
   // artithmeticSequence(-17, 7, 37);
   // artithmeticSequence(0, 29, 199);
    leonardoSequence(1, 137);
    leonardoSequence(2, 69);
    leonardoSequence(5, 177);

    printf("\n");
    return EXIT_SUCCESS;
}