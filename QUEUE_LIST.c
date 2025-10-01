#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nodo de la cola
struct Node {
    char data[100];
    struct Node* next;
};

// Cola dinámica
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Crear cola dinámicamente
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Verificar si la cola está vacía
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Agregar elemento
void enqueue(struct Queue* q, const char* value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, value);
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// Eliminar elemento
void dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("La cola está vacía.\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Elemento eliminado: %s\n", temp->data);
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL)
        q->rear = NULL;
}

// Ver primer elemento
void peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("La cola está vacía.\n");
    } else {
        printf("Primer elemento: %s\n", q->front->data);
    }
}

// Mostrar cola
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("La cola está vacía.\n");
        return;
    }

    struct Node* temp = q->front;
    printf("Elementos en la cola:\n");
    while (temp != NULL) {
        printf("- %s\n", temp->data);
        temp = temp->next;
    }
}

// Liberar memoria de la cola
void freeQueue(struct Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// Programa principal
int main() {
    struct Queue* q = createQueue();  // Cola dinámica

    int opcion;
    char input[100];

    do {
        printf("\n--- Menú de Cola Dinámica ---\n");
        printf("1. Enqueue (Agregar)\n");
        printf("2. Dequeue (Eliminar)\n");
        printf("3. Display (Mostrar cola)\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); // Limpiar buffer

        switch (opcion) {
            case 1:
                printf("Ingrese un valor: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = '\0'; // Eliminar salto de línea
                enqueue(q, input);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Liberando memoria y saliendo...\n");
                freeQueue(q);
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 4);

    return 0;
}
