#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows = 4, cols = 4;
    int ** matrix; //puntero doble para la matriz dinamica 

//reservar espacio para los punteros (uno por fila)
matrix = (int **) malloc (rows * sizeof(int*)); 

//reservar espacio para la columna
for(int i =0; i<rows; i++){
   * (matrix + i) = (int*) malloc(cols * sizeof(int));
}
//rellenar la matriz
for(int i = 0; i< rows; i++){
    for(int j= 0; j< cols; j++){
        *(*(matrix +i)+j) = i * cols +j;
    }
printf("Matriz: \n");
for(int i = 0; i<rows; i++){
    for(int j= 0; j<cols; j++){
        printf("%d\n", *(*(matrix +i)+ j));
    }
    printf("\n");
}

}

    
    

    return 0;
}
