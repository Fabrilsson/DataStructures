#include <stdio.h>
#include <stdlib.h>

//PROTOTIPAÇÃO----------------------------------------



//MODULARIZAÇÃO---------------------------------------

void alocacao (float **var,int num){
	
	*var=(float *)malloc(num*sizeof(float));
	
}

void leitura (float *var,int num){
	
	int i;
	
	for (i=0;i<num;i++){
		
		printf("Digite o valor da posicao %i: ",i+1);
		scanf("%f",var);
		var++;
		
	}
		
	
}

void maiorvalor(float *var,int num,float *maior){
	
	int i;
	float maior2,menor;
	
	maior2=*var;
	menor=*var;
	
	for(i=0;i<num;i++){
		
		if(*var>maior2){
			
			maior2=*var;
			printf("\n%f",maior2);
		}
		
		var++;
		
	}
	
}

main (void){
	
	float *var, maior;
	int num;
	
	printf("Digite o numero de alocacoes que voce deseja: ");
	scanf("%i",&num);
	
	alocacao(&var,num);
	
	leitura(var,num);
	
	maiorvalor(var,num,&maior);
}
