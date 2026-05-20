#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "main_menu.h"

#include "jogo_do_galo.h"
#include "guess_game.h"
#include "aux_func.h"

typedef enum
{
    UNKNOWN = -1,
    MENU_EXIT = 0,
    MENU_GALO = 1,
    MENU_GUESS = 2,
    MENU_PLAYER = 5,
} MainMenuOption;

MainMenuOption getMenuChoice(void)
{
    const char menuText[] = "\n===== MENU PRINCIPAL =====\n1 - Jogo do Galo\n2 - Guess Game\n0 - Sair";
    int choice = -1;

    puts(menuText);
    if (readDigitUserInput("Escolha: ", &choice))
    {
        LOG_DEBUG("string recebida: %i", choice);
        return UNKNOWN;
    }

    switch (choice)
    {
    case MENU_EXIT:
    case MENU_GALO:
    case MENU_GUESS:
    case MENU_PLAYER:
        return (MainMenuOption)choice;

    default:
        return UNKNOWN;
    }
}

int mainMenu(void)
{
    while (1)
    {
        MainMenuOption option = getMenuChoice();
        LOG_DEBUG("Input lida: %i", option);
        switch (option)
        {
        case MENU_EXIT:
            return 0;

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
            // break;

        default:
            puts("Opção inválida.");
            break;
        }
    }
}