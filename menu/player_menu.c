#include <stdio.h>

#include "player_menu.h"
#include "jogador.h"
#include "aux_func.h"

PlayerMenuOption getPlayerMenuChoice(void)
{
    // variaveis
    const char menuText[] = "\n===== MENU JOGADOR =====\n1 - Selecionar jogador\n2 - Criar jogador\n3 - Remover jogador\n0 - Voltar";
    int choice = -1;

    // imprimir textMenu e obter a resposta do user.
    puts(menuText);
    if (readDigitUserInput("Escolha :", &choice))
    {
        return PLAYER_MENU_UNKNOWN;
    }

    switch (choice)
    {
    case PLAYER_MENU_EXIT:
    case CHOOSE_PLAYER:
    case CREATE_PLAYER:
    case REMOVE_PLAYER:
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

        case CHOOSE_PLAYER:
            break;
        case CREATE_PLAYER:
            buildPlayer();
            break;
        case REMOVE_PLAYER:
            break;

        case PLAYER_MENU_EXIT:
            return 0;

        default:
            LOG_WARN("\7"
                     "Opção fora do escopo,reveja o enum.Valor:%i",
                     option);
            return 1;
        }
    }
}