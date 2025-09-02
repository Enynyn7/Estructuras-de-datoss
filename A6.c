/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>

int main()
{
//definir filas y columnas 
int rows, cols;
//solicitar al usuario los datos
printf("Dame los numeros de la fila: \n");
scanf("%d", &rows);
printf("Dame el numero de columnas: \n");
scanf("%d", &cols);

//reservar la memoria para las filas A B C
int **A = (int **) malloc(rows * sizeof(int*));
int ** B= (int **)malloc(rows *sizeof(int*));
int**C = (int**)malloc(rows*sizeof(int*));

//reservar memoria para las columnas y con A+i accede a todas
for(int i=0; i<rows; i++){
*(A+i)= (int*)malloc(cols * sizeof(int));
*(B+i)=(int*)malloc(cols * sizeof(int));
*(C+i)=(int*)malloc(cols * sizeof(int));

}

//rellenar la matriz con datos proporcionados por el usuario
printf("ingresa los elementos de la matriz A: \n ");
for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
        printf("A[%d][%d]:", i, j);
        scanf("%d", (*A+i)+j);
    }
}

//rellenar la matriz con datos del usuario 
printf("Ingresa los elementos de la matriz B: \n ");
for(int i= 0; i<rows; i++){
    for(int j=0; j<cols;j++){
        printf("B[%d][%d]:", i, j);
        scanf("%d", *(B+i)+j);
    }
}

//calcular la suma de C= A+B 
for(int i=0; i<rows; i++){
    for(int j=0; j<cols; j++){
        *(*(C+i)+j)=*(*(A+i)+j)+ *(*(B+i)+j);
        
    }
}

//imprimir resultado de C 
printf("El resultado de la matriz A+B :\n");
for(int i= 0; i<rows; i++){
    for(int j=0; j<cols; j++){
        printf("%d", *(*C+i )+j );
    }
}

    return 0;
}