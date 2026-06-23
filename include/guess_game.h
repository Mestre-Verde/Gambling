#ifndef GUESS_GAME_H
#define GUESS_GAME_H

#include "Engine.h"

/**
 * @brief Função principal do jogo
 * @param difficulty dificuldade do jogo
 * @param currentPoints pontos do jogador atual
 * @param points ponteiro para a variavelq eu vai guardar os pontos
 * @return 0 = sucesso ; 1 = erro
 */
signed int guess_main_process(const Difficulty difficulty, const unsigned long int currentPoints, unsigned long int *points);

#endif
