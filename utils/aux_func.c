#include <stdio.h>
#include <stdbool.h>

bool isBetween(int value, int min_value, int max_value) { return min_value <= value && value <= max_value; }

void createLine(short n, char c)
{
    for (int i = 0; i < n; i++)
        putchar(c);
    putchar('\n');
}

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

// @return valor absoluto
int Abs(int x) { return x < 0 ? -x : x; }
// retorna o cubo de um numero.
int Cubo(int x) { return x * x * x; }
// retorna o numero negativo
int Minus(int x) { return x < 0 ? x : -x; }
// retorna o inverso de um numero
int Inverso(int x) { return x == 0 ? x : (1 / x); }