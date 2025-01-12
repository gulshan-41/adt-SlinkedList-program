// Implementing linked list - abstract data type.

#include <stdio.h>      // for: input & output.
#include <conio.h>      // for: getch();
#include <stdlib.h>     // for: exit(), system();

struct Node {
    int data;
    struct Node *linkN; 
};

void welcomeScreen();

void main() {
    welcomeScreen();
}

void welcomeScreen() {
    printf("\n-- adt-SlinkedList-program.");
}