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
    return rand() % 11 + 1;
}

static int getDealerStopValueByDifficulty(Difficulty difficulty)
{
    switch (difficulty)
    {
    case EASY:
        return 15;

    case MEDIUM:
        return 17;

    case HARD:
        return 18;

    default:
        return 17;
    }
}

static unsigned long int calculateBlackjackPoints(Difficulty difficulty, int playerTotal, int dealerTotal)
{
    unsigned long int basePoints;
    unsigned long int bonusPoints;

    if (playerTotal > 21)
    {
        return 0;
    }

    if (playerTotal == dealerTotal)
    {
        return 25;
    }

    if (dealerTotal <= 21 && dealerTotal > playerTotal)
    {
        return 0;
    }

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

    if (playerTotal == 21)
    {
        return basePoints + bonusPoints;
    }

    return basePoints;
}

int blackjack_main_process(Difficulty difficulty, unsigned long int *points)
{
    *points = 0;

    srand((unsigned int)time(NULL));

    int dealerStopValue = getDealerStopValueByDifficulty(difficulty);

    int playerTotal = drawCard() + drawCard();
    int dealerTotal = drawCard() + drawCard();

    printf("Bem vindo ao Blackjack!\n");
    printf("O teu valor inicial e: %d\n", playerTotal);
    printf("O valor inicial do dealer e: %d\n", dealerTotal);

    while (playerTotal < 21)
    {
        int choice;

        puts("\nEscolhe uma opcao:");
        puts("1 - Pedir carta");
        puts("2 - Parar");

        if (readDigitUserInput("Escolha: ", &choice))
        {
            puts("Opcao invalida.");
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
            puts("Opcao invalida.");
        }
    }

    if (playerTotal > 21)
    {
        puts("\nPassaste de 21. Perdeste.");
        *points = 0;
        return 0;
    }

    puts("\nVez do dealer...");

    while (dealerTotal < dealerStopValue)
    {
        int card = drawCard();
        dealerTotal += card;

        printf("Dealer recebeu carta: %d\n", card);
        printf("Total do dealer: %d\n", dealerTotal);
    }

    printf("\nTotal final do jogador: %d\n", playerTotal);
    printf("Total final do dealer: %d\n", dealerTotal);

    *points = calculateBlackjackPoints(difficulty, playerTotal, dealerTotal);

    if (playerTotal == dealerTotal)
    {
        puts("Empate.");
    }
    else if (*points > 0)
    {
        puts("Ganhaste!");
    }
    else
    {
        puts("Perdeste.");
    }

    printf("Pontos ganhos: %lu\n", *points);

    return 0;
}