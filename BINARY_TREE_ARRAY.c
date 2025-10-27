/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define MAX 10

int main()
{
char tree[MAX]={'G','D','I','B','F','H','J','A','C','E'};
int numElements= 10;

printf("Representacion del arreglo: \n");
for(int i=0; i<numElements; i++){
    printf("tree[%d] = %c\n", i, tree[i]);
}

    return 0;
}