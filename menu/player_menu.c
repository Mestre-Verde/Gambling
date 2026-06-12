#include <stdio.h>

#include "player_menu.h"
#include "jogador.h"
#include "aux_func.h"

PlayerMenuOption getPlayerMenuChoice(void)
{
    // variaveis
    const char menuText[] =
        "\n===== MENU JOGADOR =====\n\
1 - Criar jogador\n\
2 - Selecionar jogador\n\
3 - Remover jogador\n\
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
                LOG_ERROR("O processo de escolher um jogador foi abortado.");
            }
            else
            {
                LOG_INFO("Jogador selecionado com sucesso.");
            }
            break;

        case REMOVE_PLAYER:
            // removePlayer();
            break;

        case PLAYER_STATS:

            break;

        case PLAYER_MENU_EXIT:
            return 0;

        default:
            LOG_WARN("\7Opção fora do escopo,reveja o enum.Valor:%i", option);
            return 1;
        }
    }
}