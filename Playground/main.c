
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;

}List;

void printList(List l1) {
    Node* tmp;
    tmp = l1.head;

    while(tmp != NULL) {
        printf("%d\n",tmp->value);
        tmp = tmp->next;
    }
}

int main(void) {
    Node n1, n2, n3;
    n1.value = 10;
    n1.next = &n2;
    n2.value = 20;
    n2.next = &n3;
    n3.value = 30;
    n3.next = NULL;

    List l1;
    l1.head = &n1;
    printList(l1);
    return EXIT_SUCCESS;
}