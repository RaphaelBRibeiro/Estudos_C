#include <stdio.h>
#include <stdlib.h>

struct Node{
	int idade;
	struct Node *prox;
};
typedef struct Node node;


int menu(void);
void iniciaLista(node *PILHA);
void opcaoMenu(node *PILHA,int op);
node *criaNo();
void removerElemento(node* PILHA);
void push(node* PILHA);
void pop(node* PILHA);
void imprimeLista(node* PILHA);
void libera(node* PILHA);
int vazia(node *PILHA);


int main(){
	node *PILHA = (node *)malloc(sizeof(node));
	iniciaLista(PILHA);
	
	int opcao;
	
	do{
		opcao=menu();
		opcaoMenu(PILHA,opcao);
	}while(opcao);
	
}

void pop(node* PILHA){
	
	node *ant=PILHA;
	node *suc=PILHA->prox;
	
	while(suc->prox!=NULL){
		ant=suc;
		suc=suc->prox;
	}
	ant->prox=NULL;
	free(suc);
}

void push(node* PILHA){
	node *novo=(node *)malloc(sizeof(node));
	printf("Idade por favor: ");
	scanf("%d",&novo->idade);
	novo->prox=NULL;
	
	if(vazia(PILHA)){
		PILHA->prox=novo;
	}else{
		node *temp=PILHA->prox;
		while(temp->prox!=NULL){
			temp=temp->prox;
		}
		temp->prox=novo;
	}
	
}

void imprimeLista(node* PILHA){
	node *temp;
	temp=PILHA->prox;
	while(temp!=NULL){
		printf("%d\n",temp->idade);
		temp=temp->prox;
	}
}

void opcaoMenu(node *PILHA,int op){
	switch(op){
		case 0:
			free(PILHA);
			break;
		case 1:
			system("cls");
			imprimeLista(PILHA);
			break;
		case 2:
			system("cls");
			push(PILHA);
			break;
		case 3:
			system("cls");
			pop(PILHA);
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
	printf("1 - Imprimir a pilha\n");
	printf("2 - Push\n");
	printf("3 - Pop\n");
	printf("Opcao: ");
	scanf("%d",&opcao);
	return opcao;	
}

void insereInicio(node* PILHA){
	node *novo=(node *)malloc(sizeof(node));
	printf("Idade por favor: ");
	scanf("%d",&novo->idade);
	
	node *temp=PILHA->prox;
	PILHA->prox=novo;
	novo->prox=temp;
}

int vazia(node* PILHA){
	if(PILHA->prox==NULL){
		return 1;
	}else{
		return 0;
	}
}

void iniciaLista(node *PILHA){
	PILHA->prox=NULL;
}


