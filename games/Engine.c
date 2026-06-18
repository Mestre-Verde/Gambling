/**
 * Aqui é o unico lugar onde o jogador vai ser usado, em outros ficheiros de jogos não
 * pode ter nenhuma chamada do jogador.
 * Com isso, este vai ser o launcher. Os parametros do jogador a mexer devem ser passados como parametros.
 */

#include <stdio.h>

#include "aux_func.h"

#include "Engine.h"
#include "FileManager.h"
#include "jogador.h"

#include "guess_game.h"
#include "jogo_do_galo.h"
#include "blackjack_game.h"
#include "memory_game.h"

Difficulty chooseDifficulty(void)
{
    const char MenuText[] =
        "\nEscolha a dificuldade desta partida:\n"
        "1 - Fácil\n"
        "2 - Média\n"
        "3 - Difícil\n"
        "0 - Sair";

    int choice = DIFFICULTY_UNKNOWN;

    puts(MenuText);

    if (readDigitUserInput("Insira a sua escolha: ", &choice))
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
            LOG_ERROR("Houve um problema com o jogo do galo!");
        }

        LOG_INFO("Processo do jogo do galo terminado com sucesso.");
        break;

    case GUESS_GAME:
        // variavel para armazenar a dificuldade.
        Difficulty difficulty = DIFFICULTY_UNKNOWN;
        do
        {
            // obtem a dificuldade que o user escolher
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

        // guarda em uma variavel o estado do processo do jogo
        int state = guess_main_process(difficulty, currentPlayer.pontos_guess, &points);

        if (state)
        {
            return 2;
        }
        else
        {
            LOG_INFO("Processo do jogo da adivinha terminado com sucesso.");
        }
        break;

    case BLACKJACK:
        Difficulty blackjackDifficulty = DIFFICULTY_UNKNOWN;

        do
        {
            blackjackDifficulty = chooseDifficulty();

            if (blackjackDifficulty == DIFFICULTY_UNKNOWN)
            {
                puts("Entrada inválida.");
            }

        } while (blackjackDifficulty == DIFFICULTY_UNKNOWN);

        if (blackjackDifficulty == DIFFICULTY_EXIT)
        {
            break;
        }

        int blackjackState = blackjack_main_process(blackjackDifficulty, &points);

        if (blackjackState)
        {
            return 3;
        }

        LOG_INFO("Processo do Blackjack terminado com sucesso.");
        break;

    case MEMORY_GAME:
        Difficulty memoryDifficulty = DIFFICULTY_UNKNOWN;

        do
        {
            memoryDifficulty = chooseDifficulty();

            if (memoryDifficulty == DIFFICULTY_UNKNOWN)
            {
                puts("Entrada inválida.");
            }

        } while (memoryDifficulty == DIFFICULTY_UNKNOWN);

        if (memoryDifficulty == DIFFICULTY_EXIT)
        {
            break;
        }

        int memoryState = memory_game_main_process(memoryDifficulty, &points);

        if (memoryState)
        {
            return 4;
        }

        LOG_INFO("Processo do Memory Game terminado com sucesso.");
        break;

    case GAMES_MENU_EXIT:
    case GAMES_MENU_UNKNOWN:
        LOG_WARN("EXIT ou UNKNOWN do menu anterior entrou no engine!!");
        return 5;

    default:
        LOG_WARN("Jogo desconhecido entrou no engine.Valor:%i", game);
        return 6;
    }
    if (points)
    {
        LOG_DEBUG("Há pontos, a guardar no jogador.Nº de pontos:%lu", points);
        currentPlayer.pontos_guess += points;

        if (savePlayerInDataBase(currentPlayer, PLAYERDB_DIR))
        {
            LOG_ERROR("Não foi possivel salvar o jogador na base de dados.");
        }
    }

    return 0;
}
