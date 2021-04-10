//programa que cria um ponteiro para um conjunto de inteiros
//programa simula uma matriz por alocação dinâmica
//as dimensões da matriz são lidas
#include <stdio.h>
#include <stdlib.h>
main(){ 
   int *pti,*inicio;
   int i,j,linhas,colunas;
   printf("Digite quantidade de linhas:");
   scanf("%d",&linhas);
   printf("Digite quantidade de colunas:");
   scanf("%d",&colunas);   
   pti = (int *)malloc(linhas*colunas*sizeof(int));
   inicio=pti;
   for(i=0;i<linhas;i++)
    for(j=0;j<colunas;j++){
     printf("Digite um numero[%d,%d]: ",i+1,j+1);   
     scanf("%d",pti);
     pti++;
   }
   pti=inicio;
   for(i=0;i<linhas;i++){
    printf("\n");
    for(j=0;j<colunas;j++){   
     printf("%5d  ",*pti);   
     pti++;
   }
   }
   free(inicio);
   printf("\n");
   system("pause");
}
