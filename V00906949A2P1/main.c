/*
 * Name: Ezra Nestel
   UVicID: V00906949
   Date: 2018/09/20
   Assignment: Assignment 2, Part 1
   File name: V00906949A2P1.c
   Description: This program outputs a fixed-width square box.
 */


#include <stdio.h>
#include <stdlib.h>

int width = 5;
int height = 5;

//Creates a solid *** border
int horBorder(int length) {
    int k = 1;
    while(k <= length){
        printf("*");
        k = k + 1;
    }
    printf("\n");
    return EXIT_SUCCESS;
}//horBorder

//Creates a inner border *_*
int innerBorder(int length) {
    int k = 1;
    printf("*"); //Creates outer border line
    while(k <= length - 2){ //Subtract two for the sides of the wall
        printf("-");
        k = k + 1;
    }//while
    printf("*\n"); //Finishes off the inner wall
    return EXIT_SUCCESS;
}//innerBorder


//Loops the inner border to make box have height, subtracts two for top and bottom border
int loopInnerBorder(int length, int lines){
    int k = 1;

    while(k <= lines - 2){
        innerBorder(length);
        k = k + 1;
    }
    return EXIT_SUCCESS;
}//loopInnerBorder


int box(){
    horBorder(width);
    loopInnerBorder(width, height);
    horBorder(5);
    return EXIT_SUCCESS;
}//box

int main() {

    box();
    box();
    printf("\n");

    return EXIT_SUCCESS;
}//main