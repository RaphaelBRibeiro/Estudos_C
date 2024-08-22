#include <stdio.h>

main()
{ int idade, meses, dias;
printf ("informe a sua idade:");
scanf ("%d", &idade);

meses = idade * 12;

dias = meses * 30;

printf ("a sua idade me dias eh de: %d", dias);
}

