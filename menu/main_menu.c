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
    MENU_GALO = 1,
    MENU_GUESS = 2,
    MENU_PLAYER = 5,
    UNKNOWN = 9,

} MainMenuOption;

MainMenuOption getMenuChoice(void)
{
    
    char buffer[5 + 1];

    puts("\n===== MENU PRINCIPAL =====");
    puts("1 - Jogo do Galo");
    puts("2 - Guess Game");
    puts("0 - Sair");
    printf("Escolha: ");

    // Obtem a entrada do usuário e guarda no buffer.
    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
        return UNKNOWN;

    // Verifica se existe um new line.
    if (strchr(buffer, '\n') == NULL)
        clearStdinTrash();

    int value;
    if (sscanf(buffer, "%d", &value) != 1)
        return UNKNOWN;

    switch (value)
    {
    case MENU_EXIT:
    case MENU_GALO:
    case MENU_GUESS:
    case MENU_PLAYER:
        return (MainMenuOption)value;

    default:
        return UNKNOWN;
    }
}

signed short int mainMenu(void)
{
    while (1)
    {
        MainMenuOption option = getMenuChoice();

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