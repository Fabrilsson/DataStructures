//programa que cria um ponteiro para um conjunto de inteiros
//programa simula um vetor por alocação dinâmica
//o tamanho do vetor é lido

#include <stdio.h>
#include <stdlib.h>
main(){
   
   int *pti,*inicio;
   int i,tam;
   printf("Digite o tamanho do vetor (quantidade de elementos):");
   scanf("%d",&tam);
   pti = (int *)malloc(tam*sizeof(int));
   inicio=pti;
   for(i=0;i<tam;i++){
     printf("Digite um numero[%d]: ",i+1);   
     scanf("%d",pti);
     pti++;
   }
   pti=inicio;
   for(i=0;i<tam;i++){   
     printf("\nNumero[%2d]: %3d",i+1,*pti);   
     pti++;
   }
   free(pti);
   printf("\n");
   system("pause");
}
