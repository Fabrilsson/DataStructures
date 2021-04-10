//programa que cria um ponteiro para um conjunto de inteiros
//programa simula um vetor por alocação dinâmica

#include <stdio.h>
#include <stdlib.h>
main(){
   
   int *pti,*inicio;
   int i;
   int tam;
   printf("Digite o tamanho do vetor:");
   scanf("%d",&tam);
   pti = (int *)malloc(tam*sizeof(int));
   inicio=pti;					/* vai igualar o primeiro endereço ao "inicio", para que depois o pti possa
   								voltar a começar no mesmo lugar depois de ser mudado*/
   for(i=0;i<tam;i++){
     printf("Digite um numero[%d]: ",i+1);   
     scanf("%d",pti);
     pti++;                    /*incrementa o ponteiro, desloca n bytes de acordo com o tipo do ponteiro*/
     							
   }
   pti=inicio;					/*retorna o primeiro endereço ao pti*/
   for(i=0;i<tam;i++){   
     printf("\nNumero[%2d]: %2d",i+1,*pti);   
     pti++;
   }
   free(pti);
   printf("\n");
}
