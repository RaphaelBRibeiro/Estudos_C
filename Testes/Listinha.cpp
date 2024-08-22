#include <stdio.h>

int main()
{
int a;
int b; 
int maior; 
int menor;
int x;

printf ("Escreva o primeiro valor: ");
scanf ("%d", &a);
	maior = a;

printf ("Escreva o segundo valor: ");
scanf ("%d", &b);
	menor = b;

if (a < b){
	maior = b;
	menor = a;	
}
x = maior - menor;
printf ("O resultado da diferenca entre %d e %d igual a: %d", a, b, x );
		
}
