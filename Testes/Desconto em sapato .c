#include <stdio.h>
#include <math.h>
int main ()
{
float N1;
float N2;
float N3;
float N4;
float final;

printf ("Informe o valor da NOTA 1: ");
scanf ("%f", &N1);

printf ("Informe o valor da NOTA 2: ");
scanf ("%f", &N2); 

printf ("Informe o valor da NOTA 3: "); 
scanf ("%f", &N3);

printf ("Informe o valor da NOTA 4: "); 
scanf ("%f", &N4);

final = (N1 + N2 + N3 + N4) /4;

if (final >= 5)
	printf ("APORVADO \n");
else
	printf ("REPROVADO \n");

printf ("%2.2f", final);
return 0;
}
 
