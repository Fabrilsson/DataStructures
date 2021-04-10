//programa que cria um ponteiro para um conjunto de inteiros
//programa simula uma matriz por alocação dinâmica
//as dimensões da matriz são lidas
#include <stdio.h>
#include <stdlib.h>

void ler(int *p,int linhas,int colunas);
void escrever(int *p,int linhas, int colunas);
void aloca(int **p,int tam);
int *aloca2(int tam);
main(){ 
   int *pti,*m1;
   int linhas,colunas;
   printf("Digite quantidade de linhas:");
   scanf("%d",&linhas);
   printf("Digite quantidade de colunas:");
   scanf("%d",&colunas);
   //aloca(&pti,linhas*colunas);  
   pti = aloca2(linhas*colunas); 
   ler(pti,linhas,colunas);
   escrever(pti,linhas,colunas);
   m1 = aloca2(linhas*colunas); 
   ler(m1,linhas,colunas);
   escrever(m1,linhas,colunas);
   free(pti);   
   free(m1);   
   printf("\n");
   system("pause");
}

void ler(int *p,int l,int c){
int i,j;
for(i=0;i<l;i++)
 for(j=0;j<c;j++){
   printf("Digite um numero[%d,%d]: ",i+1,j+1);   
   scanf("%d",p);
   p++;
  }     
}
void escrever(int *p,int l, int c){
int i,j;
 for(i=0;i<l;i++){
   printf("\n");
   for(j=0;j<c;j++){   
     printf("%5d  ",*p);   
     p++;
    }
 }    
}

void aloca(int **p,int tam){
  *p=(int *)malloc(tam*sizeof(int));   
}

int *aloca2(int tam){
  return ((int *)malloc(tam*sizeof(int)));   
}






