#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int num;

int guess_main_processo(void)
{
    puts("Welcome to the Guess Game!");
    puts("Try to guess the number between 1 and 100.");

    num = rand() % 100 + 1;

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