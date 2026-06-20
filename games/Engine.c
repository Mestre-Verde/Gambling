/**
 * Aqui é o unico lugar onde o jogador vai ser usado, em outros ficheiros de jogos não
 * pode ter nenhuma chamada do jogador. Isto para controlar a forma como se usa o static
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
    Difficulty difficulty = DIFFICULTY_UNKNOWN; // variavel para armazenar a dificuldade.

    // obtem a dificuldade do jogador
    if (game == GUESS_GAME || game == BLACKJACK || game == MEMORY_GAME)
    {
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
            return 0;
        }
    }

    // inicia o procesos principal do menu principal
    switch (game)
    {
    case JOGO_DO_GALO:
        if (galoMainProcess())
        {
            LOG_ERROR("Houve um problema com o jogo do galo!");
            return 1;
        }

        LOG_INFO("Processo do jogo do galo terminado com sucesso.");
        break;

    case GUESS_GAME:
        if (guess_main_process(difficulty, currentPlayer.pontos_guess, &points))
        {
            return 2;
        }
        LOG_INFO("Processo do jogo da adivinha terminado com sucesso.");
        break;

    case BLACKJACK:
        if (blackjack_main_process(difficulty, currentPlayer.blackjackPoints, &points))
        {
            return 3;
        }
        LOG_INFO("Processo do Blackjack terminado com sucesso.");
        break;

    case MEMORY_GAME:
        int memoryState = memory_game_main_process(difficulty, currentPlayer.memoryPoints, &points);

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

    // se tiver pontos incrementa-os na secção respetiva
    if (points)
    {
        LOG_DEBUG("Há pontos, a guardar no jogador.Nº de pontos:%lu", points);

        switch (game)
        {
        case GUESS_GAME:
            currentPlayer.pontos_guess += points;
            break;

        case BLACKJACK:
            currentPlayer.blackjackPoints += points;
            break;

        case MEMORY_GAME:
            currentPlayer.memoryPoints += points;
            break;
        default: // os erros já são tratados no switch do processo de jogos
            break;
        }
        if (savePlayerInDataBase(currentPlayer, PLAYERDB_DIR))
        {
            LOG_ERROR("Não foi possivel salvar o jogador na base de dados.");
        }
    }
    return 0;
}
