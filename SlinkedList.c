// Implementing linked list - abstract data type.

#include <stdio.h>      // for: input & output.
#include <conio.h>      // for: getch();
#include <stdlib.h>     // for: exit(), system();

struct node {
    int data;
    struct node *linkN; 
};

struct node *headN = NULL;
int nodeCount = 1;

void welcomeScreen();
void screenCleaner();

void insertion();
void atBeginning();
void atEnd();
void atSpecificSerial();

void deletion();
void firstNode();
void lastNode();
void specificNode();

void update();

void search();

void sort();
struct node * mergeSort(struct node * );
struct node * split(struct node * ); 
struct node * merge(struct node * , struct node * );

void reverse();

void removeDuplicates();

void tryAgain(int );
void printL();

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
        case 3: 
            update();
            break;
        case 4:
            search();
            break;
        case 5:
            sort();
            break;
        case 6:
            reverse();
            break;
        case 7:
            removeDuplicates();
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

void printL() {
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
            atBeginning();
            printL();
            tryAgain(1);
            break;
        case 2:
            atEnd();
            printL();
            tryAgain(1);
            break;
        case 3: 
            atSpecificSerial();
            printL();
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

void atBeginning() {

    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("\nError: Memory allocation failed!.\n");
        exit(1);
    }

    printf("\nnewNode->data: ");
    scanf("%d", &(newNode->data));

    newNode->linkN = headN;
    headN = newNode;

    nodeCount++;
}

void atEnd() {
    struct node *newNode = malloc(sizeof(struct node));
    if (!newNode) {
        printf("\nError: Memory allocation failed!.\n");
        exit(1);
    } else {
        printf("\nnewNode->data: ");
        scanf("%d", &(newNode->data));
        newNode->linkN = NULL;

        struct node *end = headN;
            
        while(end->linkN != NULL) {
            end = end->linkN;
        }
        end->linkN = newNode;   
    }

    nodeCount++;
}

