#include <stdio.h>


void tabuadaDo5()
{
    puts("Tabuada do 5.");
    int i = 1;
    while (i <= 10)
    {
        printf("5 x %i  = %i\n", i, 5 * i);
        i += 1;
    }
}

void doWhile()
{
    // programa que peça um numero que esteja entre 1 e 10, se estiver fora repete
    int n;
    do
    {
        puts("Insira um nuemro entre 1 e 10");
        scanf("%i", &n);

    } while (n < 1 || n > 10);
}
void menu()
{
    char menuText[] = {""};
    short choice = -1;
    do
    {
        puts("Menu:\n1\tCliente\n2\tFurnecedor\n3\tEncomendas\n0\tSair\n");
        printf("Insira um numero:");
        scanf("%*i", &choice); // deixa um espaçoantes do inteira para não dar problemas.
        putchar('\n');
    } while (choice);
}
void ciclosEncadeados()
{
    for (int linha = 1; linha <= 3; linha++)
    {
        int valorAtual = 1;
        while (valorAtual <= linha)
        {
            printf("%i ", valorAtual);
            valorAtual++;
        }
        putchar('\n');
    }

    for (int i = 0; i < 3; i++)
    {
        putchar('.');
    }
    putchar('\n');

    for (int i = 1; i <= 10; i++)
        printf("%i ", i);
    putchar('\n');
}

void umAteDez()
{
    for (short linha = 1; linha <= 10; linha++)
    {
        for (short i = 1; i <= linha; i++)
        {
            printf("%hi ", i);
        }
        putchar('\n');
    }
}

void wirdIncrment()
{
    int var = 4;
    printf("%d\n", var++ + ++var); // usa o valor incrementado mesmo para o var++.
    
    // este não vai dar
    int i1 = 0;
    if (i1++) 
        printf("%d i++\n", i1);

    // Este já vai dar
    int i2 = 0;
    if (++i2)
        printf("%d ++i\n", i2);
}
int main()
{
    // tabuadaDo5();
    // doWhile();
    // menu();
    // ciclosEncadeados();
    // umAteDez();
    wirdIncrment();
    return 0;
}
