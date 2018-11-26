/*
Name: Ezra Nestel
UVicID: V00906949
Date: 2018/11/23
Assignment: Assignment 7, Part 5
File name: V00906949A7P5.c
Description: Inserts a node and printing list backwards
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LOW (11)
#define HIGH (99)
#define MAXGEN (5)

typedef int Key;
typedef struct {
    Key k;
} Item;
typedef Item* ItemRef;

typedef struct NodeStruct* NodeRef;
typedef struct NodeStruct {
    NodeRef next;
    NodeRef prev;
    ItemRef item;
} Node;

typedef struct {
    NodeRef head;
    NodeRef tail;
} DList;
typedef DList* DListRef;

ItemRef createItem(Key val){
    ItemRef ip = (ItemRef)malloc(sizeof(Item));
    ip->k = val;
    return ip;
}//createItem

// prototypes
NodeRef createNode(Key val);
NodeRef insertNodeAtHead(DListRef dlr, Key val);
NodeRef insertNodeAtTail(DListRef dlr, Key val); //write code
void deleteSpecificNode(DListRef dlr, NodeRef xp);
void printListFW(DListRef dlr);
void printListBW(DListRef dlr); //write code
NodeRef findListItem(DListRef dlr, Item key);
DListRef createList(void);
DListRef createNewListAtHead(void);
DListRef createNewListAtTail(void);
void seedPRNG(void);
int prngInt(int iLow, int iHigh);
int main(void);

NodeRef createNode(Key val){
    NodeRef xp = (NodeRef)malloc(sizeof(Node));
    xp->next = NULL;
    xp->prev = NULL;
    xp->item = createItem(val);
    return xp;
}//createNode

NodeRef insertNodeAtHead(DListRef dlr, Key val){
    NodeRef xp = createNode(val);
    if (dlr->head == NULL) {
        dlr->head = xp;
        dlr->tail = xp;
    } else if (dlr->head == dlr->tail) {
        dlr->head->prev = xp;
        xp->next = dlr->head;
        dlr->head = xp;
    } else {
        xp->next = dlr->head;
        dlr->head->prev = xp;
        dlr->head = xp;
    }//if
    return xp;
}//insertNodeAtHead

NodeRef insertNodeAtTail(DListRef dlr, Key val) {
    NodeRef xp = createNode(val);
    if (dlr->tail == NULL) {
        dlr->head = xp;
        dlr->tail = xp;
    } else if (dlr->head == dlr->tail) {
        dlr->head->next = xp;
        xp->prev = dlr->head;
        dlr->tail = xp;
    } else {
        xp->prev = dlr->tail;
        dlr->tail->next = xp;
        dlr->tail = xp;
    }


    return xp;
}//insertNodeAtTail

void printListFW(DListRef dlr){
    printf("Forward list:  ");
    if (dlr == NULL) {
        printf("no list provided\n");
        return;
    } else if (dlr->head == NULL) {
        printf("empty list\n");
        return;
    }//if
    NodeRef xp = dlr->head;
    while (xp != NULL) {
        printf("%d ", xp->item->k);
        xp = xp->next;
    }//while
    printf(" List end\n");
}//printListFW

void printListBW(DListRef dlr){
    printf("Backward list: ");
    // replace with your code
    printf(" List start\n");
}//printListBW

NodeRef findListItem(DListRef dlr, Item key){
    printf("Find list item: ");
    if (dlr == NULL) {
        printf("no list provided\n");
        return NULL;
    } else if (dlr->head == NULL) {
        printf("empty list\n");
        return NULL;
    }//if
    NodeRef xp = dlr->head;
    while (xp != NULL) {
        if (xp->item->k == key.k) {
            printf("value %d found\n", key.k);
            return xp;
        }//if
        xp = xp->next;
    }//while
    printf("value %d not found\n", key.k);
    return NULL;
}//findListItem

DListRef createList(void){
    DListRef dlr = (DListRef)malloc(sizeof(DList));
    dlr->head = NULL;
    dlr->tail = NULL;
    return dlr;
}//createList

void seedPRNG(void) {
    // a seed, so we control the output in iLeap
    int seed;
    printf("Enter seed:_");
    scanf("%d", &seed);
    srand(seed);
}//seedPRNG

int prngInt(int iLow, int iHigh) {
    int mod = iHigh - iLow + 1;
    return rand() % mod + iLow;
}//prngInt

DListRef createNewListAtHead(void) {
    DListRef dlr = createList();
    if (dlr->head != NULL) {
        printf("createNewList: List is not empty\n");
    }//if
    int prn = 0;
    for (int k = 0; k < MAXGEN; k++) {
        prn = prngInt(LOW, HIGH);
        insertNodeAtHead(dlr, prn);
    }//for
    return dlr;
}//createNewListAtHead

DListRef createNewListAtTail(void) {
    DListRef dlr = createList();
    if (dlr->head != NULL) {
        printf("createNewList: List is not empty\n");
    }//if
    int prn = 0;
    for (int k = 0; k < MAXGEN; k++) {
        prn = prngInt(LOW, HIGH);
        insertNodeAtTail(dlr, prn);
    }//for
    return dlr;
}//createNewListAtTail

int main(void) {
    printf("Doubly linked list problems\n");
    Item key = {0};
    NodeRef xp = NULL;
    DListRef dlr1 = createNewListAtHead();
    DListRef dlr2 = createNewListAtTail();
    printListFW(dlr1);
    printListBW(dlr2);
    key.k = 78;
    xp = findListItem(dlr1, key);
    key.k = -33;
    xp = findListItem(dlr2, key);
    return EXIT_SUCCESS;
}//main