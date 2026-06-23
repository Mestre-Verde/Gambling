#ifndef PEDRA_PAPEL_TESOURA_H   
#define PEDRA_PAPEL_TESOURA_H

#include "Engine.h"

#define MAX_VICTORIES 3

#define BASE_POINTS_EASY 100
#define BASE_POINTS_MEDIUM 150
#define BASE_POINTS_HARD 250

/**
 * @brief Função principal do jogo blackjack.
 * @param difficulty Dificuldade selecionada para a ronda (define comportamento do dealer).
 * @param currentPoints Pontos atuais do jogador.
 * @param points Ponteiro onde serão guardados os pontos obtidos pelo jogador.
 * @return 0 = sucesso, 1 = erro
 */
int main_process_pedra_papel_tesoura(const unsigned long int currentPoints, unsigned long int *points);

#endif