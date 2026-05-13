#include <stdio.h>

int firsCode()
{
    int inteiro;
    printf("intrudiza um Nº:");
    scanf("%d", &inteiro);
    printf("O Nº inteiro introduzido foi: %d\n", inteiro);
    return 0;
}
int secCode()
{
    int var1, var2, var3;
    puts("Introduza 3 Nºs:");
    scanf("%d %i %d", &var1, &var2, &var3);

    printf("O resultado de %d + %i - %d é igual a %d.\n", var1, var2, var3, var1 + var2 - var3);

    return 0;
}
void tamanho()
{

    // o caracter especial \ permite cortar de linha a string no codigo sem modificar o output
    printf("Nº de bytes de cada data type:\n\
int\t\t%zu\n\
float\t\t%zu\n\
char\t\t%zu\n\
double\t\t%zu\n",
           sizeof(int),
           sizeof(float),
           sizeof(char),
           sizeof(double));

    printf("\nNº de bytes de cada combinação modificador/datatype:\nshort int\t%hi\n\
long int\t%li\n\
long long int\t%lli\n\
long double\t%ld\n\
short\t\t%i\n\
long\t\t%d\n\
long long\t%d\n",
           sizeof(short int),
           sizeof(long int),
           sizeof(long long int),
           sizeof(long double),
           sizeof(short),
           sizeof(long),
           sizeof(long long));
}
void readImput()
{
    char ch1, ch2;
    printf("Com problema\nIntruduza o primeiro char:");
    scanf("%c", &ch1);
    printf("Intruduuza o segundo char:");
    scanf("%c", &ch2); // será sempre o enter (\n)
    printf("Os caracters recebidos foram os seguintes:[%c],[%c]\n", ch1, ch2);
    printf("sem problema\nIntruduza o primeiro char:");
    scanf("%c", &ch1);
    printf("Intruduuza o segundo char:");
    scanf(" %c", &ch2);
    printf("Os caracters recebidos foram os seguintes:[%c],[%c]\n", ch1, ch2);
}
void exerc2_9(){
    int dia,mes,ano;
    printf("Escreva o Dia:");
    scanf("%i",&dia);
    printf("Insira o Mês:");
    scanf("%i",&mes);
    printf("Insira o Ano:");
    scanf("%i",&ano);

    printf("A data formatada com dd/mm/aaaa: %i/%i/%d\n",dia,mes,ano);
}
void exerc2_10(){
    int dia,mes,ano;
    puts("Escreva a data no formato aaaa-mm-dd abaixo.");
    scanf("%i-%i-%i",&ano,&mes,&dia);
    printf("A data em outro formato fica: %i/%i/%i .\n",dia,mes,ano);
}
int main(void)
{
    // firsCode();
    // secCode();
    // tamanho();
    // readImput();
    //exerc2_10();
    return 0;
}