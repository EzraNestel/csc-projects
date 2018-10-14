#include <stdio.h>
#include <stdlib.h>
#define ERROR_MSG ("Illegal_input:_must_be_in_range_1_and_4999_or_0_for_exit\n")
#define BYE_MSG ("You_entered_0_to_exit_bye\n")

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

void printProperRomanString(int d, int dim){
    // this function prints a proper Roman numeral including 'D', 'L', and 'V'
    // that is, XVII instead of XIIIIIII for 17
    // d is the number of letters to be output (i.e., M, C, X, or I)
    // depending on dim, the dimension (i.e., 1000, 100, 10, 1)
    if (dim == 1000) {
        for (int k = 1; k <= d; k++) {
            printf("M");
        }

    } else if (dim == 100) {
        if (d >= 5) {
            printf("D");
            d = d - 5;
        }

        for (int k = 1; k <= d; k++) {
            printf("C");
        }

    } else if (dim == 10) {
        if (d >= 5) {
            printf("L");
            d = d - 5;
        }

        for (int k = 1; k <= d; k++) {
            printf("X");
        }

    } else if (dim == 1) {
        if (d >= 5) {
            printf("V");
            d = d - 5;
        }

        for (int k = 1; k <= d; k++) {
            printf("I");
        }
    }
}//printProperRomanString

void printRoman(int r) {
    // this function calls the functions extractDimDigit and
    // printProperRomanString to print the proper Roman numeral for integer r
    // replace with your code
    int d = 0;
    int dims[4] = {1000,100,10,1};
    printf(FEEDBACK_MSG,r);

    for (int k = 0; k <= 3; k++) {
        d = extractDimDigit(r, dims[k]);
        printProperRomanString(d,dims[k]);
    }
    printf("\n");
}//printRoman

void interactiveRoman(void) {
    int n = 0;
    scanf("%d", &n);
    int r = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &r);
        // Your code here
    }//for
}// interactiveRoman
int main(void) {
    interactiveRoman();
    return EXIT_SUCCESS;
}//main
