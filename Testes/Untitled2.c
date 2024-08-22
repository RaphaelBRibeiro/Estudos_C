#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i=5 ,soma, j;
	
	while (i<=5)
	{
		soma = 0;
		j=1;
		while (j<=1)
		{
			soma+=j;
			j++;
		}
		i++;
	}	
	printf ("soma = %d\n", soma);
	system ("PAUSE");
	return 0;
}
