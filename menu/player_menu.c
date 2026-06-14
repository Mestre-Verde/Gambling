#include <stdio.h>

#include "aux_func.h"

#include "player_menu.h"
#include "jogador.h"

PlayerMenuOption getPlayerMenuChoice(void)
{
    // variaveis
    const char menuText[] =
        "\n===== MENU JOGADOR =====\n\
1 - Criar jogador\n\
2 - Selecionar jogador\n\
3 - Remover jogador\n\
4 - Mostrar status do jogador atual\n\
0 - Voltar";
    int choice = PLAYER_MENU_UNKNOWN;

    // imprimir textMenu e obter a resposta do user.
    puts(menuText);
    if (readDigitUserInput("Escolha :", &choice))
    {
        return PLAYER_MENU_UNKNOWN;
    }

    switch (choice)
    {
    case PLAYER_MENU_EXIT:
    case CREATE_PLAYER:
    case CHOOSE_PLAYER:
    case REMOVE_PLAYER:
    case PLAYER_STATS:
        return (PlayerMenuOption)choice;
        break;

    default:
        return PLAYER_MENU_UNKNOWN;
        break;
    }
}

int playerMenu(void)
{
    while (1)
    {
        int option = getPlayerMenuChoice();

        switch (option)
        {
        case PLAYER_MENU_UNKNOWN:
            puts("Opção inválida.");
            break;

        case CREATE_PLAYER:
            if (buildPlayer())
            {
                LOG_ERROR("O processo de criar um jogador foi abortado.");
            }
            else
            {
                LOG_INFO("Jogador criado com sucesso!");
            }
            break;

        case CHOOSE_PLAYER:
            if (choosePlayer())
            {
                LOG_ERROR("O processo de seleção do jogador falhou.");
            }
            else
            {
                LOG_INFO("Processo de seleção terminado com sucesso.");
            }
            break;

        case REMOVE_PLAYER:
            if (removePlayer())
            {
                LOG_ERROR("O processo de remoção de jogador falhou.");
            }
            else
            {
                LOG_INFO("Processo de remoção completada com sucesso.");
            }
            break;

        case PLAYER_STATS:
            LOG_INFO("Status do jogador ainda não implementado");
            break;

        case PLAYER_MENU_EXIT:
            return 0;

        default:
            LOG_WARN("\7Opção fora do escopo,reveja o enum.Valor:%i", option);
            return 1;
        }
    }
}