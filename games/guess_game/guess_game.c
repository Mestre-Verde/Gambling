#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "guess_game.h"
#include "jogador.h"
#include "jogador.h"
#include "aux_func.h"
#include "colors.h"

/**
 * @brief função para calcular os pontos com base em tentativas
 * @param difficulty dificuldade do jogo
 * @param attemptsUsed nº de tentativas.
 * @param finalPoints ponteiro para a variavel que armazena os pontos locais.
 * @return 0 se sucesso, 1 se ocorreu um problema.
 */
int calculateGuessPoints(Difficulty difficulty, int attemptsUsed, unsigned long int *finalPoints)
{
    int basePoints;      // pontos base
    int penalPerAttempt; // penalização por tentativa

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
        LOG_WARN("Recebida uma dificuldade não listada. Valor:%i", difficulty);
        return 1;
    }

    // pontos finais = pontos base menos nº de tentativas, ignorando a que acertou no numero vezes a penalização por tentativa.
    int totalPoints = basePoints - ((attemptsUsed - 1) * penalPerAttempt);
    LOG_DEBUG("Pontos totais: %i - (%i - 1) x %i = %i", basePoints, attemptsUsed, penalPerAttempt, totalPoints);
    if (totalPoints < 0)
    {
        totalPoints = 0;
    }

    *finalPoints = (unsigned long int)totalPoints;
    return 0;
}

/**
 * @brief Converte uma string em um numero decimal para a dificuldade dificil.
 * @param buffer string a converter.
 * @param guessValue ponteiro para a variavel a substituir.
 * @return 0 se sucesso, 1 se o formato não é o correto.
 */
int parseHardGuess(const char buffer[], int *guessValue)
{
    int i = 0;
    int integerPart = 0;
    int decimalPart = 0;
    int decimalDigits = 0;

    if (!isDigit(buffer[i]))
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

    *guessValue = integerPart * 100 + decimalPart;
    return 0;
}

int guess_main_process(const Difficulty difficulty, const unsigned long int currentPoints, unsigned long int *points)
{
    // gera uma seed "aleatória"
    srand((unsigned int)time(NULL));

    // define o numero máximo que pode gerar
    const bool isHard = difficulty == HARD;
    int maxNumber = isHard ? 200 : (int)difficulty * 50;

    const int MIN_VALUE = 1; // valor minimo

    // Variavel com o valor a adivinhar
    int secretNumber = isHard ? rand() % ((maxNumber - 1) * 100 + MIN_VALUE) + 100 : rand() % maxNumber + 1;

    bool guessed = false; // variavel que guarda o valor se o jogador advinhou
    int attemptsUsed = 0; // contador de tentativas

    // imprime as introduções ao jogo
    puts("\nWelcome to the Guess Game!");
    if (isHard)
    {
        printf("Tenta advinhar o número decimal entre %i.00 e %d.00.\n", MIN_VALUE, maxNumber);
    }
    else
    {
        printf("Tenta advinhar o número inteiro entre %i e %d.\n", MIN_VALUE, maxNumber);
    }
    while (!guessed)
    {
        LOG_DEBUG("secret number: %d | maxNumber:%i |attemptsUsed:%i | isHard: %d", secretNumber, maxNumber, attemptsUsed, isHard);

        // var para guardar a entrada do user.
        int guess = 0;

        if (isHard)
        {
            const int MAX_BUFFER_LEN = (10 + 1);
            char buffer[MAX_BUFFER_LEN];
            if (readStrUserInput("Insira o seu palpite(insira S para saír)", MAX_BUFFER_LEN, buffer, 0, "") == 1)
            {
                return 1;
            }
            //  verifica se é para sair do jogo
            if (toLower(buffer[0]) == 's')
            {
                // é considerado desistencia, pontos = 0
                return 0;
            }
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
            // guarda a entrada do user.
            int inputStatus = readDigitUserInput("Insira o seu palpite(-1 para sair):", &guess);
            switch (inputStatus)
            {
            case -1:
                puts("Entrada inválida.");
                continue;

            case 0:
                if (guess == -1) // verifica se é para sair.
                {
                    // é considerado desistencia, pontos = 0
                    return 0;
                }
                // verifica se a entrada está dentro do intervalo aceitável.
                if (!isBetween(guess, MIN_VALUE, maxNumber))
                {
                    LOG_INFO("O número deve estar entre 1 e %d.\n", maxNumber);
                    continue;
                }
                break;

            case 1:
                return 1;

            default:
                LOG_WARN("Valor desconhecido de readDigitInput. Valor:%i", inputStatus);
                return 1;
            }
        }

        attemptsUsed++;

        if (guess < secretNumber)
        {
            puts(COLOR_BLUE "Muito baixo! Tenta outra vez." COLOR_RESET);
        }

        else if (guess > secretNumber)
        {
            puts(COLOR_RED "Muito alto! Tenta outra vez." COLOR_RESET);
        }
        else
        {
            unsigned long int earnedPoints = 0;
            if (calculateGuessPoints(difficulty, attemptsUsed, &earnedPoints))
            {
                return 1;
            }

            *points = earnedPoints;

            createLine(50, '#');
            puts(COLOR_YELLOW "Parabéns! Advinhaste o número!" COLOR_RESET);

            printf("Nº de tentativas: %d\n", attemptsUsed);
            printf("Pontos ganhos: %lu\n", earnedPoints);
            printf("Pontos totais do jogador no Guess Game: %lu\n", currentPoints + earnedPoints);
            createLine(50, '#');

            guessed = true;
        }
    }
    return 0;
}