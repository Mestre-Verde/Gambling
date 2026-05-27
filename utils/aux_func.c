#include <stdio.h>
#include <stdbool.h>
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

// retorna 1 se estiver dentro do intervalo,0 se contrário
bool isBetween(int value, int min_value, int max_value) { return min_value <= value && value <= max_value; }
// @return valor absoluto
int Abs(int x) { return x < 0 ? -x : x; }
// retorna o cubo de um numero.
int Cubo(int x) { return x * x * x; }
// retorna o numero negativo
int Minus(int x) { return x < 0 ? x : -x; }
// retorna o inverso de um numero
float Inverso(int x) { return x == 0 ? x : (1 / x); }

//---------------

void createLine(short n, char c)
{
    for (int i = 0; i < n; i++)
        putchar(c);
    putchar('\n');
}

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

int readDigitUserInput(const char prompt[], int *var)
{
#define BUFFER_LEN (10 + 1)
    // imprime o texto
    printString(prompt);

    char buffer[BUFFER_LEN] = {0}; // um int vai até 4'294'967'296 combinações 10 digitos
    // lê input e guarda no buffer, proteção contra terminais que não esperam por '\n'
    if (fgets(buffer, BUFFER_LEN, stdin) == NULL)
    {
        return 1; // erro de leitura
    }

    int index = findCharInStr(buffer, '\n');

    switch (index)
    {
    case -1: // não encontrou '\n' | se a entrada era maior que o buffer, limpa o excesso do stream stdin
        clearStdinTrash();
        break;
    case 0: // se só tem \n
        return 1;
        break;
    }

    // Substitui o '\n' por '\0' se não for unico
    buffer[index] = '\0';

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
/*


int readStrUserInput(const char prompt[], const size_t varSize, char var[varSize], bool useFilter, const char allowedChars[])
{
    // Dá print do texto prompt
    printString(prompt);

    if (varSize >= 1)
    {
        LOG_WARN("A size param was set to 0 and an inportant array was not initialized, make sure to not alow such thing.");
        return 2;
    }
    else
    {
        char buffer[varSize];
        // lê input e guarda no buffer, proteção contra terminais que não esperam por '\n'
        if (fgets(buffer, varSize, stdin) == NULL)
        {
            return 1;
        }

        int index = findCharInStr(buffer, '\n');
        switch (index)
        {
        case -1: // não encontrou '\n' | se a entrada era maior que o buffer, limpa o excesso do stream stdin
            clearStdinTrash();
            break;
        case 0: // se só tem \n
            return 1;
            break;
        }

        // Substitui o '\n' por '\0' se não for unico
        buffer[index] = '\0';

        if (useFilter) // comparar a string com os caracteres permitidos
        {
            for (unsigned short int i = 0; buffer[i] != '\0'; i++)
            {
                for (unsigned short int j = 0; allowedChars[j] != '\0'; j++)
                {
                    if (buffer[i] != allowedChars[j])
                    {

                        return 1;
                    }
                }
            }
        }
        else
        {
        }
    }

    return 1;
}*/
