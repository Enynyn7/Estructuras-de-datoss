/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define V 4

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* adjList[V];

void addEdge(int src, int dest) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = dest;
    newNode->next = adjList[src];
    adjList[src] = newNode;
}

void printAdjList() {
    for (int i = 0; i < V; i++) {
        printf("%c → ", 'A' + i);
        Node* temp = adjList[i];
        while (temp) {
            printf("%c ", 'A' + temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < V; i++)
        adjList[i] = NULL;

    // A → B, A → C, B → D
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);

    printAdjList();

    return 0;
}
