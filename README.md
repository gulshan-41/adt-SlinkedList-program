# adt-SlinkedList-program
C program implementing and demonstrating operations on Singly Linked List. Designed to help beginners understand operations related to Singly Linked List.

<img src="images/welcomeScreen.png" alt="Program Screenshot">

## Features
- Operation including: [Insertion](#insertion-operations), [Deletion](#deletion-operations), [Updation](#update-function), [Searching](#search-function), [Sorting](#sort-functions), [Reverse](#reverse-function), [Removing Duplicates](#removing-duplicates-function).
- Menu driven program for easy interaction.
- Simple and clean code structure.

## Project Structure
``
adt-SlinkedList-program/
|-- SlinkedList.c  # Main program implementing ADT Singly Linked List
|-- README.md  # Project documentation
``

## Requirements
- **C Compiler** (GCC, MinGW, or any compatible)
- **VS Code** or any code editor

## Installation Guide
- Clone the repository using HTTP/SSH URL.
```bash
git clone https://github.com/gulshan-41/adt-SlinkedList-program.git
```
- Navigate to the project directory.
```bash
cd adt-SlinkedList-program.
```

## Program Variables
- struct node { int data; struct node *linkN };
- struct node *headN = NULL;
- int nodeCount = 1;

## Program Functions
Main functions that construct the whole program includes, main(), welcomeScreen(), insertion(), deletion(), update(), search(), sort(), reverse(), removeDuplicates().

## Insertion Operations


- Insert a node at the beginning of the list.
```bash
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
```
- Insert a node at the end of the list.
```bash
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
```
- Insert a node at a specified serial number.
```bash
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

        // The serial number should be between the list, or at the end.
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
```

## Deletion Operations


- Deleting the first node.
```bash
void firstNode() {

    struct node *p = headN;
    headN = (headN)->linkN;
        
    free(p);
    p = NULL;

    nodeCount--;
}
```
- Deleting the last node.
```bash
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
```
- Deleting a specific node, specified by it's serial number.
```bash
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
```
## Update Function
- Update nodes with new data.
```bash
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
```
## Search Function
- Search a specific node, taking reference it's data.
```bash
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
```

## Sort Functions
- Sort the list using merge sort algorithm.
```bash
struct node * mergeSort(struct node *headN) {

    if (headN == NULL || headN->linkN == NULL) {
        return headN;
    }

    struct node *second = split(headN);

    headN = mergeSort(headN);
    second = mergeSort(second);

    return merge(headN, second);
}
```
```bash
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
```
```bash
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
```
## Reverse Function
- Reverse the list.
```bash
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
```
## Removing Duplicates Function
- Traverse through the list and remove duplicates of an element.
```bash
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
```
## Helper Functions
- Helper functions include,. printL(), screenCleaner(), tryAgain(int ).

## Contact
For queries, feel free to reach out:
- Email: main.gulshan2003@gmail.com
- GitHub: [gulshan-41](https://github.com/gulshan-41)
