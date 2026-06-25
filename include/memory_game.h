#ifndef MEMORY_GAME_H
#define MEMORY_GAME_H

#include "Engine.h"

/**
 * @brief Função principal do Memory Game. Que gera uma sequência aleatória, mostra ao jogador, lê a sequência do jogador e verifica se está correta.
 * @param difficulty dificuldade do jogo (EASY, MEDIUM, HARD)
 * @param currentPoints pontos atuais do jogador
 * @param points ponteiro para a variável que armazenará os pontos ganhos nesta partida
 * @return 0 = sucesso ; 1 = erro
 */
int memory_game_main_process(Difficulty difficulty, const unsigned long int currentPoints, unsigned long int *points);

#endif