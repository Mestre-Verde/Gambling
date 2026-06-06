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

    // player.pontos_guess = 0;
    return player;
}

/**
 * @brief Imprime os valores de um Player
 * @param player struct Player a imprimir.
 */
void showPlayerInfo(Player player)
{
    createLine(50, '+');
    printf("Nome do jogador:%s\n", player.nome);
    printf("Pontos no jogo da Adivinha: %lu\n", player.pontos_guess);
}

int choosePlayer(void)
{
    listPlayersInDataBase(1);
    return 1;
}

int buildPlayer(void)
{
    // pede nome
    char nome[MAX_NAME_LENGTH] = {0};
    if (readStrUserInput("Insira o nome do jogador", MAX_NAME_LENGTH, nome, 0, ""))
    {
        LOG_INFO("Não foi possivel criar o jogador.Nome não aceite.");
        return 0;
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