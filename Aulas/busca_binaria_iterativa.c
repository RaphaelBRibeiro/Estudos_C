#include <stdio.h>

int buscaBinaria(int vetor[],int tamanho,int valor){
	int inicio=0;
	int fim=tamanho-1;
	
	while(inicio<=fim){
		int meio=(inicio+fim)/2;
		
		if(valor==vetor[meio]){
			return meio;
		}
		
		if(vetor[meio]<valor){
			inicio=meio+1;
		}else{
			fim=meio-1;
		}
	}
	return -1;
}

int main(){
	int v[]={1,3,4,5,7,8,11,13,24,27,33,45};
	int t=sizeof(v)/sizeof(v[0]);
	printf("resultado: %d",buscaBinaria(v,t,1));
}

