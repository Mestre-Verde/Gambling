#include <stdio.h>

#include "aux_func.h"

#include "games_menu.h"

#include "jogador.h"
#include "Engine.h"

GamesMenuOptions getGamesMenuOption(void)
{
    const char menuText[] =
        "\n\n===== MENU JOGOS =====\t|%s|\n"
        "1 - Jogo do Galo\n"
        "2 - Jogo de advinha\t[%lu]\n"
        "3 - Blackjack\n"
        "4 - Game4\n"
        "0 - Voltar\n";

    printf(menuText, currentPlayer.id == 0 ? "Nenhum" : currentPlayer.nome, currentPlayer.pontos_guess);

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
    case BLACKJACK:
    case GAME4:
        return (GamesMenuOptions)choice;

    default:
        return GAMES_MENU_UNKNOWN;
    }
}

int gamesMenu(void)
{
    if (currentPlayer.id == 0)
    {
        LOG_INFO("Precisa de escolher um jogador primeiro!");
        return 0;
    }
    while (1)
    {
        GamesMenuOptions option = getGamesMenuOption();

        switch (option)
        {
        case GAMES_MENU_UNKNOWN:
            puts("Opção inválida.");
            break;

        case GAMES_MENU_EXIT:
            return 0;

        case JOGO_DO_GALO:
        case GUESS_GAME:
        case BLACKJACK:
        case GAME4:
            int state = engineStartGame(option);
            if (state)
            {
                LOG_ERROR("Erro ao iniciar o Engine. Código: %d", state);
                return 1;
            }
            break;

        default:
            LOG_WARN("\7Opção fora do escopo,reveja o enum.Valor:%i", option);
            return 1;
        }
    }
}