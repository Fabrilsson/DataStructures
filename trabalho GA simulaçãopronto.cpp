#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#define MAX 50
#include <locale.h>

typedef struct FILA1{	
	int idade;
	char nome[MAX];
	FILA1 *proximo;	
};

typedef struct FILA2{	
	int idade;
	char nome[MAX];
	FILA2 *proximo;	
};

typedef struct FILA3{	
	int idade;
	char nome[50];
	FILA3 *proximo;	
};

typedef struct NODO{
 	int idade;
 	char nome[50];
 	NODO *proximo; 
};

typedef struct LISTA{
  NODO *inicio,*fim;
  int qtd;
};

typedef struct DADOS{
	int idade;
	char nome[50];
};

//Prototipação----------------------------------------------------------

void menu (int *opcao);
void escolha (int *opcao);
LISTA* alocafila1();
LISTA* alocafila2();
LISTA* alocafila3();
void balcao1(int cont2,int *cont1,LISTA* iniciofila1,int *z,int x);
void balcao2(int cont2, int *cont3,LISTA* iniciofila2,int *j,int x);
void balcao3(int cont2,int *cont4,LISTA* iniciofila3,int *k,int x);
DADOS lerElemento();
void alocanovo1 (LISTA* iniciofila1, DADOS informa);
void mostralista (NODO* q);
void atende1 (int cont2,int cont1, LISTA* iniciofila1,int *cont5,int z,int *x);
void atende2 (int cont2,int cont3, LISTA* iniciofila2,int *cont5,int j,int *x);
void atende3 (int cont2,int cont4, LISTA* iniciofila3,int *cont5,int k,int *x);
void refresh1 (int cont1,int cont2, int a);
void refresh2 (int cont3,int cont2);
void refresh3 (int cont4,int cont2);

//Modularização---------------------------------------------------------

void menu (int *opcao){	
	system("cls");
	printf("1-Inicializa filas \n2-Simulação \n3-Registros \n4-Sair");
	printf("\n\nDigite sua a opcao: ");
	scanf("%i",opcao);	
}

void menu2 (int *opcao){
	system("cls");
	printf("1- Mostrar pessoas que foram atendidas na fila 1\n2- Mostrar pessoas que foram atendidas na fila 2\n3- Mostrar pessoas que foram atendidas na fila 3\n5- Voltar");
	printf("\n\nDigite sua opcao: ");
	scanf("%i",opcao);
}



LISTA* alocafila1(){
	
	LISTA *p;
	
	p=(LISTA *)malloc(sizeof(LISTA));
	p->inicio=NULL;
	p->fim=NULL;
	p->qtd=0;
	
	return(p);
}

LISTA* alocafila2(){
	
	LISTA *p;
	
	p=(LISTA *)malloc(sizeof(LISTA));
	p->inicio=NULL;
	p->fim=NULL;
	p->qtd=0;
	
	return(p);
}

LISTA* alocafila3(){
	
	LISTA *p;
	
	p=(LISTA *)malloc(sizeof(LISTA));
	p->inicio=NULL;
	p->fim=NULL;
	p->qtd=0;
	
	return(p);
}

void balcao1(int cont2, int *cont1,LISTA* iniciofila1,int *z,int x){
	
	int cont;
	DADOS informa;
	
	//balcao 1
	if(*cont1!=0){
	if(x>0){
	*cont1=*cont1-1;
	}
	}
	*z=0+(rand()%2);
						//randomiza o numero de pessoas que serão colocadas na fila													
	printf("\n__1\n  |\n O|");				
						
		for(cont=0;cont<*cont1;cont++){						
			printf("  O");						
		}	
	
	for(cont=0;cont<*z;cont++){		//imprime as novas pessoas da fila;
		printf("  O");
		*cont1=*cont1+1;		
	}
	
	printf("\n__|\n\n\n");
	
	
	
}

