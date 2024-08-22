#include <stdio.h>

int main ()
{
int n1,n2,maior,menor,result;

printf ("Informe um valor: ");
scanf ("%d", &n1);

printf ("informe outro numero ");
scanf ("%d", &n2);

if (n1 > n2){
	maior = n1;
	menor = n2;
}
else{
	maior = n2;
	menor = n1;
}
result = maior + menor;
printf ("\n A soma de %d com %d eh igual a: %d",maior,menor,result);
}
