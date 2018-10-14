/*
 *
 */
#include <stdio.h>
#include <stdlib.h>

int extractDimDigit(int r, int dim) {
    if (dim == 1000){
        return (r/1000) % 10;

    } else if (dim == 100) {
        return (r/100) % 10;

    } else if (dim == 10) {
        return (r/10) % 10;

    } else {
        return (r/1) % 10;
    }
}//extractDimDigit

void printPseudoRomanString(int d, int dim){
    if (dim == 1000) {
        for (int k = 1; k<= d; k++){
            printf("M"); //Roman numeral for 1000
        }
        printf("\n");

    } else if (dim == 100) {
        for (int k = 1; k<= d; k++){
            printf("C"); //Roman numeral for 100
        }
        printf("\n");

    } else if (dim == 10) {
        for (int k = 1; k<= d; k++){
            printf("X"); //Roman numeral for 10
        }
        printf("\n");

    } else if (dim == 1) {
        for (int k = 1; k<= d; k++){
            printf("I"); //Roman numeral for 1
        }
        printf("\n");
    }
}// printPseudoRomanString

int main(void) {
    int r = 4925; // Try different values here to test your program
    int dim = 1000;
    int d = 0;
    for (int k = 0; k<4; k++) {
        d = extractDimDigit(r, dim);
        printf("%d_%4d_%d_", r, dim, d);
        printPseudoRomanString (d, dim);
        dim = dim /10;
    }//for
    return EXIT_SUCCESS;
}//main