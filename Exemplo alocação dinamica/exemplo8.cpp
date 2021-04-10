//programa que cria um ponteiro para um conjunto de inteiros
//programa simula um vetor por alocação dinâmica

#include <stdio.h>
#include <stdlib.h>
main(){
   
   int *pti,*inicio;
   int i;
   int tam=5;
   pti = (int *)calloc(10,sizeof(int));
   inicio=pti;
   for(i=0;i<10;i++){
     printf("Digite um numero[%d]: ",i+1);   
     scanf("%d",pti);
     pti++;
   }
   pti=inicio;
   for(i=0;i<10;i++){   
     printf("\nNumero[%2d]: %2d",i+1,*pti);   
     pti++;
   }
   free(pti);
   printf("\n");
   system("pause");
}
