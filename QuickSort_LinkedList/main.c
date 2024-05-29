#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct listNode {
    int data;
    struct listNode *nextPtr;
    struct listNode *previousPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

//Prototype
void insertEnqueue(ListNodePtr *headPtr, ListNodePtr *tailPtr, int info);
void printList(ListNodePtr currentPtr);
void deleteEnqueue(ListNodePtr *headPtr, ListNodePtr *tailPtr);
ListNodePtr partition(ListNodePtr low, ListNodePtr high);
void quickSortRec(ListNodePtr low, ListNodePtr high);


int main() {
    ListNodePtr headPtr = NULL;
    ListNodePtr tailPtr = NULL;

      srand(time(NULL));

    for(int i = 0; i < 100; i++){
        int value = rand() % 1000;
        insertEnqueue(&headPtr, &tailPtr, value);
    }

    printf("Last node: %d\n\n", tailPtr->data);

    printf("Original list:\n");
    printList(headPtr);

    quickSortRec(headPtr, tailPtr);

    printf("Sorted list:\n");
    printList(headPtr);

    // Clean up the memory
    while (headPtr != NULL) {
        deleteEnqueue(&headPtr, &tailPtr);
    }

    return 0;
}


void insertEnqueue(ListNodePtr *headPtr, ListNodePtr *tailPtr, int info) {
    ListNodePtr newPtr = malloc(sizeof(ListNode));

    if (newPtr != NULL) {
        newPtr->data = info;
        newPtr->nextPtr = NULL;
        newPtr->previousPtr = NULL;

        if (*headPtr == NULL && *tailPtr == NULL) {
            *headPtr = newPtr;
            *tailPtr = newPtr;
        } else {
            newPtr->previousPtr = *tailPtr;
            (*tailPtr)->nextPtr = newPtr;
            *tailPtr = newPtr;
        }

    } else {
        printf("memory allocation failure\n");
        return;
    }
}

void printList(ListNodePtr currentPtr) {
    if (currentPtr == NULL) {
        printf("Empty list\n");
    } else {
        while (currentPtr != NULL) {
            printf("%d --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;
        }
        printf("NULL\n\n");
    }
}

void deleteEnqueue(ListNodePtr *headPtr, ListNodePtr *tailPtr) {
    if (*headPtr == NULL) {
        printf("Queue is empty\n");
        return;
    }

    ListNodePtr tempPtr = *headPtr;

    if ((*headPtr)->nextPtr != NULL) {
        (*headPtr)->nextPtr->previousPtr = NULL;
    } else {
        *tailPtr = NULL;
    }

    *headPtr = (*headPtr)->nextPtr;

    if (*headPtr != NULL) {
        (*headPtr)->previousPtr = NULL;
    }

    free(tempPtr);
}

ListNodePtr partition(ListNodePtr low, ListNodePtr high) {
    int pivot = high->data;
    ListNodePtr i = low->previousPtr;
    ListNodePtr j = low;

    while (j != high) {
        if (j->data <= pivot) {
            i = (i == NULL) ? low : i->nextPtr;
            int temp = i->data;
            i->data = j->data;
            j->data = temp;
        }
        j = j->nextPtr;
    }
    i = (i == NULL) ? low : i->nextPtr;
    int temp = i->data;
    i->data = high->data;
    high->data = temp;
    return i;
}

void quickSortRec(ListNodePtr low, ListNodePtr high) {
    if (high != NULL && low != high && low != high->nextPtr) {
        ListNodePtr p = partition(low, high);
        quickSortRec(low, p->previousPtr);
        quickSortRec(p->nextPtr, high);
    }
}

