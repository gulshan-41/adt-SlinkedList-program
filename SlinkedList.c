// Implementing linked list - abstract data type.

#include <stdio.h>      // for: input & output.
#include <conio.h>      // for: getch();
#include <stdlib.h>     // for: exit(), system();

struct node {
    int data;
    struct node *linkN; 
};

struct node *headN = NULL;

void welcomeScreen();
void screenCleaner();

void insertion();
void atBeginning(struct node ** );

void tryAgain(int );
void printL(struct node *);

void main() {
    welcomeScreen();
}

void welcomeScreen() {
    int choice;

label1:
    screenCleaner();

    printf("-- Demonstrating linkedList as abstract data type.\n\n");

    printf("Read the options carefully and choose.\n");
    printf("> 1. Insertion.\n");
    printf("> 2. Deletion.\n");
    printf("> 3. Update.\n");
    printf("> 4. Search.\n");
    printf("> 5. Sort.\n");
    printf("> 6. Reverse.\n");
    printf("> 7. Remove duplicates.\n");
    printf("> 8. Exit the program.\n\n");

    printf("*NOTE: Before choosing options like deletion, searching,\n"
           "reverse, search.. must insert enough elements.\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            insertion();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Error! choose from the given options.\n");
            printf("Press any key to exit...");
            getch();
            goto label1;
    }
}

void printL(struct node *headN) {
    struct node *p = NULL;
    p = headN;
    
    if(headN == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("\nThe List: ");
    while(p != NULL) {
        printf("| %d |", p->data);
        p = p->linkN;
    }
    printf("\n");
}

void insertion() {
    screenCleaner();
    
    int choice1;

label2:
    screenCleaner();
    printf("-- Insertion.\n\n");
    printf("Options: \n");
    printf("> 1. At the beginning.\n");
    printf("> 2. At the end.\n");
    printf("> 3. At a specific position.\n");
    printf("> 4. Exit from this section.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);

    switch(choice1) {
        case 1:
            atBeginning(&headN);
            printL(headN);
            tryAgain(1);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nError! choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            goto label2;
    }
}

void atBeginning(struct node **headN) {

    if(*headN == NULL) {
        *headN = malloc(sizeof(struct node));
        if(!(*headN)) {
            printf("\nError: Memory allocation failed!\n");
            exit(1);
        } else {
            printf("\nnewNode->data: ");
            scanf("%d", &((*headN)->data));

            (*headN)->linkN = NULL;
        }
    } else {
        struct node *newNode = malloc(sizeof(struct node));
        if (!newNode) {
            printf("\nError: Memory allocation failed!.\n");
            exit(1);
        }

        printf("\nnewNode->data: ");
        scanf("%d", &(newNode->data));

        newNode->linkN = *headN;
        *headN = newNode;
    }
}

void tryAgain(int choice) {
    char ch;

    printf("\nDo you want to try again[y/N]: ");
    scanf(" %c", &ch);

    switch(ch) {
        case 'y':
        case 'Y':
            if(choice == 1) {
                insertion();
            } /* else {
                deletion();
            } */
            break;
        case 'n':
        case 'N':
            welcomeScreen();
            break;
        default:
            printf("\nError: invalid input. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
    }
}

void screenCleaner() {
    system("cls");
    fflush(stdin);
}