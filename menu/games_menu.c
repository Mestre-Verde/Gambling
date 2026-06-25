/*
 * games_menu.c
 * Menu que lista os jogos disponíveis e delega a execução para o Engine.
 * Responsabilidades:
 * - Mostrar pontuações do `currentPlayer`
 * - Validar escolha do jogo e chamar `engineStartGame()`
 */

#include <stdio.h>

#include "aux_func.h"

#include "games_menu.h"

#include "jogador.h"
#include "Engine.h"

GamesMenuOptions getGamesMenuOption(void)
{

    const char menuText[] =
        TEXT_BOLD COLOR_BRIGHT_CYAN
        "\n===== MENU JOGOS =====" COLOR_RESET
        "\t|%s|\n" COLOR_RESET COLOR_BRIGHT_WHITE
        "1 - Jogo do Galo\n"
        "2 - Jogo de Adivinha\t" COLOR_YELLOW "[%lu]\n" COLOR_RESET
        "3 - Pedra Papel Tesoura " COLOR_YELLOW "[%lu]\n" COLOR_RESET
        "4 - Jogo da Memória\t" COLOR_YELLOW "[%lu]\n" COLOR_RESET
        "0 - Voltar\n" COLOR_RESET;

    printf(menuText, currentPlayer.id == 0 ? "Nenhum" : currentPlayer.nome, currentPlayer.pontos_guess, currentPlayer.pedra_papel_tesouraPoints, currentPlayer.memoryPoints);

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
    case PEDRA_PAPEL_TESOURA:
    case MEMORY_GAME:
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
            puts(COLOR_GOLD "Opção inválida." COLOR_RESET);
            break;

        case GAMES_MENU_EXIT:
            return 0;

        case JOGO_DO_GALO:
        case GUESS_GAME:
        case PEDRA_PAPEL_TESOURA:
        case MEMORY_GAME:
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
