#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "blackjack_game.h"
#include "jogador.h"
#include "aux_func.h"
#include "Engine.h"

/**
 * @brief Gera uma carta aleatória.
 *
 * Gera e devolve o valor de uma carta compreendido entre
 * MIN_CARD e MAX_CARD (inclusive).
 *
 * @return Valor da carta gerada aleatoriamente.
 */
int drawCard(void)
{
    return rand() % (MAX_CARD - MIN_CARD + 1) + MIN_CARD;
}

/**
 * @brief Obtém o valor mínimo a partir do qual o dealer deixa de pedir cartas.
 * @param difficulty Dificuldade atual do jogo.
 * @return Valor mínimo para o dealer parar de comprar cartas.
 */
int getDealerStopValueByDifficulty(Difficulty difficulty)
{
    switch (difficulty)
    {
    case EASY:
        return DEALER_STOP_EASY;

    case MEDIUM:
        return DEALER_STOP_MEDIUM;

    case HARD:
        return DEALER_STOP_HARD;

    default:
        return 1;
    }
}

/**
 * @brief Calcula os pontos obtidos no Blackjack.
 * @details A pontuação depende da dificuldade selecionada e do resultado da partida.
 * O jogador não recebe pontos se ultrapassar 21 ou perder contra o dealer.
 * Em caso de empate é atribuída uma pontuação fixa e um Blackjack (21 pontos)
 * concede um bónus adicional.
 *
 * @param difficulty Dificuldade atual do jogo.
 * @param playerTotal Valor final da mão do jogador.
 * @param dealerTotal Valor final da mão do dealer.
 * @return Pontos a adicionar ao jogador.
 */
unsigned long int calculateBlackjackPoints(Difficulty difficulty, int playerTotal, int dealerTotal)
{
    unsigned long int basePoints;
    unsigned long int bonusPoints;

    if (playerTotal > BLACKJACK_VALUE || (dealerTotal <= BLACKJACK_VALUE && dealerTotal > playerTotal))
    {
        return 0;
    }

    if (playerTotal == dealerTotal)
    {
        return DRAW_POINTS;
    }

    switch (difficulty)
    {
    case EASY:
        basePoints = BASE_POINTS_EASY;
        bonusPoints = BLACKJACK_BONUS_EASY;
        break;

    case MEDIUM:
        basePoints = BASE_POINTS_MEDIUM;
        bonusPoints = BLACKJACK_BONUS_MEDIUM;
        break;

    case HARD:
        basePoints = BASE_POINTS_HARD;
        bonusPoints = BLACKJACK_BONUS_HARD;
        break;

    default:
        return 1; // Dificuldade não tratada.
    }

    return (playerTotal == BLACKJACK_VALUE) ? basePoints + bonusPoints : basePoints;
}

int blackjack_main_process(Difficulty difficulty, unsigned long int *points)
{

    int dealerStopValue = getDealerStopValueByDifficulty(difficulty);

    int playerTotal = drawCard() + drawCard();
    int dealerTotal = drawCard() + drawCard();

    puts("\nBem vindo ao Blackjack!");
    printf("O teu valor inicial é: %d\n", playerTotal);
    printf("O valor inicial do dealer é: %d\n", dealerTotal);

    while (playerTotal < BLACKJACK_VALUE)
    {
        LOG_DEBUG("dealerstopValue: %i|playertotal: %i|dealerTotal: %i|", dealerStopValue, playerTotal, dealerTotal);
        int choice;

        puts("\nEscolhe uma opção:");
        puts("1 - Pedir carta");
        puts("2 - Parar");

        if (readDigitUserInput("Escolha: ", &choice))
        {
            puts("Opção inválida.");
            continue;
        }
        LOG_DEBUG("Jogador escolheu: %d", choice);

        if (choice == 1)
        {
            int card = drawCard();
            playerTotal += card;

            printf("Carta recebida: %d\n", card);
            printf("Total atual: %d\n", playerTotal);
            if (playerTotal > BLACKJACK_VALUE)
            {
                LOG_DEBUG("Jogador rebentou | total=%d", playerTotal);
                break;
            }
        }
        else if (choice == 2)
        {
            LOG_DEBUG("Jogador decidiu parar | total=%d", playerTotal);
            break;
        }
        else
        {
            puts("Opção inválida.");
        }
    }

    if (playerTotal > BLACKJACK_VALUE)
    {
        puts("\nPassaste de 21. Perdeste.");
        *points = 0;
        return 0;
    }

    puts("\nVez do dealer...");
    // delay para parecer que o dealer está a fazer uam jogada
    for (size_t i = 0; i < 4000000000; i++)
        ;

    LOG_DEBUG("Dealer inicia jogada | total=%d | stop=%d",
              dealerTotal, dealerStopValue);

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