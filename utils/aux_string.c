/*
 * aux_string.c
 * Funções utilitárias simples para manipulação de strings em C.
 * Responsabilidades:
 * - Cópia de strings (`stringCopy`)
 * - Impressão de strings (`printString`)
 * - Pesquisa de caracteres (`findCharInStr`)
 * - Impressão em hexadecimal (`printHex`)
 * - Cálculo de comprimento (`stringLen`)
 * Utilização típica: auxilia funções de input/output e validação nos menus e jogos.
 */

#include <stdio.h>

void stringCopy(const char inicial[], char final[])
{
    int i = 0;
    while (inicial[i])
    {
        final[i] = inicial[i];
        // printf("Caracter copiado:%c|%i\n",inicial[i],(int)inicial[i]);
        i++;
    }
    final[i] = '\0';
}

void printString(const char str[])
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        putchar(str[i]);
    }
}

int findCharInStr(char str[], char c)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == c)
        {
            return i;
        }
    }
    return -1;
}

void printHex(int strLen, char str[strLen])
{
    for (int i = 0; i < strLen; i++)
    {
        printf("%02X ", (unsigned char)str[i]);
    }
    printf("\n");
}

int stringLen(const char s[])
{
    int i = 0;
    while (s[i]){i++;}
    return i += 1;
}