void balcao2 (int cont2, int *cont3,LISTA* iniciofila2,int *j,int x){
	
	int cont;
	DADOS informa;
	if(*cont3!=0){
		if(x>0){
			*cont3=*cont3-1;
		}
	}
	
	//balcao 2			
	*j=0+(rand()%2);	//randomiza o numero de pessoas que serão colocadas na fila				
	printf("%i",*j);
							
	printf("\n__2\n  |\n O|");				
						
		for(cont=0;cont<*cont3;cont++){						
			printf("  O");						
		}					
								
	for(cont=0;cont<*j;cont++){		//imprime as novas pessoas da fila;
		printf("  O");
		*cont3=*cont3+1;
	}
	printf("\n__|\n\n\n");	
}

void balcao3 (int cont2, int *cont4,LISTA* iniciofila3,int *k,int x){
	
	int cont;
	DADOS informa;
	
	//balcao 3
	if(*cont4>0){
		if(x>0){
			*cont4=*cont4-1;
		}
	}									
	*k=0+(rand()%2);	//randomiza o numero de pessoas que serão colocadas na fila				
	printf("%i",*k);
						
	printf("\n__3\n  |\n O|");				
					
		for(cont=0;cont<*cont4;cont++){  //imprime as pessoas que ja estavam na fila						
			printf("  O");						
		}					
						
	for(cont=0;cont<*k;cont++){		//imprime as novas pessoas da fila;
		printf("  O");
		*cont4=*cont4+1;
	}
	printf("\n__|\n\n\n");	
}

DADOS lerElemento(){
	int x,cont;
	DADOS info;
	char nome[MAX];
	FILE *arquivo;
	if((arquivo=fopen("nomes.txt","r"))==NULL){
		system("cls");
		printf("Erro na abertura do arquivo dos nomes");
	}
	x=1+(rand()%20);
	for(cont=0;cont<x;cont++){
	fgets(info.nome,MAX,arquivo);
	}	
	fclose(arquivo);
	if((arquivo=fopen("idades.txt","r"))==NULL){
		system("cls");
		printf("Erro na abertura do arquivo das idades");
	}
	x=1+(rand()%20);
	for(cont=0;cont<x;cont++){
	fscanf(arquivo,"%i",&info.idade);
	}	
	fclose(arquivo);
	
	return(info);
}

void alocanovo1 (LISTA* iniciofila1, DADOS informa){
	NODO *n,*p,*q;
	n=(NODO *)malloc(sizeof(NODO));
	n->idade=informa.idade;
	strcpy(n->nome,informa.nome);
	n->proximo=NULL;
	if(iniciofila1->inicio!=NULL){
		p=iniciofila1->fim;
		p->proximo=n;
		iniciofila1->fim=n;
		iniciofila1->qtd=iniciofila1->qtd+1;
	}
	else{
		iniciofila1->inicio=n;
		iniciofila1->fim=n;
		iniciofila1->qtd=1;
	}
}

void mostralista (LISTA* iniciofilaN){
	NODO* o;
	int cont=0;
	o=iniciofilaN->inicio;
	printf("Tinham %i pessoas na fila\n\n",iniciofilaN->qtd);
	while(o!=NULL){
		printf("\n\n");
		printf("Nome da pessoa: %s\n",o->nome);
		printf("Idade da pessoa: %i\n\n",o->idade);
		o=o->proximo;
	}
}

void atende1 (int cont2,int cont1, LISTA* iniciofila1,int *cont5,int z,int *x){
	DADOS informa;
	NODO *p;
	int cont,cont3;
	*x=0+(rand()%2);
	
	system("cls");
	if(*x>0){
	if(cont1>0){
	printf("Qual é o seu nome e idade ?");
	printf("\n__1\n  |/\n O|");				
						
		for(cont=0;cont<cont1;cont++){						
			printf("  O");											
		}
		informa=lerElemento();            //aloca apenas quando a pessoa for atendida pelo balconista
		alocanovo1(iniciofila1,informa);

		p=iniciofila1->inicio;
		for(cont=0;cont<*cont5;cont++){		
		p=p->proximo;
		}
		printf("\n__|  Meu nome é %s e tenho %i anos\n\n\n",p->nome,p->idade);	
		*cont5=*cont5+1;	
	
	 
}
else{
	printf("\n__1\n  |\n O|");
	for(cont=0;cont<cont1;cont++){						
			printf("  O");											
		}
	printf("\n__|\n\n\n");

}
}
else{
	printf("\n__1\n  |\n O|");
	for(cont=0;cont<cont1;cont++){						
			printf("  O");											
		}
	printf("\n__|\n\n\n");

}

}


