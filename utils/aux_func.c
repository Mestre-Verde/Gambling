#include <stdio.h>
#include "aux_func.h"

int isDigit(int ch) { return '0' <= ch && ch <= '9'; }
int isAlpha(int ch) { return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'); }
int isAlnum(int ch) { return ('0' <= ch && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'); }
int isLower(int ch) { return (ch >= 'a' && ch <= 'z'); }
int isUpper(int ch) { return (ch >= 'A' && ch <= 'Z'); }
int isSpace(int ch) { return ch == 32; }
int isVowell(char ch) { return (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U'); }

int toLower(int ch)
{
    if (isUpper(ch))
        return ch + 32;
    return ch;
}

int toUpper(int ch)
{
    if (isLower(ch))
        return ch - 32;
    return ch;
}

//---------------

void clearStdinTrash(void)
{
    // LOG_INFO("Detetado caracteres a mais em stdin. A limpar...");
    for (int c = 0; c != '\n' && c != EOF;)
    {
        c = getchar();
        // printf("%i ", (int)c);
    }
    // putchar('\n');
}

void printHex(int strLen, char str[strLen])
{
    for (int i = 0; i < strLen; i++)
    {
        printf("%02X ", (unsigned char)str[i]);
    }
    printf("\n");
}

/**
 * @brief Imprime uma string caractere a caractere até '\0'.
 *
 * Diferente de puts(), não adiciona automaticamente '\n'.
 * Evita overhead de formatação do printf().
 *
 * @param str String a imprimir
 */
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

int readDigitUserInput(const char str[], int *var)
{
    // Variaveis para uso da função
    char buffer[10 + 1] = {0}; // un int vai até 4'294'967'296 combinações 10 digitos

    // imprime o texto
    printString(str);

    // lê input e guarda no buffer
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        return 1; // erro de leitura
    }
    // se a entrada era maior que o buffer, limpa o excesso do stream stdin
    if (findCharInStr(buffer, '\n') == -1)
    {
        clearStdinTrash();
    }
    // Substitui o '\n' por '\0' se existir
    int index = findCharInStr(buffer, '\n');
    if (index != -1)
    {
        buffer[index] = '\0';
    }

    // valida se todos os caracteres são dígitos
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        if (!isDigit(buffer[i]))
            return 1; // input inválido
    }
    // converte manualmente
    /*
    | i | buffer | cálculo   | value |
    | - | ---- | --------- | ----- |
    | 0 | '1'  | 0*10 + 1  | 1     |
    | 1 | '2'  | 1*10 + 2  | 12    |
    | 2 | '3'  | 12*10 + 3 | 123   |
    */
    int value = 0;
    for (int i = 0; buffer[i] != '\0'; i++)
    {
        value = value * 10 + (buffer[i] - '0');
    }

    *var = value;

    return 0;
}

void createLine(short n, char c)
{
    for (int i = 0; i < n; i++)
        putchar(c);
    putchar('\n');
}

//---------------

// retorna 1 se estiver dentro do intervalo,0 se contrário
_Bool isBetween(int value, int min_value, int max_value) { return min_value <= value && value <= max_value; }
// @return valor absoluto
int Abs(int x) { return x < 0 ? -x : x; }
// retorna o cubo de um numero.
int Cubo(int x) { return x * x * x; }
// retorna o numero negativo
int Minus(int x) { return x < 0 ? x : -x; }
// retorna o inverso de um numero
float Inverso(int x) { return x == 0 ? x : (1 / x); }