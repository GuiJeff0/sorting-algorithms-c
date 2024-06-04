#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
Author: Guilherme Santos
Date: 06/04/2024
*/

struct listNode {
    int data;
    struct listNode *nextPtr;
    struct listNode *previousPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

// Prototypes
void insertEnqueue(ListNodePtr *headPtr, ListNodePtr *tailPtr, int info);
void printList(ListNodePtr currentPtr);
void deleteEnqueue(ListNodePtr *headPtr, ListNodePtr *tailPtr);
void insertionSort(ListNodePtr *headPtr);

// Main function for testing
int main() {
    ListNodePtr head = NULL;
    ListNodePtr tail = NULL;


    srand(time(NULL));

    // Insert some test data
    for(int i = 0; i < 1000; i++){
        int value = rand() % 1000;
        insertEnqueue(&head, &tail, value);
    }

    // Print original list
    printf("Original list:\n");
    printList(head);

    // Sort the list
    insertionSort(&head);

    // Print sorted list
    printf("\nSorted list:\n");
    printList(head);

    // Clean up
    while (head != NULL) {
        deleteEnqueue(&head, &tail);
    }

    return 0;
}

void insertEnqueue(ListNodePtr *headPtr, ListNodePtr *tailPtr, int info) {
    ListNodePtr newPtr = malloc(sizeof(ListNode));
    if (newPtr != NULL) { // Check if memory is allocated
        newPtr->data = info;
        newPtr->nextPtr = NULL;
        newPtr->previousPtr = *tailPtr;

        if (*headPtr == NULL) { // List is empty
            *headPtr = newPtr;
        } else {
            (*tailPtr)->nextPtr = newPtr;
        }
        *tailPtr = newPtr;
    } else {
        printf("Memory not allocated.\n");
    }
}

void printList(ListNodePtr currentPtr) {
    while (currentPtr != NULL) {
        printf("%d -> ", currentPtr->data);
        currentPtr = currentPtr->nextPtr;
    }
    printf("NULL\n");
}

void deleteEnqueue(ListNodePtr *headPtr, ListNodePtr *tailPtr) {
    if (*headPtr != NULL) {
        ListNodePtr tempPtr = *headPtr;
        *headPtr = (*headPtr)->nextPtr;

        if (*headPtr != NULL) {
            (*headPtr)->previousPtr = NULL;
        } else {
            *tailPtr = NULL;
        }

        free(tempPtr);
    }
}

void insertionSort(ListNodePtr *headPtr) {
    if (*headPtr == NULL || (*headPtr)->nextPtr == NULL) {
        return; // List is empty or has only one element
    }

    ListNodePtr sorted = NULL; // Sorted part of the list
    ListNodePtr current = *headPtr; // Current node to be inserted into sorted part

    while (current != NULL) {
        ListNodePtr next = current->nextPtr;

        if (sorted == NULL || sorted->data >= current->data) {
            current->nextPtr = sorted;
            if (sorted != NULL) {
                sorted->previousPtr = current;
            }
            current->previousPtr = NULL;
            sorted = current;
        } else {
            ListNodePtr temp = sorted;
            while (temp->nextPtr != NULL && temp->nextPtr->data < current->data) {
                temp = temp->nextPtr;
            }
            current->nextPtr = temp->nextPtr;
            if (temp->nextPtr != NULL) {
                temp->nextPtr->previousPtr = current;
            }
            temp->nextPtr = current;
            current->previousPtr = temp;
        }

        current = next;
    }

    *headPtr = sorted;
}