void atende2 (int cont2,int cont3, LISTA* iniciofila2,int *cont5,int j,int *x){
	DADOS informa;
	NODO *p;
	
	
	
	int cont,cont1;
	*x=0+(rand()%2);
	if(*x>0){
	if(cont3>0){
	printf("Qual é o seu nome e idade ?");
	printf("\n__2\n  |/\n O|");				
	if(cont2!=0){					
		for(cont=0;cont<cont3;cont++){						
			printf("  O");											
		}
		informa=lerElemento();            //aloca apenas quando a pessoa for atendida pelo balconista
		alocanovo1(iniciofila2,informa);

		p=iniciofila2->inicio;
		for(cont=0;cont<*cont5;cont++){		
		p=p->proximo;
		}
		printf("\n__|  Meu nome é %s e tenho %i anos\n\n\n",p->nome,p->idade);	
		*cont5=*cont5+1;
	}
	 
	}
	else{
	printf("\n__2\n  |\n O|");
	for(cont=0;cont<cont3;cont++){						
			printf("  O");											
		}
	printf("\n__|\n\n\n");
	
}
}
	else{
	printf("\n__2\n  |\n O|");
	for(cont=0;cont<cont3;cont++){						
			printf("  O");											
		}
	printf("\n__|\n\n\n");
}

}

void atende3 (int cont2,int cont4, LISTA* iniciofila3,int *cont5,int k,int *x){
	DADOS informa;
	NODO *p;
	
	int cont,cont3;
	*x=0+(rand()%2);
	if(*x>0){
	if(cont4>0){
	printf("Qual é o seu nome e idade ?");
	printf("\n__3\n  |/\n O|");				
	if(cont2!=0){					
		for(cont=0;cont<cont4;cont++){						
			printf("  O");											
		}
		informa=lerElemento();    		       	//aloca apenas quando a pessoa for atendida pelo balconista
		alocanovo1(iniciofila3,informa);		   
		p=iniciofila3->inicio;
		for(cont=0;cont<*cont5;cont++){		
		p=p->proximo;
		}
		printf("\n__|  Meu nome é %s e tenho %i anos\n\n\n",p->nome,p->idade);	
		*cont5=*cont5+1;
	}
		
	}
	else{
		printf("\n__3\n  |\n O|");
		for(cont=0;cont<cont3;cont++){						
				printf("  O");											
		}
			printf("\n__|\n\n\n");
	}
}
else{
	printf("\n__3\n  |\n O|");
	for(cont=0;cont<cont4;cont++){						
			printf("  O");											
		}
	printf("\n__|\n\n\n");
}

}

void refresh1 (int cont1,int cont2,int a){
	int cont,cont3;
	system("cls");
	 printf("\n__1\n  |\n O|");	
	 if(a>0){
	 cont3=cont1-1;			
	 }
	 else{
	 	cont3=cont1;
	 }
		for(cont=0;cont<cont3;cont++){						
			printf("  O");					
		}							
	
	printf("\n__|\n\n\n");
}

void refresh2 (int cont3,int cont2,int b){
	int cont1,cont;
	 printf("\n__2\n  |\n O|");	
	 if(b>0){
	 cont1=cont3-1;			
	 }
	 else{
	 	cont1=cont3;
	 }
		for(cont=0;cont<cont1;cont++){						
			printf("  O");					
		}							
	
	printf("\n__|\n\n\n");
}

