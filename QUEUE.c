/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define QUEUESIZE 5 //global size 5 elements in the array 
int queue[QUEUESIZE];//array named queue is defined with the queuesize of 5 
int front= 0; //iniciate in the position 0
int rear=0; //iniciate in the position 0 


//function to check if the queue is full 
int isfull(){
return rear==QUEUESIZE;
}

//function to check if the queue is empty by knowing that the fist and the last position are in the same position
int isempty(){
    return front==rear;
}
//enqueue operation 
void enqueue(int value){
    if(isfull()){
        printf("queue is full, cannot enqueue\n");
    }
    else{
        queue[rear++] = value;
        printf("Enqueued: %d\n", value);
        }
    }

//dequeue operation
void dequeue(){
    if(isempty()){
        printf("cannot dequeue. Is empty");
    }
    else{
        int value = queue[front++];
        printf("Dequeued: %d\n", value);
    }
}

//display queue
void displayQueue(){
    if(isempty()){
        printf("The queue is empty. No elements");
    } 
    else{
    printf("Queue contents: \n");
    for(int i=front; i<rear; i++){
        printf("%d", queue[i]);
    }
    printf("\n");
    }
}

int main() 
{
int option;
int value;
//cases for different options
while(1){
 printf("\nSeleccione una opción:\n");
        printf("1. Encolar\n");
        printf("2. Desencolar\n");
        printf("3. Salir\n");
        printf("Opción: ");
        scanf("%d", &option);

switch (option) {
            case 1:
                printf("Ingrese el valor a encolar: ");
                scanf("%d", &value);
                enqueue(value);
                displayQueue();
                break;
            case 2:
                dequeue();
                displayQueue();
                break;
            case 3:
                printf("Saliendo del programa.\n");
                return 0;
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
}


    return 0;
}