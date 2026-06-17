#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "guess_game.h"
#include "jogador.h"
#include "jogador.h"
#include "aux_func.h"
#include "colors.h"

unsigned long int calculateGuessPoints(Difficulty difficulty, int attemptsUsed)
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

int parseHardGuess(const char buffer[], int *guessValue)
{
    int i = 0;
    int integerPart = 0;
    int decimalPart = 0;
    int decimalDigits = 0;

    if (buffer[i] < '0' || buffer[i] > '9')
    {
        return 1;
    }

    while (isDigit(buffer[i]))
    {
        integerPart = integerPart * 10 + (buffer[i] - '0');
        i++;
    }

    if (buffer[i] == '.' || buffer[i] == ',')
    {
        i++;

        while (isDigit(buffer[i]))
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

int guess_main_process(Difficulty difficulty, unsigned long int *points)
{
    // gera uma seed "aleatória"
    srand((unsigned int)time(NULL));

    // define o numero máximo que pode gerar
    const bool hardMode = difficulty == HARD;
    int maxNumber = hardMode ? 200 : (int)difficulty * 50;

    // Variavel com o valor a adivinhar
    int secretNumber = hardMode ? rand() % ((maxNumber - 1) * 100 + 1) + 100 : rand() % maxNumber + 1;

    bool guessed = false; // variavel que guarda o valor se o jogador advinhou
    int attemptsUsed = 0; // contador de tentativas

    puts("Welcome to the Guess Game!");
    if (hardMode)
    {
        printf("Try to guess the decimal number between 1.00 and %d.00.\n", maxNumber);
    }
    else
    {
        printf("Try to guess the number between 1 and %d.\n", maxNumber);
    }
    while (!guessed)
    {
        const int MAX_BUFFER_LEN = (10 + 1);
        char buffer[MAX_BUFFER_LEN];
        if (readStrUserInput("Insira o seu palpite", MAX_BUFFER_LEN, buffer, 1, "0123456789.sS") == 1)
        {
            return 1;
        }
        // verifica se é para sair do jogo
        if (toLower(buffer[0]) == 's')
        {
            // é considerado desistencia, pontos = 0
            *points = 0;
            return 0;
        }
        // var para guardar a entrada do user.
        int guess;
        if (hardMode)
        {
            if (parseHardGuess(buffer, &guess))
            {
                LOG_INFO("Número decimal inválido. Formato: 00.00");
                continue;
            }

            if (!isBetween(guess, 100, maxNumber * 100))
            {
                LOG_INFO("O número deve estar entre 1.00 e %d.00.\n", maxNumber);
                continue;
            }
        }
        else
        {
            if (sscanf(buffer, "%d", &guess) != 1)
            {
                LOG_INFO("Numero inválido");
                continue;
            }

            if (!isBetween(guess, 1, maxNumber))
            {
                LOG_INFO("Number must be between 1 and %d.\n", maxNumber);
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

            *points += earnedPoints;

            puts(COLOR_YELLOW "Congratulations! You've guessed the number!" COLOR_RESET);

            printf("Tentativas usadas: %d\n", attemptsUsed);
            printf("Pontos ganhos: %lu\n", earnedPoints);
            printf("Total de pontos Guess Game: %lu\n", *points);

            guessed = true;
        }
    }

    return 0;
}
