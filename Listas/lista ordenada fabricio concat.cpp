//programa que gerencia uma lista em memoria 
//permite gravação e leitura da lista de um arquivo
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#define max 50
typedef char TEXTO[max];

typedef struct DADOS{
 int codigo;
 TEXTO nome; 
};

typedef struct LISTA{
 int codigo;
 TEXTO nome;
 LISTA *proximo; 
};

FILE *criaArquivo();
FILE *abreArquivo();
void fecha(FILE *arq);
void grava(FILE *arq, LISTA *elemento);
void ler(FILE *arq, LISTA *elemento);
LISTA *cria();
void alocaOrdenado(LISTA **elemento, DADOS info);
void mostralista(LISTA *elemento);
DADOS lerElemento();
char menu();
void aloca(LISTA *elemento,DADOS info);

main(){
   
   LISTA *inicio,*inicio2;
   FILE *arquivo;
   DADOS informa,informa2;
   char conf;
   char op='Z';
   inicio=NULL;
   inicio2=NULL;
   while(op!='F'){
     op=menu();
     switch (op){
     case 'I': printf("\nI - inicializa lista 1\n");
               inicio = cria();//aloca o início da lista  
               system("pause");                       
               break;
               
     case 'C': printf("\nC - inicializa lista 2\n");
     
     			inicio2=cria();
     			system("pause");
     			break;
     
     case 'N': printf("\nN - novo elemento lista 1\n");
               if(inicio==NULL){
                 printf("\nLista nao inicializada\n");
                 system("pause");
                 }
               else{
                   informa=lerElemento(); 
                   alocaOrdenado(&inicio,informa);
               } 
               break;
     
	 case 'D': printf("\nD - novo elemento na lista 2\n");	 			
	 			if(inicio2==NULL){
	 				printf("\nLista nao inicializada\n");
	 				system("pause");	 				
				 }
				 else{
				 	
				 	informa2=lerElemento();
				 	alocaOrdenado(&inicio2,informa2);
				 	
				 }
	 
     
     case 'M':      
               printf("\nM - mostra lista 1\n");
               if (inicio == NULL)
                  printf("\n Lista Vazia \n ");
               else
                  mostralista(inicio); 
               system("pause");
               break;
               
     case 'O': printf("\nO - mostra lista 2\n");
     
     			if(inicio2==NULL)
     			printf("\nLista nao inicializada");
     			else
     			mostralista(inicio2);
     			system("pause");
     			
     case 'T': printf("\nT - concatena as duas listas");
     
     			if(inicio==0 or inicio2==0)
     			printf("\nAlguma das listas nao foi inicializada");
     			else{
     				
     				concatena(inicio,inicio2);
     				
				 }
     
     case 'G': printf("\nG - grava arquivo\n"); 
               //gravando dados da lista no arquivo 
               if(inicio==NULL){
                 printf("\nLista nao inicializada\n");
                 system("pause");
                 }
               else{                
               printf("\n Gravando dados no arquivo\n");   
               arquivo=criaArquivo();
               grava(arquivo,inicio);
               fecha(arquivo);
               printf("\n Dados gravados....\n");
               system("pause");  
               }
               break;
     case 'L': printf("\nL - ler arquivo\n");
               //lendo dados do arquivo para lista nova
               printf("\n Lendo dados do arquivo\n");   
               arquivo=abreArquivo();
               if (inicio != NULL){
                 printf("\nExistem dados na lista em memoria");
                 printf("\nDeseja substituir pelo arquivo(S/N)?");
                 do{
                 conf=toupper(getche());
                 }while((conf!='S')&&(conf!='N'));
               }
               else
                 conf='S';
               if (conf=='S'){
                   inicio = cria();
                   ler(arquivo,inicio);  
                   mostralista(inicio);
                   printf("\n Dados lidos....\n"); 
               }
               else
                   printf("\n Arquivo nao lido....\n");
               fecha(arquivo);
               system("pause");                             
               break;
                 
     case 'F': free(inicio);
               printf("\nfinalizando sistema\n");
               break;            
                         
     default: printf("\n opcao invalida \n");
              system("pause");             
     }            
   }
   printf("\n");
   system("pause");
}

char menu(){
 system("cls");
 printf("\nI - inicializa lista 1");
 printf("\nC - inicializa lista 2");
 printf("\nN - novo elemento lista 1");
 printf("\nO - novo elemento lista 2");
 printf("\nM - mostra lista 1");
 printf("\nO - mostra lista 2"); 
 printf("\nG - grava arquivo"); 
 printf("\nL - ler arquivo"); 
 printf("\nF - fim");
 printf("\nDigite opcao: "); 
 fflush(stdin);
 return(toupper(getche()));    
}

//função que abre o arquivo para leitura
FILE *abreArquivo(){
 FILE *arq;
 arq=fopen("dados.bin","rb");
 if (arq == NULL)
   printf("\nArquivo nao existe!\n");
 else
   printf("\nArquivo aberto com sucesso\n"); 
 return(arq);    
}

