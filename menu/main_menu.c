#include <stdio.h>
#include <stdbool.h>

#include "main_menu.h"
#include "jogo_do_galo.h"
#include "guess_game.h"

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
    char buffer[100];

    puts("\n===== MENU PRINCIPAL =====");
    puts("1 - Jogo do Galo");
    puts("2 - Guess Game");
    // puts("");
    // puts("");
    //  puts("5 - Defenições Jogador");
    puts("0 - Sair");
    printf("Escolha: ");

    if (!fgets(buffer, sizeof(buffer), stdin))
        return MENU_EXIT;

    if (sscanf(buffer, "%d", &choice) != 1)
        return -1;

    return choice;
}

_Bool mainMenu(void)
{
    int option;

    while (1)
    {
        option = getMenuChoice();

        switch (option)
        {
        case MENU_EXIT:
            return 0;

        case MENU_GALO:
            if (galoMainProcess())
            {
                perror("Ocorreu um erro com o jogo do galo.");
            }
            break;

        case MENU_GUESS:
            if (guess_main_processo())
            {
                perror("Ocorreu um erro com o jogo de adivinha.");
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