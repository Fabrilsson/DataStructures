//programa que cria um ponteiro para um conjunto de inteiros
//programa simula um vetor por aloca��o din�mica
//o tamanho do vetor � lido
#include <stdio.h>
#include <stdlib.h>
main(){   
   float *ptf,*inicio;
   int i,tam;
   printf("Digite o tamanho do vetor (quantidade de elementos):");
   scanf("%d",&tam);
   ptf = (float *)malloc(tam*sizeof(float));
   inicio=ptf;
   for(i=0;i<tam;i++){
     printf("Digite um numero[%d]: ",i+1);   
     scanf("%f",ptf);
     ptf++;
   }
   ptf=inicio;
   for(i=0;i<tam;i++){   
     printf("\nNumero[%2d]: %7.2f",i+1,*ptf);   
     ptf++;
   }
   free(inicio);
   printf("\n");
   system("pause");
}
