#include <stdio.h>

int main(void)
{
    // esta função não dá \n no final
    printf("Hello World!");
    // usando o \n
    printf("Hello World\n");

    /* produzir  o output:
    C
    is the best
    Language
    */
    printf("C\n");
    printf("is the best\n");
    printf("Language\n");

    // ou

    printf("C\nis the best\nLanguage\n");

    // uso dos caracteres especiais
    printf("Beep!\a\n");
    printf("Beep!\7\n");

    // fazer uma arvore simples
    printf("  *  \n");
    printf(" *** \n");
    printf("*****\n");
    printf(" /|\\\n");

    // exercicio de usar o tab e o %
    printf("\n");
    printf("Total\t=\t100%%\nIVA\t=\t23%%\nIRS\t=\t11%%\n");
    printf("--------------------\n");
    printf("Lig.\t=\t66%%\n");

    printf("Hello World!");
    printf("\n");
    puts("Hello World!"); // esta dá no final um \n
    return 0;
}
