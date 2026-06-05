#include <stdio.h>
#include "aux_func.h"
#include "aux_string.h"
#include "jogador.h"
#include "FileManager.h"

// constutor
Player createPlayer(const char nome[MAX_NAME_LENGTH], unsigned short int *id)
{
    // inicializa tudo a 0
    Player player = {0};

    stringCopy(nome, player.nome);
    // LOG_DEBUG("Nome do novo jogador:%s", player.nome);

    player.id = *id;
    // LOG_DEBUG("Id do novo jogador:%i", player.id);

    // player.vitorias_galo = 0;
    // player.derrotas_galo = 0;
    // player.pontos_guess = 0;
    return player;
}

void showPlayerInfo(Player p)
{
    printf("Nome do jogador:%s", p.nome);
    printf("Nº de vitórias no jogo do Galo: %u\n", p.vitorias_galo);
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
    char nome[MAX_NAME_LENGTH] = {0};
    if (readStrUserInput("Insira o nome do jogador", MAX_NAME_LENGTH, nome, 0, "") == 1)
    {
        LOG_INFO("Não foi possivel criar o jogador.Nome não aceite.");
        return 1;
    }

    // verifica os ids e atribui
    unsigned short int id = 0;
    if (getNextPlayerId(&id))
    {
        LOG_ERROR("Houve um problema ao obter o próximo ID do jogador.");
        return 1;
    }

    Player player = createPlayer(nome, &id);
    // LOG_DEBUG("Size of Player is %zu\n", sizeof(Player));
    savePlayerInDataBase(player);

    return 0;
}

int removePlayer(void) { return 1; }