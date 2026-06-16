#include <stdio.h>

#include "aux_func.h"
#include "guess_game.h"
#include "jogo_do_galo.h"
#include "Engine.h"

Difficulty chooseDifficulty(void)
{
    const char MenuText[] =
        "Escolha a dificuldade desta partida:\n"
        "1 - Fácil\n"
        "2 - Média\n"
        "3 - Difícil\n"
        "0 - Sair";

    const char inputPrompt[] = "Insira a sua escolha:";

    int choice = UNKNOWN;

    puts(MenuText);
    readDigitUserInput(inputPrompt, &choice);

    switch (choice)
    {
    case EASY:
    case MEDIUM:
    case HARD:
        return (Difficulty)choice;

    default:
        puts("Entrada inválida.");
        return UNKNOWN;
    }
}

int engineStartGame(GamesMenuOptions game)
{
    switch (game)
    {
    case JOGO_DO_GALO:
        if (galoMainProcess())
        {
            LOG_ERROR("Ocorreu um erro no jogo do galo.");
            return 1;
        }

        return 0;

    case GUESS_GAME:
    {
        Difficulty difficulty = chooseDifficulty();

        if (difficulty == UNKNOWN)
        {
            return 0;
        }

        return guess_main_process(difficulty);
    }

    case GAME3:
    case GAME4:
        LOG_INFO("Ainda não implementado");
        return 0;

    default:
        LOG_ERROR("Opção de jogo desconhecida.");
        return 1;
    }
}
