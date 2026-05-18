#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "main_menu.h"

#include "jogo_do_galo.h"
#include "guess_game.h"
#include "aux_func.h"

typedef enum
{
    MENU_EXIT = 0,
    MENU_PLAYER = 5,
    MENU_GALO = 1,
    MENU_GUESS = 2,
} MainMenuOption;

int getMenuChoice(void)
{
    int choice;
    char buffer[3 + 1];

    puts("\n===== MENU PRINCIPAL =====");
    puts("1 - Jogo do Galo");
    puts("2 - Guess Game");
    puts("0 - Sair");
    printf("Escolha: ");

    if (!fgets(buffer, sizeof(buffer), stdin))
        return MENU_EXIT;

    if (strchr(buffer, '\n') == NULL)
        clearStdinTrash();

    if (sscanf(buffer, "%d", &choice) != 1)
        return -1;

    return choice;
}

_Bool mainMenu(void)
{
    while (1)
    {
        int option = getMenuChoice();

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
            if (guess_main_processo())
            {
                LOG_ERROR("Ocorreu um erro com o jogo de adivinha.");
            }
            break;

        case MENU_PLAYER:
            break;

        default:
            puts("Opção inválida.");
            break;
        }
    }
}