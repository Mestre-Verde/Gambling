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