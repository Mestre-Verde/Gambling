#ifndef GUESS_GAME_H
#define GUESS_GAME_H

#include "Engine.h"

int guess_main_process(Difficulty, unsigned long int *);

#endif

/*

int guess_main_process(Difficulty difficulty, unsigned long int *points)
{
    // gera uma seed "aleatória"
    srand((unsigned int)time(NULL));

    int maxNumber = difficulty == HARD ? 200 : (int)difficulty * 50;

    bool hardMode = difficulty == HARD;

    int secretNumber;

    if (hardMode)
    {
        secretNumber = rand() % ((maxNumber - 1) * 100 + 1) + 100;
    }
    else
    {
        secretNumber = rand() % maxNumber + 1;
    }

    puts("Welcome to the Guess Game!");

    if (hardMode)
    {
        printf("Try to guess the decimal number between 1.00 and %d.00.\n", maxNumber);
    }
    else
    {
        printf("Try to guess the number between 1 and %d.\n", maxNumber);
    }

    puts("Type 'S' to exit.");

    bool guessed = false;
    int attemptsUsed = 0;

    while (!guessed)
    {
        char buffer[100];
        int guess;

        printf("Enter your guess: ");

        if (!fgets(buffer, sizeof(buffer), stdin))
        {
            {
                continue;
            }
        }

        if (buffer[0] == 'S' || buffer[0] == 's')
        {

            if (hardMode)
            {
                if (parseHardGuess(buffer, &guess))
                {
                    puts("Invalid decimal number. Example: 37.42");
                    continue;
                }

                if (!isBetween(guess, 100, maxNumber * 100))
                {
                    printf("Number must be between 1.00 and %d.00.\n", maxNumber);
                    continue;
                }
            }
            else
            {
                if (sscanf(buffer, "%d", &guess) != 1)
                {
                    puts("Invalid number.");
                    continue;
                }
            }

            if (hardMode)
            {
                if (parseHardGuess(buffer, &guess))
                {
                    puts("Invalid decimal number. Example: 37.42");
                    continue;
                }

                if (!isBetween(guess, 100, maxNumber * 100))
                {
                    printf("Number must be between 1.00 and %d.00.\n", maxNumber);
                    continue;
                }
            }
            else
            {
                if (sscanf(buffer, "%d", &guess) != 1)
                {
                    puts("Invalid number.");
                    continue;
                }

                if (!isBetween(guess, 1, maxNumber))
                {
                    printf("Number must be between 1 and %d.\n", maxNumber);
                    continue;
                }
                if (!isBetween(guess, 1, maxNumber))
                {
                    printf("Number must be between 1 and %d.\n", maxNumber);
                    continue;
                }
            }

            attemptsUsed++;

            if (guess < secretNumber)
                attemptsUsed++;

            if (guess < secretNumber)
            {
                puts(COLOR_BLUE "Too low! Try again." COLOR_RESET);
            }

            else if (guess > secretNumber)
            {
                puts(COLOR_RED "Too high! Try again." COLOR_RESET);
            }
            else
            {
                unsigned long int earnedPoints = calculateGuessPoints(difficulty, attemptsUsed);

                currentPlayer.pontos_guess += earnedPoints;

                puts(COLOR_YELLOW "Congratulations! You've guessed the number!" COLOR_RESET);

                printf("Tentativas usadas: %d\n", attemptsUsed);
                printf("Pontos ganhos: %lu\n", earnedPoints);
                printf("Total de pontos Guess Game: %lu\n", currentPlayer.pontos_guess);

                guessed = true;
            }
        }

        return 0;
    }
    return 1;
}
*/