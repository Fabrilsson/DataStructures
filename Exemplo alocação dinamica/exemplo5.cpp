//programa que cria um ponteiro para uma estrutura
typedef struct pontos{
 int x,y;
};
#include <stdio.h>
#include <stdlib.h>
main(){   
   pontos *pti;
   pti = (pontos *)malloc(sizeof(pontos));

     printf("Digite X: ");   
     scanf("%d",&pti->x);
     printf("Digite Y:");   
     scanf("%d",&pti->y);     
  
     printf("\nPonto: %d - %d",pti->x,pti->y);   

   free(pti);
   printf("\n");
   system("pause");
}
