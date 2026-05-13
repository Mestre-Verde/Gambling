#include <stdio.h>
#include <ctype.h>
#include <string.h>

// esta merda demorou a porra de uma tarde identeria sem a AI a judar fogo... BIXOOOOO huuuu fufado!! funciona caralhoooo.

#define MAX_LEN 100 + 1

// 10 nomes com 30 letras maximas
char nomeCompleto[MAX_LEN] = {'\0'};
const char sair[] = "SAIR";
char apelido[15 + 1] = "";

char *strupper(char s[])
{
    // printf("String à entrada:");
    // puts(s);
    for (short i = 0; s[i] != '\0'; i++)
    {
        if (islower(s[i]))
        {
            s[i] = toupper(s[i]);
        }
    }
    // printf("String à saida:");
    // puts(s);
    return s;
}

// colcoa os nomes no formato "Nome"
void fixName(char str[MAX_LEN]) // Cai\0
{
    char toUp = 1;
    char hadLetter = 0;
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        char now = str[i];
        char next = str[i + 1];

        // putchar(str[i]);
        //  verifica se é caracter e não escreve nada.
        if (isdigit(now) && isalpha(next) && !hadLetter)
        {
            toUp = 1;
            continue;
        }

        // é um espaço e a seguir é uma letra?
        if (isspace(now) && isalpha(next))
        {
            if (hadLetter) // tinha uma letra antes?
            {
                nomeCompleto[j] = ' ';
                j++;
            }

            toUp = 1;
            continue;
        }
        // é uma letra?
        if (isalpha(now))
        {
            if (toUp) // é para elevar?
            {
                nomeCompleto[j] = toupper(str[i]);
                toUp = 0;
            }
            else
            {
                nomeCompleto[j] = tolower(str[i]);
            }
            j++;
            hadLetter = 1;
        }
    }
    // nomeCompleto[j] = 'E';
    nomeCompleto[j] = '\0';
}

int obtemApelido(char str[])
{
    // obterm o index do inicio do apelido
    int lastSpaceIndex = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            lastSpaceIndex = i;
            // printf("encontrado espaço nº: %i\n", lastSpaceIndex);
        }
    }

   // printf("O ultimo espaço foi encontrado na posição:%i\n", lastSpaceIndex);
    // verifica se encontrou um espaço
    if (lastSpaceIndex == 0)
    {
        return 0;
    }
    // com o index do inicio do apelido em mãos vamos copiar para o apelido e depois remover do nome completo
    int i = 0;
    while (str[i + (lastSpaceIndex + 1)] != '\0')
    {
        apelido[i] = str[i + lastSpaceIndex + 1];
        i++;
    }
    apelido[i] = '\0';
    str[lastSpaceIndex] = '\0';

    return 1;
}

int main(void)
{
    while (1)
    {
        // get user input
        char input[MAX_LEN] = "";
        printf("Escreva um nome completo:");

        fgets(input, MAX_LEN, stdin);

        // debugg
        //printf("Entrada Recebida:");
        // puts(input);

        // verifica se é para sair.
        if (strncmp(strupper(input), sair, 4) == 0)
            return 1;

        // manda o a input para formatar.
        fixName(input);
        //printf("resultado de formatação:");
        //puts(nomeCompleto);

        // manda separar o apelido do nome completo

        if (!obtemApelido(nomeCompleto))
        {
            puts(nomeCompleto); // se não tem apelido passa para o proximo nome.
            continue;
        }

        strcat(apelido, " , ");
        strcat(apelido, nomeCompleto);
        puts(apelido);

        nomeCompleto[0] = '\0';
        apelido[0] = '\0';
    }
    return 0;
}
