//programa que cria um ponteiro para um conjunto de pontos
//programa simula um vetor por alocação dinâmica
//o tamanho do vetor é lido
typedef struct pontos{
 int x,y;
};
#include <stdio.h>
#include <stdlib.h>
main(void){  
   pontos *pti,*inicio;
   int i,tam;
   printf("Digite o tamanho do vetor:");
   scanf("%d",&tam);
   pti = (pontos *)malloc(tam*sizeof(pontos));
   inicio=pti;
   for(i=0;i<tam;i++){
     printf("Digite X[%d]: ",i+1);      /* dentro de um for ele vai ler dois valores e depois incrementar
     									o ponteiro*/
     scanf("%d",&pti->x);
     printf("Digite Y[%d]: ",i+1);   
     scanf("%d",&pti->y);     
     pti++;
   }
   pti=inicio;
   printf("\nPontos Lidos:\n");
   for(i=0;i<tam;i++){   
     printf("\nPonto[%2d]: <%3d,%3d>",i+1,pti->x,pti->y);   
     pti++;
   }
   free(inicio);
   printf("\n");
   system("pause");
}
