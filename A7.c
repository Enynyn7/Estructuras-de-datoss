/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    //abrir el archivo usando apuntador file en modo lectura, sino devuelve error con NULL
FILE *file= fopen("sales.txt", "r");
if(file==NULL){
    printf("Error al abrir el archivo\n");
    return 1;
}
//contar el numero de lineas usando fgets
char line [100];
int count=0;
while(fgets(line, sizeof(line), file)!=  NULL){
if (strlen(line) > 1) { // Ignorar líneas vacías
            count++;
}
  printf("Lee la linea antes de asignar memoria: %s \n", line);
}

//asignar memoria dinamica en el arreglo 
float *sales= (float*) malloc(count *sizeof(float));
if(sales == NULL){
    perror("Error al guardar espacio");
    fclose(file);
    return 1;
}
//lee los datos del arreglo nuevo 
rewind(file);
int i=0;
while(fgets(line, sizeof(line), file)!=  NULL&& i < count){
if (strlen(line) > 1) { // Ignorar líneas vacías
sales[i] = atof(line); // Convertir la línea a float y guardarla
        printf("Lee la línea: %s", line);
        printf("Valor convertido: %.2f\n", sales[i]);
        i++;

}
  printf("Lee la linea: %s \n", line);
}

//funcion para el total de ventas
float totalSale(float sales[], int n){
    float total=0.0;
    for(int i=0; i<n; i++){
        total+= sales[i];
    }
    return total;
    
}

// Función para encontrar la venta máxima
float maxSale(float sales[], int n) {
    float max = sales[0];
    for (int i = 1; i < n; i++) {
        if (sales[i] > max) {
            max = sales[i];
        }
    }
    return max;
}


// Mostrar resultados
    printf("Ventas totales: %.2f\n", totalSale(sales, count));
    printf("Venta máxima: %.2f\n", maxSale(sales, count));

    


    return 0;
}