#include <stdio.h>

int main ()
{ 	int a;

printf ("Insira sua idade: ");
scanf ("%d", &a);

if (a >= 0 && a <= 10){
	printf ("Salve bbzinho \n");
	
} else if (a >= 11 && a <= 14){
	printf ("Voce e chato pra krl \n");
	
}else if (a >= 15 && a <= 18){
	printf ("Parabens, voce ja pode ser eleitor \n");
	
}else if (a >= 19 && a <= 21){
	printf ("Hmmmmmm, PASSAVA O RATO");
	
}else if (a > 21 ){
	printf ("Bem agora ja esta na hora de sair de casa e seguir a sua vida");
}
	
	
return 0;
}

	

