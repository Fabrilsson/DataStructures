#include <stdio.h>
#include <stdlib.h>

//PROTOTIPAÇÃO----------------------------------------



//MODULARIZAÇÃO-------------------------------------

int fatorial (int num){
	
	if (num==0){
		
		return (1);
		
	}
	else{
		
		return (num*fatorial(num-1));
		
	}
	
}

main (void){
	
	int num,num2;
	
	printf("Digite um valor inteiro: ");
	scanf("%i",&num);
	
	num2=fatorial(num);
	
	printf("Fatorial: %i",num2);
	
	
}
