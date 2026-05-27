#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "guess_game.h"
#include "aux_func.h"

#define COLOR_RED "\033[31m"
#define COLOR_BLUE "\033[34m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

/*
 * Executa o jogo "Guess Game".
 * O jogador tenta adivinhar um numero aleatorio entre 1 e 100.
 * O jogo termina quando o jogador acerta ou escreve 'S' para sair.
 */
int guess_main_process(void)
{
    // Inicializa a seed do gerador aleatorio com a hora atual.
    srand(time(NULL));

    // Gera o numero secreto no intervalo de 1 a 100.
    int num = rand() % 100 + 1;

    // Mostra as instrucoes iniciais ao jogador.
    puts("Welcome to the Guess Game!");
    puts("Try to guess the number between 1 and 100.");
    puts("Type 'S' to exit.");

    // Controla se o jogador ja acertou no numero.
    bool guessed = false;

    // Repete enquanto o jogador nao acertar nem sair.
    while (!guessed)
    {
        // Buffer usado para ler a linha completa escrita pelo jogador.
        char buffer[100];
        int guess;

        printf("Enter your guess: ");

        // Le a entrada do utilizador de forma segura.
        if (!fgets(buffer, sizeof(buffer), stdin))
            continue;

        // Permite sair do jogo escrevendo 'S' ou 's'.
        if (buffer[0] == 'S' || buffer[0] == 's')
            return 0;

        // Converte a entrada para numero inteiro e valida se a conversao resultou.
        if (sscanf(buffer, "%d", &guess) != 1)
        {
            puts("Invalid number.");
            continue;
        }

        // Garante que a tentativa esta dentro do intervalo permitido.
        if (guess < 1 || guess > 100)
        {
            puts("Number must be between 1 and 100.");
            continue;
        }

        // Compara a tentativa com o numero secreto e mostra uma pista ao jogador.
        if (guess < num)
        {
            puts(COLOR_BLUE "Too low! Try again." COLOR_RESET);
        }
        else if (guess > num)
        {
            puts(COLOR_RED "Too high! Try again." COLOR_RESET);
        }
        else
        {
            puts(COLOR_YELLOW "Congratulations! You've guessed the number!" COLOR_RESET);
            guessed = true;
        }
    }

    return 0;
}
