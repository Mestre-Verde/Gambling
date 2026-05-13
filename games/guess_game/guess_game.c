#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int guess_main_processo(void)
{
    // permite gerar uma seed que não repete o mesmo valor sempre
    srand(time(NULL));
    // obtem um numero aleatório e deixa-o dentro do intervalo 0 a 100
    int num = rand() % 100 + 1;

    puts("Welcome to the Guess Game!");
    puts("Try to guess the number between 1 and 100.");

    int guess;
    bool guessed = false;

    while (!guessed)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

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