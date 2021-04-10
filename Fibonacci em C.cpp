#include <stdio.h>
#include <stdlib.h>

//PROTOTIPAÇÃO----------------------------------------



//MODULARIZAÇÃO-------------------------------------

int fibonacci (int num){
	
	if (num==1)
		
		return (1);
		
		if(num==2)
			
			return (1);
			
			
		return (fibonacci(num-1)+fibonacci(num-2));
		
	
	
}

main (void){
	
	int num,num2;
	
	printf("Digite um valor inteiro: ");
	scanf("%i",&num);
	
	num2=fibonacci(num);
	
	printf("Fatorial: %i",num2);
	
	
}
