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
    Player player = {0};

    stringCopy(nome, player.nome);
    // LOG_DEBUG("Nome do novo jogador:%s", player.nome);

    player.id = *id;
    // LOG_DEBUG("Id do novo jogador:%i", player.id);

    player.pontos_guess = 0;
    return player;
}

void showPlayerInfo(Player player, bool withLine)
{
    if (withLine)
    {
        createLine(50, '+');
    }
    printf("Nome do jogador:%s\n", player.nome);
    printf("Pontos no jogo da Adivinha: %lu\n", player.pontos_guess);
}

int choosePlayer(void)
{
    // Lista os jogadores com index
    int estado = listPlayersInDataBase(1, PLAYERDB_DIR);
    if (estado == -1)
    {
        return 0;
    }
    else if (estado)
    {
        return 1;
    }
    putchar('\n');
    createLine(50, '+');

    // obtem a input do user
    int id = 0;
    int estadoInput = -1;
    do
    {
        estadoInput = readDigitUserInput("Insira o numero do jogador a escolher('0' para abortar):", &id);
        if (estadoInput == 1)
        {
            return 1;
        }
    } while (estadoInput);

    // verifica se o id é invalido
    if (!id)
    {
        return 0;
    }

    // verifica se o jogador existe
    Player player = {0};
    int foundState = findPlayerInDB(id, &player);
    if (foundState == -1)
    {
        LOG_INFO("Jogador não encontrado.");
    }
    else if (!foundState)
    {
        currentPlayer = player;
        printString("\nJogador atual:\n");
        showPlayerInfo(currentPlayer, 0);
    }
    else
    {
        return 1;
    }
    return 0;
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
    int estadoInput = -1;
    do
    {
        estadoInput = readDigitUserInput("Insira o id do jogador a remover('0' para abortar):", &playerId);
        if (estadoInput == 1)
        {
            return 1;
        }
    } while (estadoInput);

    if (!playerId)
    {
        return 0;
    }
    if (playerId == currentPlayer.id)
    {
        LOG_INFO("\7Não pode apagar o jogador atual!");
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
