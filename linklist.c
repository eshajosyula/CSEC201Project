#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

void addNode(struct LinkedList* list, char* cmd) {
    struct node* added = (struct node*)malloc(sizeof(struct node));     //      make a new node
    if (added == NULL) {
        printf("couldn't allocate memory 4 new node.\n");
        exit(1);
    }


    added->cmd = (char*)malloc(strlen(cmd) + 1);     //     make space for the command string + /0
    if (added->cmd == NULL) {
        printf("couldn't allocate memory for cmd string\n");
        free(added);
        exit(1);
    }

    strcpy(added->cmd, cmd);      //     copy the cmd into the node

    added->next = list->head;       //      put it  @ front of the list
    list->head = added;
    list->size++;
}


void printList(struct LinkedList* list) {
    struct node* temp = list->head;
    int i = 1;
    while (temp != NULL) {

        printf("%d: %s\n", i++, temp->cmd);
        temp = temp->next;
    }
    if (i == 1) {
        printf("history is empty\n");
    }
}

void freeList(struct LinkedList* list) {

    while (list->head != NULL) {
        struct node* temp;
        temp = list->head;
        struct node* nextNode;
        nextNode = temp->next;
        free(temp->cmd);        //       free the cmd inside the node
        free(temp);        //       free the node
    }

    list->size = 0;

}
