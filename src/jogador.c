#include <stdio.h>
#include <stdbool.h>

#include "aux_func.h"
#include "aux_string.h"

#include "jogador.h"
#include "FileManager.h"

// constutor
Player createPlayer(const char nome[MAX_NAME_LENGTH], unsigned short int *id)
{
    // inicializa tudo a 0
    Player player;

    stringCopy(nome, player.nome);
    // LOG_DEBUG("Nome do novo jogador:%s", player.nome);

    player.id = *id;
    // LOG_DEBUG("Id do novo jogador:%i", player.id);

    player.pontos_guess = 0;
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
    listPlayersInDataBase(1, PLAYERDB_DIR);
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
    if (getNextPlayerId(&id, PLAYERDB_DIR))
    {
        LOG_ERROR("Houve um problema ao obter o próximo ID do jogador.");
        return 1;
    }

    Player player = createPlayer(nome, &id);
    // LOG_DEBUG("Size of Player is %zu\n", sizeof(Player));
    savePlayerInDataBase(player, PLAYERDB_DIR);

    return 0;
}

// TODO :quando implementar corrent player, naõ deixar que ele se apague.
int removePlayer(void)
{
    int stateOfThePlayerList = listPlayersInDataBase(true, PLAYERDB_DIR);
    // Lista os jogadores existentes
    if (stateOfThePlayerList == 1)
    {
        LOG_WARN("Não foi possível listar jogadores.");
        return 1;
    }
    else if (stateOfThePlayerList == -1)
    {
        return 0;
    }

    // pergunta qual jogador quer remover com base em id, será 1 por vez para simpificar
    int playerId = 0;
    if (readDigitUserInput("Insira o id do jogador a remover('0' para abortar):", &playerId))
    {
        return 1;
    }

    if (!playerId)
    {
        return 0;
    }

    // com o id começa o processo de remoção do jogador, isto se existir
    // chama a função de remoção em FileManager.
    int estado = removePlayerFromDB(playerId, PLAYERDB_DIR);

    switch (estado)
    {
    case -1:
        LOG_INFO("Jogador não encontrado.");
        break;

    case 0:
        LOG_INFO("Jogador removido com sucesso.");
        break;

    case 1:
        return 1;
    }

    return 0;
}