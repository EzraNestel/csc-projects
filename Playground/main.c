
#include <stdlib.h>
#include <stdio.h>




int main(void) {
    int q;
    int x = 5;
    int* m = &x;
    q = m;
    printf("%d",q);
    return EXIT_SUCCESS;
}