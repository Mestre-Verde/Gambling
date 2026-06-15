#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "guess_game.h"
#include "jogador.h"
#include "aux_func.h"

#define COLOR_RED "\033[31m"
#define COLOR_BLUE "\033[34m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_RESET "\033[0m"

static int getMaxNumberByDifficulty(Difficulty difficulty)
{
    switch (difficulty)
    {
    case EASY:
        return 50;

    case MEDIUM:
        return 100;

    case HARD:
        return 200;

    default:
        return 100;
    }
}

static unsigned long int calculateGuessPoints(Difficulty difficulty, int attemptsUsed)
{
    int basePoints;
    int penalPerAttempt;

    switch (difficulty)
    {
    case EASY:
        basePoints = 100;
        penalPerAttempt = 10;
        break;

    case MEDIUM:
        basePoints = 150;
        penalPerAttempt = 15;
        break;

    case HARD:
        basePoints = 250;
        penalPerAttempt = 25;
        break;

    default:
        return 0;
    }

    int totalPoints = basePoints - ((attemptsUsed - 1) * penalPerAttempt);

    if (totalPoints < 0)
    {
        totalPoints = 0;
    }

    return (unsigned long int)totalPoints;
}

static int parseHardGuess(const char buffer[], int *guessValue)
{
    int i = 0;
    int integerPart = 0;
    int decimalPart = 0;
    int decimalDigits = 0;

    if (buffer[i] < '0' || buffer[i] > '9')
    {
        return 1;
    }

    while (buffer[i] >= '0' && buffer[i] <= '9')
    {
        integerPart = integerPart * 10 + (buffer[i] - '0');
        i++;
    }

    if (buffer[i] == '.' || buffer[i] == ',')
    {
        i++;

        while (buffer[i] >= '0' && buffer[i] <= '9')
        {
            if (decimalDigits >= 2)
            {
                return 1;
            }

            decimalPart = decimalPart * 10 + (buffer[i] - '0');
            decimalDigits++;
            i++;
        }

        if (decimalDigits == 1)
        {
            decimalPart *= 10;
        }
    }

    if (buffer[i] != '\n' && buffer[i] != '\0')
    {
        return 1;
    }

    *guessValue = integerPart * 100 + decimalPart;
    return 0;
}

int guess_main_process(Difficulty difficulty)
{
    srand((unsigned int)time(NULL));

    int maxNumber = getMaxNumberByDifficulty(difficulty);
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
            continue;
        }

        if (buffer[0] == 'S' || buffer[0] == 's')
        {
            return 0;
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
        }

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