void refresh3 (int cont4,int cont2,int c){
	int cont3,cont;
	 printf("\n__3\n  |\n O|");	
	 if(c>0){
	 cont3=cont4-1;
	 }
	 else{
	 	cont3=cont4;
	 }
	 			
						
		for(cont=0;cont<cont3;cont++){						
			printf("  O");					
		}							
	
	printf("\n__|\n\n\n");
}

void fim (LISTA* iniciofila1,LISTA* iniciofila2,LISTA* iniciofila3,int cont1,int cont3,int cont4){
	int cont2,cont;
	system("cls");
	 printf("\n__1\n  |\n O|");	
	 								
		for(cont=0;cont<cont1;cont++){						
			printf("  O");					
		}							
	
	printf("\n__|\n\n\n");
	
	printf("                                                                    O\n");
	printf("                                                                   /");
	printf("                                                             Isso é um assalto");		
	printf("\n__2\n  |\n O|");
	 								
		for(cont=0;cont<cont3;cont++){						
			printf("  O");					
		}						
	
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                                                    O");
	
	printf("\n__3\n  |\n O|");			
						
		for(cont=0;cont<cont4;cont++){						
			printf("  O");					
		}							
	
	printf("\n__|\n\n\n");
	
	sleep(4);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	 								
		for(cont=0;cont<cont1;cont++){						
			printf("  O");					
		}							
	
	printf("\n__|\n\n\n");
	
	printf("                                                                    O\n");
	printf("                                                                   /");
	printf("                                              Fiquem só os caixas e o resto saia");	
	printf("\n__2\n  |\n O|");
	 								
		for(cont=0;cont<cont3;cont++){						
			printf("  O");					
		}
									
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                                                    O");
	
	printf("\n__3\n  |\n O|");			
						
		for(cont=0;cont<cont4;cont++){						
			printf("  O");					
		}							
	
	printf("\n__|\n\n\n");
	
	sleep(4);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                                                    O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                                                    O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(4);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                                                    O\n");
	printf("                                                                   /");
	printf("\n__2\n  |\n O|");
	 									
		printf("                                            Muito bem, vamos ver ...");							
	
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                                                    O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(3);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                                                 O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                                                 O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                                              O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                                              O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                                           O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                                           O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                                        O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                                        O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                                     O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                                     O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                                  O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                                  O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                               O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                               O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                            O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                            O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                         O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                         O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                      O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                      O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                   O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                   O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                                O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                                O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                             O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                             O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
		system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                          O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                          O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                       O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                       O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                    O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                    O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("                 O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("                 O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("              O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("              O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(1);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("           O\n");

	printf("\n__2\n  |\n O|");
	 															
	printf("\n__|\n\n\n");
	printf("                                                                   \n");
	printf("           O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	
	sleep(2);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("           O\n");
	printf("Por favor, não nos machuquem ;-;");
	printf("\n__2\n  |/\n O|");															
	printf("\n__|   Não facam nada para que eu precise fazê-lo, e eu não farei\n\n\n");
	printf("          \\\n");
	printf("           O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(5);
	
	system("cls");
	 printf("\n__1\n  |\n O|");	
	printf("\n__|\n\n\n");
	
	printf("           O\n");
	printf("\n__2\n  |\n O|");															
	printf("\n__|   Mas desliguem o sistema de câmeras\n\n\n");
	printf("          \\\n");
	printf("           O");
	
	printf("\n__3\n  |\n O|");			
	
	printf("\n__|\n\n\n");
	
	sleep(5);
	
	system("cls");
	
	printf("Sistema de cameras desligado pelo gerente ...\n\n");
	
	sleep(3);
}

main (void){
	
	int *opcao,cont5=0,cont6=0,cont7=0,z,j,k;
	setlocale(LC_ALL,"portuguese");
	opcao=(int *)malloc(sizeof(int));
		
	LISTA *iniciofila1;
	LISTA *iniciofila2;
	LISTA *iniciofila3;
	LISTA *q,*p,*r;
	
	iniciofila1=NULL;
	iniciofila2=NULL;
	iniciofila3=NULL;
	
	while(*opcao!=4){
			menu(opcao);

	switch(*opcao){
		
		case (1):{
			system("cls");
			printf("Opção 1 selecionada, inicializando as filas\n\n");
			sleep(3);
			iniciofila1=alocafila1();
			iniciofila2=alocafila2();
			iniciofila3=alocafila3();
			break;
		}
		
		case (2): {
			
			q=NULL;
			p=NULL;
			r=NULL;
			
			if(iniciofila1==NULL){	
				system("cls");
				printf("Você não iniciou as filas!\n\n");
				system("pause");
				system("cls");
				break;									
			}
			
			if(iniciofila2==NULL){
				system("cls");
				printf("Você não iniciou as filas!\n\n");
				system("pause");
				system("cls");
				break;
			}
			
			if(iniciofila3==NULL){
				system("cls");
				printf("Você não iniciou as filas!\n\n");
				system("pause");
				system("cls");
				break;
			}
			
			srand(time(NULL));
			system("cls");
			
			int x,y,z,a=0,b=0,c=0,cont,cont1=0,cont2=0,cont3=0,cont4=0;
		
			printf("\n__1\n  |\n O|\n__|\n\n\n");
			printf("\n__2\n  |\n O|\n__|\n\n\n");
			printf("\n__3\n  |\n O|\n__|\n\n");
			
			sleep(1);
			
			x=20+(rand()%30);            	//randomiza o numero de vezes que ele fará o processo, até certo ponto que as filas serão zeradas;
			
			for(cont=0;cont<5;cont++){
				
				system("cls");	
	
				balcao1(cont2,&cont1,iniciofila1,&z,a);
			
				balcao2(cont2,&cont3,iniciofila2,&j,b);
				
				balcao3(cont2,&cont4,iniciofila3,&k,c);
								
				cont2=cont2+1;
				
				y=2+(rand()%3);
				sleep(y);
				
				atende1(cont2,cont1,iniciofila1,&cont5,z,&a);
				atende2(cont2,cont3,iniciofila2,&cont6,j,&b);
				atende3(cont2,cont4,iniciofila3,&cont7,k,&c);
				
				y=3+(rand()%5);
				sleep(y);
					
			}
			q=iniciofila1;
			p=iniciofila2;
			r=iniciofila3;
			
			fim(iniciofila1,iniciofila2,iniciofila3,cont1,cont3,cont4);
			system("pause");
			
			printf("\n\nFinal da simulação\n\n");
			system("pause");
			
			break;
		}
		
		case(3):{
			
			opcao=(int *)malloc(sizeof(int));
			
			*opcao=10;
			
			if(iniciofila1==NULL){	
				system("cls");
				printf("Você não iniciou as filas!\n\n");
				system("pause");
				system("cls");
				break;									
			}
			
			if(iniciofila2==NULL){
				system("cls");
				printf("Você não iniciou as filas!\n\n");
				system("pause");
				system("cls");
				break;
			}
			
			if(iniciofila3==NULL){
				system("cls");
				printf("Você não iniciou as filas!\n\n");
				system("pause");
				system("cls");
				break;
			}
								
			while (*opcao!=5){				
				menu2(opcao);
				switch(*opcao){
					case (1):{
						system("cls");
						printf("\nOpção 1 selacionada, mostrando a fila 1\n\n");
						mostralista(q);
						system("pause");
						break;
					}
					case(2):{
						system("cls");
						printf("\nOpção 2 selacionada, mostrando a fila 2\n\n");
						mostralista(p);
						system("pause");
						break;
					
					}
					case(3):{
						system("cls");
						printf("\nOpção 3 selacionada, mostrando pessoas que foram atendidas\n\n");
						mostralista(r);
						system("pause");
						break;
						
					}
					case(5):{
						printf("\nOpção 5 selecionada, voltando ...");
						sleep(3);
						break;
					}
				}		
			}
			
			break;
		}
		
		case (4):{
			
			system("cls");
			printf("\n\nObrigado por usar o programa, espero que tenha se divertido!\n\nNão foi facil fazer!!!");
			
			break;
		}
	}
}
}


