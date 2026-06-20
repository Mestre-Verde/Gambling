#ifndef MEMORY_GAME_H
#define MEMORY_GAME_H

#include "Engine.h"

/**
 * @brief Processo principal do jogo da memória
 * @param difficulty Dificultade do jogo atual
 * @param currentPoints pontos atuais do jogador.
 * @param points pontos a incrementar
 * @return 0 = sucesso, 1 = erro
 */
int memory_game_main_process(Difficulty difficulty, const unsigned long int currentPoints, unsigned long int *points);

#endif