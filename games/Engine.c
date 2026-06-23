/**
 * Aqui é o unico lugar onde o jogador vai ser usado, em outros ficheiros de jogos não
 * pode ter nenhuma chamada do jogador. Isto para controlar a forma como se usa o static
 * Com isso, este vai ser o launcher. Os parametros do jogador a mexer devem ser passados como parametros e constantes.
 */

#include <stdio.h>

#include "aux_func.h"

#include "Engine.h"
#include "FileManager.h"
#include "jogador.h"

#include "guess_game.h"
#include "jogo_do_galo.h"
#include "pedra_papel_tesoura.h"
#include "memory_game.h"

Difficulty chooseDifficulty(void)
{
    const char MenuText[] =
        "\nEscolha a dificuldade desta partida:\n" BG_GREEN COLOR_BLACK " 1 - Fácil" COLOR_RESET "\n" BG_YELLOW COLOR_BLACK " 2 - Média" COLOR_RESET "\n" BG_RED COLOR_WHITE " 3 - Difícil" COLOR_RESET "\n" COLOR_WHITE " 0 - Voltar ao menu\n" COLOR_RESET;

    printf("%s", MenuText);

    int choice = DIFFICULTY_UNKNOWN;
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
    if (game == GUESS_GAME || game == MEMORY_GAME)
    {
        do
        {
            // obtem a dificuldade que o user escolher
            difficulty = chooseDifficulty();

            if (difficulty == DIFFICULTY_UNKNOWN)
            {
                puts(COLOR_GOLD "Entrada inválida." COLOR_RESET);
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

    case PEDRA_PAPEL_TESOURA:
        if (main_process_pedra_papel_tesoura(currentPlayer.pedra_papel_tesouraPoints, &points))
        {
            return 3;
        }
        LOG_INFO("Processo do jogo Pedra,Papel,Tesoura terminado com sucesso.");
        break;

    case MEMORY_GAME:
        if (memory_game_main_process(difficulty, currentPlayer.memoryPoints, &points))
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
        return 5;
    }

    // se tiver pontos incrementa-os na secção respetiva
    if (points > 0)
    {
        LOG_DEBUG("Há pontos, a guardar no jogador.Nº de pontos:%lu", points);

        switch (game)
        {
        case GUESS_GAME:
            currentPlayer.pontos_guess += points;
            break;

        case PEDRA_PAPEL_TESOURA:
            currentPlayer.pedra_papel_tesouraPoints += points;
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
    else if (points < 0)
    {
        LOG_WARN("Detetados Pontos negativos! Jogo: %i |pontos: %lu.", game, points);
        return 6;
    }

    return 0;
}
