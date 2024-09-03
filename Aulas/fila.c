#include <stdio.h>
#include <stdlib.h>

struct Node{
	int idade;
	struct Node *prox;
};
typedef struct Node node;


int menu(void);
void iniciaLista(node *FILA);
void opcaoMenu(node *FILA,int op);
node *criaNo();
void remover(node* FILA);
void inserir(node* FILA);
void imprimir(node* FILA);
void libera(node* FILA);
int vazia(node *FILA);


int main(){
	node *FILA = (node *)malloc(sizeof(node));
	iniciaLista(FILA);
	
	int opcao;
	
	do{
		opcao=menu();
		opcaoMenu(FILA,opcao);
	}while(opcao);
	
}

void remover(node* FILA){
	
	node *ant=FILA;
	node *suc=FILA->prox;
	
	while(suc->prox!=NULL){
		ant=suc;
		suc=suc->prox;
	}
	ant->prox=NULL;
	free(suc);
}


void imprimir(node* FILA){
	node *temp;
	temp=FILA->prox;
	while(temp!=NULL){
		printf("%d\n",temp->idade);
		temp=temp->prox;
	}
}

void opcaoMenu(node *FILA,int op){
	switch(op){
		case 0:
			free(FILA);
			break;
		case 1:
			system("cls");
			inserir(FILA);
			break;
		case 2:
			system("cls");
			imprimir(FILA);
			break;
		case 3:
			system("cls");
			remover(FILA);
			break;
		default:
			system("cls");
			printf("Olhe o menu direito!!!\n\n");
			break;
	}	
}

int menu(){
	int opcao=0;
	printf("Escolha uma das opcoes abaixo:\n");
	printf("0 - Sair\n");
	printf("1 - Inserir\n");
	printf("2 - Imprimir a fila\n");
	printf("3 - Remover\n");
	printf("Opcao: ");
	scanf("%d",&opcao);
	return opcao;	
}

void inserir(node* FILA){
	node *novo=(node *)malloc(sizeof(node));
	printf("Idade por favor: ");
	scanf("%d",&novo->idade);
	
	node *temp=FILA->prox;
	FILA->prox=novo;
	novo->prox=temp;
}

int vazia(node* FILA){
	if(FILA->prox==NULL){
		return 1;
	}else{
		return 0;
	}
}

void iniciaLista(node *FILA){
	FILA->prox=NULL;
}


