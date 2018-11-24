/*
Name: Ezra Nestel
UVicID: V00906949
Date: 2018/11/22
Assignment: Assignment 7, Part 1
File name: V00906949A7P1.c
Description: Converts roman numeral to integers
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 4096
#define PROMPT ("Enter roman numeral_")

// prototypes
int main(void);
int romanToInt(char *s);
void testRoman(void);

int main(void){
    printf("Problem Roman Numeral\n");
    testRoman();
    return EXIT_SUCCESS;
}//main

/* ==================================================
   Roman Numeral to Integer converter
   Parameters:
     s - A null-terminated string containing Roman Numerals in mixed case.
         Subtractive notation is optional for this assignment, so '9' can be represented as 'VIIII'.
         The only characters in s will be 'M','D','C','L','X','V' and 'I'
   Return Value:
     The positive integer value corresponding to the roman numeral
     representation. Note that if the input string is empty (i.e. ""), the
     return value should be zero.
   ==================================================
*/
int romanToInt(char *s){
    int r = 0;
    int i = 0;
    while (s[i] != '\0') {

       if(s[i] == 'M') {
           r = r + 1000;
       } else if (s[i] == 'D'){
           r += 500;
       } else if (s[i] == 'C'){
           r += 100;
       } else if (s[i] == 'L'){
           r += 50;
       } else if (s[i] == 'X'){
           r += 10;
       } else if (s[i] == 'V'){
           r += 5;
       } else if (s[i] == 'I'){
           r += 1;
       }
        i++;
    }
    return r;
}//romanToInt

void testRoman(void){
    char lineBuf[MAXLINE];
    for (;;) {
        printf("%s", PROMPT);
        for (int k=0; k<MAXLINE; k++) lineBuf[k] = '\0';
        fflush(stdout);
        fgets(lineBuf, MAXLINE, stdin);
        if (lineBuf[0] =='\n') break;
        printf("%s = %d\n", lineBuf, romanToInt(lineBuf));
    }//for
}//testRoman