void atSpecificSerial() {
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

        struct node *p = headN;

        if(index > nodeCount + 1 || index < 1) {
            printf("\nError: Enter a valid serial number.");
            printf("\nPress any key to continue...");
            getch();
            insertion();
        } else if(index == 1) {
            newNode->linkN = headN;
            headN = newNode;
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

    nodeCount++;
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
            firstNode();
            printL();
            tryAgain(2);
            break;
        case 2:
            lastNode();
            printL();
            tryAgain(2);
            break;
        case 3:
            specificNode();
            printL();
            tryAgain(2);
            break;
        case 4:
            welcomeScreen();
            break;
        default:
            printf("\nError! choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            goto label3;
    }
}

void firstNode() {

    struct node *p = headN;
    headN = (headN)->linkN;
        
    free(p);
    p = NULL;

    nodeCount--;
}

void lastNode() {

    if((headN)->linkN == NULL) {
        free(headN);
        headN = NULL;
    } else {
        struct node *p1 = headN;
        struct node *p2 = NULL;

        while(p1->linkN != NULL) {
            p2 = p1;
            p1 = p1->linkN;
        }
        p2->linkN = NULL;
        free(p1);
        p1 = NULL;
    }

    nodeCount--;
}

void specificNode() {
    int index;

    printf("\nserial no.: ");
    scanf("%d", &index);

    if(index >= nodeCount + 1 || index < 1) {
        printf("\nError: Enter a valid serial number.");
        printf("\nPress any key to continue...");
        getch();
        deletion();
    } else if(index == 1) {
        struct node *p = headN;
        headN = (headN)->linkN;
        
        free(p);
        p = NULL;
    } else {
        struct node *p1 = headN;
        struct node *p2 = NULL;

        for(int i = 1; i < index; i++) {
            p2 = p1;
            p1 = p1->linkN;
        }

        p2->linkN = p1->linkN;
        free(p1);
        p1 = NULL;
    }

    nodeCount--;
}

void update() {
    screenCleaner();

    int serial, uData, choice;

    printf("Which node do you want to update?");
    printL();

    printf("\nserial no.: ");
    scanf("%d", &serial);
    printf("data: ");
    scanf("%d", &uData);

    if(serial > nodeCount || serial < 1) {
        printf("\nError: Enter a valid serial number.");
        printf("\nPress any key to continue...");
        getch();
        welcomeScreen();
    } else {
        struct node *p = headN;

        for(int i = 1; i < serial; i++) {
            p = p->linkN;
        }

        p->data = uData;
    }

    printL();

    printf("\n> 1. Continue to update more elements.\n");
    printf("> 2. Exit from this section.\n");
    printf("\nyour choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            update();
            break;
        case 2:
            welcomeScreen();
            break;
        default:
            printf("\nError: Choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            welcomeScreen();
    }
}

void search(){
    screenCleaner();

    int target, i, flag = 0, choice;

    if(headN == NULL) {
        printf("\nError: The list is empty.\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    printL();

    printf("\nelement: ");
    scanf("%d", &target);

    struct node *p = headN;

    for(i = 1; i <= nodeCount; i++) {
        if(target == p->data) {
            flag++;
            break;
        }
        p = p->linkN;
    }

    if(flag == 1) {
        printf("\nserial no.: %d\n", i);
    } else {
        printf("\nelement not found!\n");
    }

    printf("\n> 1. Continue to search elements.\n");
    printf("> 2. Exit from this section.\n");
    printf("\nyour choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            search();
            break;
        case 2:
            welcomeScreen();
            break;
        default:
            printf("\nError: Choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            welcomeScreen();
    }
}

void sort() {
    screenCleaner();

    printL();

    if(headN == NULL || headN->linkN == NULL) {
        printf("\nError: The list is empty or it has only one node!\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    headN = mergeSort(headN);

    printL();

    printf("\nPress any key to continue...");
    getch();
    welcomeScreen();
}

struct node * mergeSort(struct node *headN) {

    if (headN == NULL || headN->linkN == NULL) {
        return headN;
    }

    struct node *second = split(headN);

    headN = mergeSort(headN);
    second = mergeSort(second);

    return merge(headN, second);
}

struct node * split(struct node *headN) {

    struct node *fast = headN->linkN;
    struct node *slow = headN;

    while (fast != NULL && fast->linkN != NULL) {
        fast = fast->linkN->linkN;
        slow = slow->linkN;
    }

    struct node *temp = slow->linkN;
    slow->linkN = NULL;
    return temp;
}

struct node * merge(struct node * first, struct node * second) {

    if(first == NULL) return second;
    if(second == NULL) return first;

    if(first->data < second->data) {
        first->linkN = merge(first->linkN, second);
        return first;
    } else {
        second->linkN = merge(first, second->linkN);
        return second;
    }
}

void reverse() {
    screenCleaner();

    int choice;

    printL();

    if(headN == NULL || headN->linkN == NULL) {
        printf("\nError: The list is empty or it has only one node!\n");
        printf("Press any key to continue...");
        getch();
        welcomeScreen();
    }

    struct node *prev = NULL;
    struct node *current = headN;
    struct node *next = NULL;

    while (current != NULL) {
        next = current->linkN;  // Store the next node
        current->linkN = prev;  // Reverse the link
        prev = current;         // Move prev to current
        current = next;         // Move current to next
    }

    headN = prev;

    printL();

    printf("\n> 1. Reverse one more time OR.\n");
    printf("> 2. Exit from this section.\n");
    printf("\nyour choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            reverse();
            break;
        case 2:
            welcomeScreen();
            break;
        default:
            printf("\nError: Choose from the given options.");
            printf("\nPress any key to continue...");
            getch();
            welcomeScreen();
    }
}

void removeDuplicates() {
    screenCleaner();

    printL();

    if (headN == NULL || headN->linkN == NULL) {
        printf("\nError: The list is empty or has only\n" 
               "one node, no duplicates to remove.\n");
        printf("Press any key to continue...\n");
        getch();
        welcomeScreen();
    }

    struct node *current = headN;
    struct node *temp, *prev;

    while (current != NULL && current->linkN != NULL) {
        prev = current;
        temp = current->linkN;

        while (temp != NULL) {
            if (temp->data == current->data) {
                // Duplicate found, remove it.
                prev->linkN = temp->linkN;
                free(temp);
                temp = prev->linkN;
                nodeCount--;
            } else {
                prev = temp;
                temp = temp->linkN;
            }
        }
        current = current->linkN;
    }

    printL();  // Display the updated list.

    printf("\nPress any key to continue...");
    getch();
    welcomeScreen();
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