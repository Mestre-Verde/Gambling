#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "blackjack_game.h"
#include "jogador.h"
#include "aux_func.h"
#include "Engine.h"

static int drawCard(void)
{
    return rand() % 11 + 1; // Gera um número aleatório entre 1 e 11
}

static int getDealerStopValueByDifficulty(Difficulty difficulty)
{
    switch (difficulty)
    {
    case EASY:
        return 15; // dealer stops at 15 in easy mode

    case MEDIUM:
        return 17; // dealer stops at 17 in medium mode

    case HARD:
        return 18; // dealer stops at 18 in hard mode

    default:
        return 17;
    }
}
static unsigned long int calculateBlackjackPoints(Difficulty difficulty, int playerTotal, int dealerTotal)
{
    int basePoints;
    int bonusPoints;

    switch (difficulty)
    {
    case EASY:
        basePoints = 100;
        bonusPoints = 20;
        break;

    case MEDIUM:
        basePoints = 150;
        bonusPoints = 30;
        break;

    case HARD:
        basePoints = 250;
        bonusPoints = 50;
        break;

    default:
        return 0;
    }

    if (playerTotal > dealerTotal && playerTotal <= 21)
    {
        return basePoints + bonusPoints;
    }
    else if (playerTotal == dealerTotal)
    {
        return basePoints; // empate, apenas pontos base
    }
    else
    {
        return 0; // perdeu, sem pontos
    }
}
int blackjack_main_process(Difficulty difficulty, unsigned long int *points)
{
    
    srand((unsigned int)time(NULL));

    int dealerStopValue = getDealerStopValueByDifficulty(difficulty);

    int playerTotal = drawCard() + drawCard();
    int dealerTotal = drawCard() + drawCard();

    printf("Bem vindo ao Blackjack!\n");
    printf("O teu valor inicial é: %d\n", playerTotal);
    printf("O valor do dealer é: %d\n", dealerTotal);

    

    while (playerTotal < 21)
    {
        int choice;

        puts("Escolhe uma opção:\n1 - Pedir carta\n2 - Parar");

        if (readDigitUserInput("Escolha: ", &choice))
        {
            puts("Opção inválida.");
            continue;
        }

        if (choice == 1)
        {
            int card = drawCard();
            playerTotal += card;

            printf("Carta recebida: %d\n", card);
            printf("Total atual: %d\n", playerTotal);
        }
        else if (choice == 2)
        {
            break;
        }
        else
        {
            puts("Opção inválida.");
        }
    }

    *points = calculateBlackjackPoints(difficulty, playerTotal, dealerTotal);
    return 0;
}
