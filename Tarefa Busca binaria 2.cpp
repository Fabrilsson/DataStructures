#include <stdio.h>
#include <stdlib.h>

//PROTOTIPAÇÃO---------------------------------------------



//MODULARIZAÇÃO--------------------------------------------

void leitura (int vet[20]){
	
	int cont;
	
	for (cont=0;cont<20;cont++){
		
		printf("Digite o numero da posição %i: ",cont+1);
		scanf("%i",&vet[cont]);
		
	}
	
}

void ordenacao (int vet[20]){
	
	int cont,cont2,aux;
	
	for (cont=0;cont<19;cont++){
		
		for (cont2=0;cont2<19-cont;cont2++){
			
			if (vet[cont2]>vet[cont2+1]){
				
				aux=vet[cont2];
				vet[cont2]=vet[cont2+1];
				vet[cont2+1]=aux;
				
			}
			else{
			}
			
		}
		
	}
	
}

main (void){
	
	int vet[20],cont;
	
	leitura(vet);
	ordenacao(vet);
	
	for(cont=0;cont<20;cont++){
		
		printf("%i   ",vet[cont]);
		
	}
	
}
