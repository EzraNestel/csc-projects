
#include <stdlib.h>
#include <stdio.h>



int main(void) {
    FILE* notPron;
    notPron = fopen("/Users/ezranestel/Documents/GitHub/csc-projects/Playground/not.html","w");
    fprintf(notPron, "<html> \n");
    fprintf(notPron, " <h3> YES </h3> \n");
    fprintf(notPron, "</html> \n");
    fclose("not.html");
    return EXIT_SUCCESS;
}