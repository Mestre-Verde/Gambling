#include <stdio.h>

#include "aux_func.h"

#include "games_menu.h"

#include "jogador.h"

#include "Engine.h"

GamesMenuOptions getGamesMenuOption(void)
{
    const char menuText[] =
        "\n===== MENU JOGOS =====\t|%s|\n\
1 - Jogo do Galo\n\
2 - Jogo de advinha\n\
3 - Game3\n\
4 - Game4\n\
0 - Voltar\n";

    printf(menuText, currentPlayer.id == 0 ? "Nenhum" : currentPlayer.nome);

    int choice = GAMES_MENU_UNKNOWN;
    if (readDigitUserInput("Escolha: ", &choice))
    {
        return GAMES_MENU_UNKNOWN;
    }

    switch (choice)
    {
    case GAMES_MENU_EXIT:
    case JOGO_DO_GALO:
    case GUESS_GAME:
    case GAME3:
    case GAME4:
        return (GamesMenuOptions)choice;

    default:
        return GAMES_MENU_UNKNOWN;
    }
}

int gamesMenu(void)
{
     GamesMenuOptions option = getGamesMenuOption();
    if (option == GAMES_MENU_UNKNOWN)
    {
        puts("Opção inválida. Tente novamente.");
        return 1;
    }
    else if (option == GAMES_MENU_EXIT)
    {
        return 0; // Voltar ao menu principal
    }
    if (engineStartGame(option))
    {
        LOG_ERROR("Ocorreu um erro ao iniciar o jogo.");
        return 1;
    }
    return 1;
}