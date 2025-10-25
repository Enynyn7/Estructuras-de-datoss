/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
//matrix of 4x4 ABCD

#define V 4

int main() {
    int adjMatrix[V][V] = {0};

    // Mapping: A=0, B=1, C=2, D=3
    adjMatrix[0][1] = 1; // A-B
    adjMatrix[1][0] = 1;

    adjMatrix[0][2] = 1; // A-C
    adjMatrix[2][0] = 1;

    adjMatrix[1][3] = 1; // B-D
    adjMatrix[3][1] = 1;

    // Print the matrix
    printf("Adjacency Matrix:\n   A B C D\n");
    for (int i = 0; i < V; i++) {
        printf("%c ", 'A' + i);
        for (int j = 0; j < V; j++) {
            printf(" %d", adjMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
    

