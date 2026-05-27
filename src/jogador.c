#include <stdio.h>
#include "aux_func.h"
#include "jogador.h"

// constutor
Player createPlayer(const char nome[MAX_NAME_LENGTH], int *id)
{
    Player player = {0};
    for (short int i = 0; i < MAX_NAME_LENGTH; i++)
    {
        player.nome[i] = nome[i];
    }
    player.id = *id;

    return player;
}
void showPlayerInfo(Player p)
{
    printf("Nome do jogador:%s", p.nome);
    printf("Nº de vitórias no jogo do Galo: %u\n", p.vitórias_galo);
    printf("Nº de derrotas no jogo do Galo: %u\n", p.derrotas_galo);
    printf("Pontos no jogo da Adivinha: %lu\n", p.pontos_guess);
}

void playerStats(Player p)
{
    puts("===== Estatísticas =====");
    showPlayerInfo(p);
    createLine(50, '+');
    // outras estatisticas.
}

int choosePlayer(void) { return 1; }

int buildPlayer(void)
{
    // pede nome
    // char nome[MAX_NAME_LENGTH] = {0};

    // verifica os ids e atribui
    // int id = getNextAvaiableID();

    // Player p = createPlayer(&nome, &id);

    return 0;
}

int removePlayer(void) { return 1; }