#include <stdio.h>
#include <math.h>
int main ()
{
int a,b,c;
float delta, x1, x2;

printf ("Informe o valor de A: ");
scanf ("%d", &a);

printf ("Informe o valor de B: ");
scanf ("%d", &b);

printf ("Informe o valor de C: ");
scanf ("%d", &c);

delta = pow (b,2) - 4 * a * c;

printf ("O valor de Delta eh: %2.2f \n", delta);

if (delta < 0 ){
	printf ("x1 nao possiu raiz ");
	printf ("\n");
	printf ("x2 nao possiu raiz ");
}
else if (delta == 0){
	x1 = (-b + sqrt (delta)) / (2 * a);
	x2 = (-b - sqrt (delta)) / (2 * a);
	printf ("Os valores de x1 e x2 sao: %2.2f %2.2f ",x1, x2);
}
else if (delta > 0){
	x1 = (-b + sqrt (delta)) / (2 * a);
	x2 = (-b - sqrt (delta)) / (2 * a);
	printf ("Os valores de x1 e x2 sao: %2.2f %2.2f ",x1, x2);
}

return 0;
}
 
 