////função que cria(recria) o arquivo para gravação
FILE *criaArquivo(){
 FILE *arq;
 arq=fopen("dados.bin","wb");
 if (arq == NULL)
   printf("\nErro ao criar arquivo!\n");
 return(arq);    
}

//função que fecha o arquivo
void fecha(FILE *arq){
   fclose(arq);  
}

//função que grava lista no arquivo
void grava(FILE *arq, LISTA *elementos){
    LISTA *p;
    DADOS registro;
    p=elementos;
    while(p!=NULL){
      registro.codigo=p->codigo;
      strcpy(registro.nome,p->nome);
      fwrite(&registro,sizeof(DADOS),1,arq); 
      printf("\ngravando: %d - %s",registro.codigo,registro.nome);
      p=p->proximo;          
    }
}

//função que le arquivo e coloca dados na lista
void ler(FILE *arq, LISTA *elementos){
    DADOS registro;
    rewind(arq);//garante que o cursor de leitura está no inicio do arquivo
    while(!feof(arq)){
      if (fread(&registro,sizeof(DADOS),1,arq)==1)                          
         aloca(elementos,registro);  
    }     
}

//função que cria a lista
LISTA *cria(){
    LISTA *p;
    p=(LISTA *)malloc(sizeof(LISTA)); 
    p->codigo=0;
    strcpy(p->nome,"inicio");
    p->proximo=NULL;
    return(p);
}

void aloca(LISTA *elemento, DADOS info){
    LISTA *p,*n;//n é o ponteiro para alocar o novo elemento
    p=elemento;//p é o ponteiro para navegação na lista
    if (strcmp(p->nome,"inicio")==0){//para guardar o primeiro elemento da lista no nodo já criado 
        p->codigo=info.codigo;
        strcpy(p->nome,info.nome);
        p->proximo=NULL;
    }
    else{//para alocar os outros nodos da lista
        n=(LISTA *)malloc(sizeof(LISTA));
        n->codigo=info.codigo;
        strcpy(n->nome,info.nome);
        n->proximo=NULL;//o novo elemento não aponta para ninguem, por isso atribui-se NULL     
        while(p->proximo!=NULL)
             p=p->proximo;//navegação na lista, p recebe o ponteiro do próximo 
        if (p->proximo==NULL)
             p->proximo=n;  
    }     
}

//aloca novo elemento na lista
void alocaOrdenado(LISTA **inicio, DADOS informa){
    LISTA *p,*n,*q;//n é o ponteiro para alocar o novo elemento
    p=*inicio;//p é o ponteiro para navegação na lista
    int inclui;
    if (strcmp(p->nome,"inicio")==0){//para guardar o primeiro elemento da lista no nodo já criado 
        p->codigo=informa.codigo;
        strcpy(p->nome,informa.nome);
        p->proximo=NULL;
    }
    else{//para alocar os outros nodos da lista
        n=(LISTA *)malloc(sizeof(LISTA));
        n->codigo=informa.codigo;
        strcpy(n->nome,informa.nome);
        n->proximo=NULL;//o novo elemento não aponta para ninguem, por isso atribui-se NULL     
        
        if(strcmp(informa.nome,p->nome)<0){
        	
        	n->proximo=p;
        	*inicio=n;
        	
		}
		else{
			inclui=0;
			
			q=p->proximo;
			while((q!=NULL)and(inclui==0)){
				
				if(strcmp(informa.nome,q->nome)<0){
					
					n->proximo=p->proximo;
					p->proximo=n;
					inclui=1;
					
				}
				else{
					
					p=q;
					q=p->proximo;
					
				}
				}
				if(strcmp(informa.nome,p->nome)>0){
					
					p->proximo=n;
					
				}
				
			}
			
			
		}
    }     

void concatena (LISTA *inicio, LISTA *inicio2){
	
	LISTA *p,*p2;
	
	p=inicio;
	p2=inicio2;
	
	while(p!=NULL){
		
		if(p->proximo==NULL){
			
			p->proximo=p2;
			
		}
		
		p=p->proximo;
		
	}
	
	
	
}

//aloca novo elemento na lista
void mostralista(LISTA *elemento){
    LISTA *p;
    int conta=0;
    p=elemento;//p é o ponteiro para navegação na lista
    while(p!=NULL){
       conta++;
       printf("Dados [%d]\n",conta);
       printf("Codigo %d \n",p->codigo);
       printf("Nome %s \n",p->nome);
       p=p->proximo;//navegação na lista, p recebe o ponteiro do próximo
    }     
}

DADOS lerElemento(){
   DADOS info;
   printf("\nDigite o codigo: ");
   scanf("%d",&info.codigo);
   printf("\nDigite o nome: ");
   fflush(stdin);
   gets(info.nome);
   return(info);    
}

