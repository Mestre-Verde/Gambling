#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "guess_game.h"
#include "aux_func.h"

int guess_main_process(void)
{
    // permite gerar uma seed que não repete o mesmo valor sempre
    srand(time(NULL));
    // obtem um numero aleatório e deixa-o dentro do intervalo 0 a 100
    int num = rand() % 100 + 1;

    puts("Welcome to the Guess Game!");
    puts("Try to guess the number between 1 and 100.");
    puts("Type 'S' to exit.");

    bool guessed = false;

    while (!guessed)
    {
        char buffer[100];
        int guess;

        printf("Enter your guess: ");

        if (!fgets(buffer, sizeof(buffer), stdin))
            continue;

        // sair
        if (buffer[0] == 'S' || buffer[0] == 's')
            return 0;

        // validar número
        if (sscanf(buffer, "%d", &guess) != 1)
        {
            puts("Invalid number.");
            continue;
        }

        // validar intervalo
        if (guess < 1 || guess > 100)
        {
            puts("Number must be between 1 and 100.");
            continue;
        }

        if (guess < num)
        {
            puts("Too low! Try again.");
        }
        else if (guess > num)
        {
            puts("Too high! Try again.");
        }
        else
        {
            puts("Congratulations! You've guessed the number!");
            guessed = true;
        }
    }

    return 0;
}