/*
 * aux_func.c
 * Funções utilitárias diversas usadas por menus e jogos.
 * Responsabilidades:
 * - Operadores sobre caracteres e checks (isDigit, isAlpha...)
 * - Conversões (toLower, toUpper)
 * - Funções auxiliares de I/O (readDigitUserInput, readStrUserInput)
 * - Utilitários de depuração/visualização (createLine, ShowCursorPosition)
 * Uso: incluído por módulos que precisam de utilitários comuns.
 */

#include <stdio.h>
#include <stdbool.h>
#include "aux_func.h"
#include "aux_string.h"

int isDigit(int ch) { return '0' <= ch && ch <= '9'; }
int isLower(int ch) { return (ch >= 'a' && ch <= 'z'); }

int isUpper(int ch) { return (ch >= 'A' && ch <= 'Z'); }
int isSpace(int ch) { return ch == 32; }

int toLower(int ch)
{
    return isUpper(ch) ? ch + 32 : ch;
}

int toUpper(int ch)
{
    return isLower(ch) ? ch - 32 : ch;
}

//---------------

// retorna 1 se estiver dentro do intervalo,0 se contrário
bool isBetween(int value, int min_value, int max_value) { return min_value <= value && value <= max_value; }
// retorna o numero negativo
int Minus(int x) { return x > 0 ? -x : x; }

//---------------

void createLine(short n, char c)
{
    for (int i = 0; i < n; i++)
        putchar(c);
    putchar('\n');
}

void clearStdinTrash(void)
{
    LOG_DEBUG("Detetado caracteres a mais em stdin. A limpar...");
    for (int c = 0; c != '\n' && c != EOF;)
    {
        c = getchar();
        // printf("%i ", (int)c);
    }
    // putchar('\n');
}

void ShowCursorPosition(FILE *file)
{
    printf("Cursor: %ld\n", ftell(file));
}

void delay(unsigned short seg)
{
    for (unsigned long long i = 0; i < (((unsigned long long)seg) * 1000000000); i++)
        ;
}
/*
void printCharTable(void)
{
    printf("Char   | Dec | Hex\n");
    printf("-------------------\n");

    for (int i = 0; i < 128; i++)
    {
        switch (i)
        {
        case '\0':
            printf("\\0     | %3d | %02X\n", i, i);
            break;
        case '\a':
            printf("\\a     | %3d | %02X\n", i, i);
            break;
        case '\b':
            printf("\\b     | %3d | %02X\n", i, i);
            break;
        case '\t':
            printf("\\t     | %3d | %02X\n", i, i);
            break;
        case '\n':
            printf("\\n     | %3d | %02X\n", i, i);
            break;
        case '\v':
            printf("\\v     | %3d | %02X\n", i, i);
            break;
        case '\f':
            printf("\\f     | %3d | %02X\n", i, i);
            break;
        case '\r':
            printf("\\r     | %3d | %02X\n", i, i);
            break;

        default:
            if (i >= 32 && i <= 126)
                printf("'%c'    | %3d | %02X\n", i, i, i);
            else
                printf("CTRL   | %3d | %02X\n", i, i);
        }
    }
}
*/
int readDigitUserInput(const char prompt[], int *var)
{
    const int BUFFER_LEN = (10 + 1);
    // imprime o texto
    printString(prompt);

    char buffer[BUFFER_LEN]; // buffer suficiente para int com sinal e '\0'
    // lê input e guarda no buffer, proteção contra terminais que não esperam por '\n'
    if (fgets(buffer, BUFFER_LEN, stdin) == NULL)
    {
        LOG_ERROR("Problema ao copiar do stdin!");
        return 1;
    }

    int LFindex = findCharInStr(buffer, '\n');

    switch (LFindex)
    {
    case -1: // não encontrou '\n'
        clearStdinTrash();
        break;

    case 0: // só tem '\n'
        return -1;

    default:
        // Substitui o '\n' por '\0'
        buffer[LFindex] = '\0';
        break;
    }

    // verificar se é negativo, o sinal para ser valido presisa de estar em buffer[0]
    bool isNegative = buffer[0] == '-';

    // verifica se só existe um '-'
    if (isNegative && LFindex == 1)
    {
        return -1;
    }

    // valida se todos os caracteres são dígitos
    for (int i = isNegative ? 1 : 0; buffer[i] != '\0'; i++)
    {
        if (!isDigit(buffer[i]))
            return -1; // input inválido
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
    for (int i = isNegative ? 1 : 0; buffer[i] != '\0'; i++)
    {
        value = value * 10 + (buffer[i] - '0');
    }

    *var = isNegative ? Minus(value) : value;

    return 0;
}

int readStrUserInput(const char prompt[], const size_t varSize, char var[varSize], bool useFilter, const char allowedChars[])
{
    // Dá print do texto prompt
    printString(prompt);
    if (useFilter)
    {
        printf("[%s]", allowedChars);
    }
    putchar(':');

    // reduz limpessas desnecessárias ao stdin
    if (varSize < 3)
    {
        LOG_WARN("The vazSize must be bigger than 2 in order to have '1 char + \\n + \\0'");
        return 1;
    }

    char buffer[varSize];
    // lê input e guarda no buffer, proteção contra terminais que não esperam por '\n'
    if (fgets(buffer, varSize, stdin) == NULL)
    {
        return 1;
    }

    LOG_DEBUG("Entrada recebida:");
    printHex(varSize, buffer);

    //  obtem a posição do enter
    int index = findCharInStr(buffer, '\n');
    // LOG_DEBUG("Obtido o index de '\\n': %i", index);

    switch (index)
    {
    case -1: // não encontrou '\n' -> A entrada era maior que o buffer, limpa o excesso do stream stdin
        clearStdinTrash();
        break;
    case 0: // se só tem \n
        return -1;
    default:
        // Substitui o '\n' por '\0' se não for único
        buffer[index] = '\0';
        break;
    }

    if (useFilter) // comparar a string com os caracteres permitidos
    {
        // caracter a caracter da string
        for (unsigned short int i = 0; buffer[i] != '\0'; i++)
        {
            bool isValid = false;
            // caracter a caracter do whitelist
            for (unsigned short int j = 0; allowedChars[j] != '\0'; j++)
            {
                if (buffer[i] == allowedChars[j])
                {
                    isValid = true;
                    break;
                }
            }
            if (!isValid)
            {
                return 2;
            }
        }
        stringCopy(buffer, var);
    }
    else
    {
        stringCopy(buffer, var);
    }
    return 0;
}