#include<stdio.h>
 
int main (void)
{
    struct ficha_aluno
    {
        char nome [40];
        int numero;
        float nota;
    };

    struct ficha_aluno aluno; // Struct - tipo de dado - Variavel 

    printf ("\n -------------Cadastro de Aluno------------ \n \n \n");

    printf ("Nome do Aluno ...: ");
    fgets(aluno.nome, 40, stdin);

    printf ("Digite o numero do Aluno:");
    scanf ("%d",&aluno.numero);

    printf ("Informe a nota do Aluno: ");
    scanf ("%f",&aluno.nota);

    printf ("\n \n ---------- Lendo os Dados da Struct ---------- \n\n");
    printf ("Nome...: %s", aluno.nome);
    printf ("Nome...: %d \n", aluno.numero);
    printf ("Nome...: %.2f \n", aluno.nota);
    return (0);
}
