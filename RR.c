/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
void insert(int item);
void showHeap(void);
int removeMax(void);
void reHeapDown(int i);
void printTree(void);

#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Function prototypes
void insert(int item);
void showHeap(void);
int removeMax(void);
void reHeapDown(int i);
void printTree(void);
void swap(int *a, int *b);

// Intercambia dos elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Inserta un elemento en el heap
void insert(int item) {
    if (size >= MAX) {
        printf("Heap lleno.\n");
        return;
    }

    int i = size;
    heap[size++] = item;

    // Reheapify hacia arriba
    while (i > 0 && heap[i] > heap[(i - 1) / 2]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    showHeap();
}

// Reheapify hacia abajo desde el índice i
void reHeapDown(int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] > heap[largest])
        largest = left;
    if (right < size && heap[right] > heap[largest])
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        reHeapDown(largest);
    }
}

// Elimina el máximo (raíz) del heap
int removeMax() {
    if (size <= 0) {
        printf("Heap vacío.\n");
        return -1;
    }

    int max = heap[0];
    heap[0] = heap[--size];
    reHeapDown(0);

    showHeap();
    return max;
}

// Muestra el heap como arreglo
void showHeap() {
    printf("Heap: ");
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

// Imprime cada nodo con sus hijos
void printTree() {
    printf("\nEstructura del Heap:\n");
    for (int i = 0; i < size; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        printf("Nodo[%d] = %d", i, heap[i]);
        if (left < size)
            printf(", Izq[%d] = %d", left, heap[left]);
        if (right < size)
            printf(", Der[%d] = %d", right, heap[right]);
        printf("\n");
    }
}

// Programa principal
int main() {
    int elementos[] = {45, 20, 14, 12, 31, 7, 11, 13, 7};
    int n = sizeof(elementos) / sizeof(elementos[0]);

    printf("Insertando elementos:\n");
    for (int i = 0; i < n; i++) {
        insert(elementos[i]);
    }

    printTree();

    int k = 3;
    printf("\nEliminando el máximo %d veces:\n", k);
    for (int i = 0; i < k; i++) {
        int eliminado = removeMax();
        printf("Eliminado: %d\n", eliminado);
    }

    printTree();

    return 0;
}
