/*
* Name: Ezra Nestel
* UVicID: V00906949
        * Date: 2018/09/20
* Assignment: Assignment 2, Part 2
* File name: V00906949A2P2.c
        * Description: This program outputs a variable square box.
*/

#include <stdio.h>
#include <stdlib.h>

//Prints a border of '*'
void border(int width){
    int k = 1;
    while(k <= width){
        printf("*");
        k = k + 1;
    }
    printf("\n");
}//width

//Loops and prints multiple middle lines of the square (ie. *___*)
void middle(int size){
    int x = 1;
    int y = 1;
    while(y <= size - 2) {
        printf("*"); //Creates outer border line
        while (x <= size - 2) { //Subtract two for the sides of the wall
            printf("-");
            x = x + 1;
        }//while
        printf("*\n"); //Finishes off the inner wall line
        x = 1;
        y = y + 1;
    }//while
}//middle

//Calls middle and border functions to create a box
void box(int size){
    border(size);
    middle(size);
    border(size);
}//box

int main() {
    int size1;
    int size2;
    scanf("%d %d", &size1, &size2);
    box(size1);
    box(size2);
    return EXIT_SUCCESS;
}
