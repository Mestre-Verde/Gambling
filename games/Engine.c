/**
 * Aqui é o unico lugar onde o jogador vai ser usado, em outros ficheiros de jogos não
 * pode ter nenhuma chamada do jogador.
 *  Com isso, este vai ser o launcher. um jogador é passado com ponteiro para os jogos.
 */

#include <stdio.h>
#include "aux_func.h"
#include "guess_game.h"
#include "jogo_do_galo.h"
#include "Engine.h"

Difficulty chooseDifficulty(void)
{
    const char MenuText[] = "Escolha a dificuldade desta partida:\n1 - Fácil\n2 - Média\n3 - Difícil\n0 - Sair";
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
