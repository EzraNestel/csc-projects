/*
Name: Ezra Nestel
UVicID: V00906949
Date: 2018/11/22
Assignment: Assignment 7, Part 3
File name: V00906949A7P3.c
Description: Converts low case to up case and vise versa
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 4096
#define PROMPT ("Enter string_")

// prototypes
int main(void);
void invertCase(char *s);
void testInvertCase(void);
void initBuf(char* s, int len);
void replaceNewlines(char* s, int len);
void copyBuf(const char* is, char* os, int len);

int main(void){
    printf("Problem Invert Case\n");
    testInvertCase();
    return EXIT_SUCCESS;
}//main

/* ==================================================
   Invert the capitalization of a string
   Parameters:
    s - A null-terminated character string.
   Result:
    The function should convert every lowercase character in the string s to
    uppercase, and every uppercase character to lowercase (and store the
    modified character back into s). Characters which are not uppercase
    or lowercase letters must be left as-is. For example, if the input string
    is "Csc111", this function would convert it to "cSC111". The standard
    library functions 'islower', 'isupper', 'tolower' and 'toupper' may be
    helpful for this.
   ==================================================
*/
void invertCase(char* s){
    int i = 0;
    char letter;
    while (s[i] != '\0'){
        letter = s[i];
        if (islower(s[i]) == 1) {
            s[i] = (char) toupper(letter);

        } else if (isupper(s[i]) == 1) {

            s[i] = (char) tolower(letter);
        } 

        i++;
    }
}//invertCase

// testInvertCase - Test the invertCase function (Task 2)
void testInvertCase(void){
    char isb[MAXLINE]; //input string buffer
    char osb[MAXLINE]; //input string buffer
    for (;;) {
        printf("%s", PROMPT);
        fflush(stdout);
        initBuf(isb, MAXLINE);
        fgets(isb, MAXLINE, stdin);
        if (isb[0] == '\n') break; //exit success
        replaceNewlines(isb, MAXLINE);
        copyBuf(isb, osb, MAXLINE);
        invertCase(osb);
        printf("%s invert case %s\n", isb, osb);
    }//for
}//testInvertCase

void initBuf(char* s, int len) {
    for (int k=0; k<len; k++) s[k] = '\0';
}//initBuf

void replaceNewlines(char* s, int len) {
    for (int k=0; k<len; k++) {
        if (s[k] == '\n') s[k] = '\0';
    }//for
}//replaceNewlines

void copyBuf(const char* is, char* os, int len) {
    for (int k=0; k<len; k++) os[k] = is[k];
}//copyBuf