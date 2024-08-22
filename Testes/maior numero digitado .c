#include <stdio.h>

int main ()
{ 	int a;
	int b;
	int c; 
	int d;
	int e;
	int x;
	
	printf ("Informe o valor 1:\n ");
	scanf ("%d", &a);
	x = a; 
	
	printf ("Informe o valor 2:\n ");
	scanf ("%d", &b);
	if (b > x ){
		x = b;
	}
	
	printf ("Informe o valor 3:\n ");
	scanf ("%d", &c);
	if (c > x ){
		x = c;
	}
	
	printf ("Informe o valor 4:\n ");
	scanf ("%d", &d);
	if (d > x ){
		x = d;
	}
	
	printf ("Informe o valor 5:\n ");
	scanf ("%d", &e);
	if (e > x ){
		x = e;
	}
		


	printf ("O maior numero digitado foi: %d ", x);
	
	
return 0;
}

	

