#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H

#include "Engine.h"

#define MIN_CARD 1
#define MAX_CARD 11

#define BLACKJACK_VALUE 21

#define DEALER_STOP_EASY 15
#define DEALER_STOP_MEDIUM 17
#define DEALER_STOP_HARD 18

#define DRAW_POINTS 25

#define BASE_POINTS_EASY 100
#define BASE_POINTS_MEDIUM 150
#define BASE_POINTS_HARD 250

#define BLACKJACK_BONUS_EASY 20
#define BLACKJACK_BONUS_MEDIUM 30
#define BLACKJACK_BONUS_HARD 50

/**
 * @brief Função principal do jogo blackjack.
 * @param difficulty Dificuldade selecionada para a ronda (define comportamento do dealer).
 * @param currentPoints Pontos atuais do jogador.
 * @param points Ponteiro onde serão guardados os pontos obtidos pelo jogador.
 * @return 0 = sucesso, 1 = erro
 */
int blackjack_main_process(Difficulty difficulty, const unsigned long int currentPoints, unsigned long int *points);

#endif