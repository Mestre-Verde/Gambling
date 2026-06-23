#ifndef PEDRA_PAPEL_TESOURA_H   
#define PEDRA_PAPEL_TESOURA_H

#include "Engine.h"

// Enum usado para representar as tres escolhas possiveis do jogo.
// Em vez de usar numeros soltos no codigo, usamos nomes mais faceis de perceber.
typedef enum
{
    PEDRA = 0,  // PEDRA fica associada ao valor 0
    PAPEL = 1,  // PAPEL fica associado ao valor 1
    TESOURA = 2 // TESOURA fica associada ao valor 2

} PedraPapelTesouraOption;

/**
 * @brief Funcao principal do jogo Pedra, Papel e Tesoura.
 * @param currentPoints pontos atuais do jogador neste jogo.
 * @param points ponteiro onde vao ser guardados os pontos ganhos nesta partida.
 * @return 0 = sucesso, 1 = erro
 */
int main_process_pedra_papel_tesoura(const unsigned long int currentPoints, unsigned long int *points);

#endif