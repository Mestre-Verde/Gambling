
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "pedra_papel_tesoura.h"
#include "jogador.h"
#include "aux_func.h"
#include "Engine.h"
#include "aux_string.h"

typedef enum
{

    PEDRA = 0,
    PAPEL = 1,
    TESOURA = 2,

}PedraPapelTesouraOption;



int main_process_pedra_papel_tesoura(const unsigned long int currentPoints, unsigned long int *points)
{
    const int MAXBUFFER_LEN = 67 + 1;
    char resposta[MAXBUFFER_LEN] = {0};

    int result_random = rand() % 3;

    int estado = readStrUserInput("PEDRA PAPEL TESOURA", MAXBUFFER_LEN, resposta, 0, "");

    switch (estado)
    {
    case 0:

        break;

    case 1:

        return 1;

    case 2:

        break;

    case -1:

        break;

    default:

    return 1;
        
    }

    printString("Escolhe Pedra, Papel ou Tesoura");

    // Condições

    if (result_random == estado)
    {
        puts("Empate");
    }    

    if (result_random == PEDRA && estado == PAPEL )
    {
        puts("Ganhaste");
    }

    if (result_random == PAPEL && estado == PEDRA)
    {
        puts("Perdeste");
    }

    if (result_random == TESOURA && estado == PEDRA)
    {
        puts("Ganhaste");
    }

    if (result_random == PEDRA && estado == TESOURA)
    {
        puts("");
    }
}