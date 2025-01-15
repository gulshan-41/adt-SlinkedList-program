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
void atEnd(struct node ** );
void atSpecificSerial(struct node ** );

void deletion();
void firstNode(struct node ** );
void lastNode(struct node ** );

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
        case 2:
            deletion();
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
        printf("Alert: the list is empty!\n");
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
    if(headN == NULL) {
        headN = malloc(sizeof(struct node));
        if(!(headN)) {
            printf("\nError: Memory allocation failed!\n");
            exit(1);
        } else {
            printf("Important: Before inserting further nodes,\n"
                   "in the list must create the head NODE!\n");
            printf("\nheadN->data: ");
            scanf("%d", &(headN->data));

            headN->linkN = NULL;
        }
    }
    
    int choice1;

label2:
    screenCleaner();
    printf("-- Insertion.\n\n");
    printf("Options: \n");
    printf("> 1. At the beginning.\n");
    printf("> 2. At the end.\n");
    printf("> 3. At a specific serial number.\n");
    printf("> 4. Exit from this section.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice1);

    switch(choice1) {
        case 1:
            atBeginning(&headN);
            printL(headN);
            tryAgain(1);
            break;
        case 2:
            atEnd(&headN);
            printL(headN);
            tryAgain(1);
            break;
        case 3: 
            atSpecificSerial(&headN);
            printL(headN);
            tryAgain(1);
            break;
        case 4:
            welcomeScreen();
            break;
        default:
            printf("\nError! choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            goto label2;
    }
}

void atBeginning(struct node **headN) {

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

void atEnd(struct node **headN) {
    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("\nError: Memory allocation failed!.\n");
        exit(1);
    } else {
        printf("\nnewNode->data: ");
        scanf("%d", &(newNode->data));
        newNode->linkN = NULL;

        struct node *end = *headN;
            
        while(end->linkN != NULL) {
            end = end->linkN;
        }
        end->linkN = newNode;   
    }
}

void atSpecificSerial(struct node **headN) {
    int index;

    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("\nError: Memory allocation failed!.\n");
        exit(1);
    } else {
        printf("\nnewNode->data: ");
        scanf("%d", &(newNode->data));
        newNode->linkN = NULL;
        printf("serial: ");
        scanf("%d", &index);

        struct node *p = *headN;

        if(index == 1) {
            newNode->linkN = *headN;
            *headN = newNode;
        } else {
            index = index - 1;
            while(index != 1) {
                p = p->linkN;
                index--;
            }
            newNode->linkN = p->linkN;
            p->linkN = newNode;
        }
    }
}

void deletion() {
    screenCleaner();

    if(headN == NULL) {
        printf("\nAlert: The list is empty.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    int choice2;

label3:
    screenCleaner();
    printf("-- Deletion.\n\n");
    printf("Options: \n");
    printf("> 1. First node.\n");
    printf("> 2. Last node.\n");
    printf("> 3. A specific node.\n");
    printf("> 4. Exit from this section.\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice2);

    switch(choice2) {
        case 1:
            firstNode(&headN);
            printL(headN);
            tryAgain(2);
            break;
        case 2:
            lastNode(&headN);
            printL(headN);
            tryAgain(2);
            break;
        default:
            printf("\nError! choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            goto label3;
    }
}

void firstNode(struct node **headN) {

    struct node *p = *headN;
    *headN = (*headN)->linkN;
        
    free(p);
    p = NULL;
}

void lastNode(struct node **headN) {

    if((*headN)->linkN == NULL) {
        free(*headN);
        *headN = NULL;
    } else {
        struct node *p1 = *headN;
        struct node *p2 = NULL;

        while(p1->linkN != NULL) {
            p2 = p1;
            p1 = p1->linkN;
        }
        p2->linkN = NULL;
        free(p1);
        p1 = NULL;
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
            } else {
                deletion();
            } 
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