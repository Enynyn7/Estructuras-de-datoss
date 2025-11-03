/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

// Definición del nodo del árbol binario
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Crear un nuevo nodo
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recorrido Preorden: Raíz → Izquierda → Derecha
void preorder(struct Node* node) {
    if (node != NULL) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

// Recorrido Inorden: Izquierda → Raíz → Derecha
void inorder(struct Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

// Recorrido Postorden: Izquierda → Derecha → Raíz
void postorder(struct Node* node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

int main() {
    // Crear árbol binario con al menos 5 nodos
    struct Node* root = createNode(9);
    root->left = createNode(5);
    root->right = createNode(13);
    root->left->left = createNode(3);
    root->left->right = createNode(7);

    // Imprimir recorridos
    printf("Recorrido Preorden: ");
    preorder(root);
    printf("\n");

    printf("Recorrido Inorden: ");
    inorder(root);
    printf("\n");

    printf("Recorrido Postorden: ");
    postorder(root);
    printf("\n");

    return 0;
}
