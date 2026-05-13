#include <stdio.h>
#include <ctype.h>
#include <string.h>

int strcounta(char s[])
{
    int count = 0;
    for (short i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            ++count;
        }
    }
    return count;
}

void init_str(char s[])
{
    s[0] = '\0';
}

int ult_ind_chr(char s[], char c)
{
    int i = 0;
    while (s[i] != c)
    {
        printf("inicio do while:%i\n", i);
        if (s[i] == '\0')
        {
            return -1;
        }
        i += 1;
        printf("fim do while:%i\n", i);
    }
    return i;
}

char *strlwr(char s[])
{
    for (short i = 0; s[i] != '\0'; i++)
    {
        if (isupper(s[i]))
        {
            s[i] = tolower(s[i]);
        }
        else
            continue;
    }
    return s;
}

char *strnset(char s[], char ch, int n)
{
    int len = strlen(s); // retorna o valor de caracter sem contar com a terminação.
    printf("tamanho da string:%i,valor de n: %i\n", len, n);
    if (n > len)
        n = len;
    printf("resultado da operação logica: %i\n", n);
    for (int i = 0; i < n; i++)
    {
        s[i] = ch;
    }
    // não precisa de ser adicionado nenhum caracter nulo pois nunca se chega a tucar nele.
    return s;
}
int isFile(char string[])
{
    int len = strlen(string);
    printf("tamanho da string:%i", len);

    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] == '.')
        {
            if (string[i + 1] != '\0')
                return 1;
        }

        i += 1;
    }
    return 0;
}



int main(void)
{
    // int n = 0;
    // char nome[25 + 1] = "Nome de Alguem";
    // puts(nome);
    // n = strcounta(nome);
    // printf("%i\n", n);
    // n = ult_ind_chr("ora viva!", '\0');
    // printf("%i\n", n);
    // init_str(nome);
    //  char aux[25 + 1] = "Era Uma Vez.";
    // strcpy(nome,strlwr(aux));
    // puts(nome);
    // strcpy(aux, nome);
    //   puts(aux);
    //  strcpy(nome, strnset(aux, 'K', 27));
    // puts(nome);
    // char filename[20+1] = "file name.";
    // isFile(filename) ? puts("O ficheiro tem um nome aceitavel.") : puts("O ficheiro não tem um nome aceitavel.");
    //   init_str(filename);
    //  strcpy(filename,"FicheiroBacano.txt");
    // isFile(filename) ? puts("O ficheiro tem um nome aceitavel.") : puts("O ficheiro não tem um nome aceitavel.");

    return 0;
}
