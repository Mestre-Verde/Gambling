/**
 * Aqui é o unico lugar onde o jogador vai ser usado, em outros ficheiros de jogos não
 * pode ter nenhuma chamada do jogador.
 *  Com isso, este vai ser o launcher. Os parametros do jogador a mexer devem ser passados como parametros.
 */
#include <stdio.h>

#include "aux_func.h"

#include "Engine.h"
#include "FileManager.h"
#include "jogador.h"

#include "guess_game.h"
#include "jogo_do_galo.h"

Difficulty chooseDifficulty(void)
{
    const char MenuText[] =
        "Escolha a dificuldade desta partida:\n"
        "1 - Fácil\n"
        "2 - Média\n"
        "3 - Difícil\n"
        "0 - Sair";

    int choice = DIFFICULTY_UNKNOWN;

    puts(MenuText);
    if (readDigitUserInput("Insira a sua escolha:", &choice))
    {
        return DIFFICULTY_UNKNOWN;
    }

    switch (choice)
    {
    case DIFFICULTY_EXIT:
    case EASY:
    case MEDIUM:
    case HARD:
        return (Difficulty)choice;

    default:
        return DIFFICULTY_UNKNOWN;
    }
}

int engineStartGame(GamesMenuOptions game)
{
    unsigned long int points = 0;
    switch (game)
    {
    case JOGO_DO_GALO:
        if (galoMainProcess())
        {
            LOG_ERROR("Ocorreu um erro no jogo do galo.");
            return 2;
        }
        break;

    case GUESS_GAME:

        Difficulty difficulty = DIFFICULTY_UNKNOWN;

        do
        {
            difficulty = chooseDifficulty();

            if (difficulty == DIFFICULTY_UNKNOWN)
            {
                puts("Entrada inválida.");
            }

        } while (difficulty == DIFFICULTY_UNKNOWN);

        if (difficulty == DIFFICULTY_EXIT)
        {
            break;
        }
        int state = guess_main_process(difficulty, &points);
        if (state)
        {
            return 3;
        }

        break;

    case GAME3:
    case GAME4:
        LOG_INFO("Ainda não implementado");
        break;

    case GAMES_MENU_EXIT:
    case GAMES_MENU_UNKNOWN:
        LOG_WARN("EXIT ou UNKNOWN do menu anterior entrou no engine!!");
        return 5;
    }
    if (points)
    {
        savePlayerInDataBase(currentPlayer, PLAYERDB_DIR);
    }

    return 0;
}
