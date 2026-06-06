#include <stdio.h>

#include "main_menu.h"
#include "player_menu.h"

#include "jogo_do_galo.h"
#include "guess_game.h"
#include "aux_func.h"

MainMenuOption getMainMenuChoice(void)
{
    const char menuText[] =
        "\n===== MENU PRINCIPAL =====\n\
1 - Jogo do Galo\n\
2 - Guess Game\n\
5 - Defenições de jogador\n\
0 - Sair";
    int choice = MENU_UNKNOWN;

    puts(menuText);
    if (readDigitUserInput("Escolha: ", &choice))
    {
        // LOG_DEBUG("digito recebido: %i", choice);
        return MENU_UNKNOWN;
    }

    // verifica se há um valor correspondente ao enum.
    switch (choice)
    {
    case MENU_EXIT:
    case MENU_GALO:
    case MENU_GUESS:
    case MENU_PLAYER:
        return (MainMenuOption)choice;

    default:
        return MENU_UNKNOWN;
    }
}

int mainMenu(void)
{
    while (1)
    {
        MainMenuOption option = getMainMenuChoice();
        LOG_DEBUG("Valor de Enum recebido: %i", option);
        switch (option)
        {
        case MENU_UNKNOWN:
            puts("Opção inválida.");
            break;

        case MENU_GALO:
            if (galoMainProcess())
            {
                LOG_ERROR("Ocorreu um erro com o jogo do galo.");
            }
            break;

        case MENU_GUESS:
            if (guess_main_process())
            {
                LOG_ERROR("Ocorreu um erro com o jogo de adivinha.");
            }
            break;

        case MENU_PLAYER:
            if (playerMenu())
            {
                LOG_ERROR("Ocorreu um erro com o menu de jogador.");
            }
            break;

        case MENU_EXIT:
            return 0;

        default:
            LOG_WARN("\7Opção fora do escopo,reveja o enum.Valor:%i", option);
            return 1;
        }
    }
}