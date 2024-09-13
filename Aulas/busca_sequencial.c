#include <stdio.h>

int buscaSequencial(int vetor[],int tamanho,int valor){
	int i;
	for(i=0;i<tamanho;i++){
		if(valor==vetor[i]){
			return i;
		}
	}
	return -1;
}

int main(){
	int v[]={11,2,4,5,7,66,54,34,23};
	int t=sizeof(v)/sizeof(v[0]);
	printf("Chave = %d",buscaSequencial(v,t,660));
	
}
