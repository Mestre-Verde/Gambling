#include <stdio.h>
# include "struct.h"

typedef struct
{
    unsigned int id;
    char nome[25 + 1];
    unsigned short int nota;
} Aluno;

void exercicio1()
{

    Aluno aluno1 = {
        .id = 12345,
        .nome = "Carlos",
        .nota = 20};

    printf("O aluno %s, com id %i tem a nota %hi.\n", aluno1.nome, aluno1.id, aluno1.nota);
}

void exercicio2()
{
}
int main(void)
{
    exercicio1();
    return 0;
}
