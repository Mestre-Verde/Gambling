/*
 * memory_game.c
 * Implementação do Memory Game (jogo da memória).
 * Responsabilidades:
 * - Gerar e mostrar sequência aleatória
 * - Ler sequência do jogador e verificar correspondência
 * - Calcular pontos em função da dificuldade
 * Funções principais: `memory_game_main_process`, `calculateMemoryPoints`.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "memory_game.h"
#include "aux_func.h"
#include "aux_string.h"

unsigned long int calculateMemoryPoints(Difficulty difficulty)
{
    switch (difficulty)
    {
    case EASY:
        return 50;

    case MEDIUM:
        return 100;

    case HARD:
        return 300;

    default:
        return 0;
    }
}

int memory_game_main_process(Difficulty difficulty, const unsigned long int currentPoints, unsigned long int *points)
{
    // Variavel para armazenar o valor de len da string
    const int sequenceSize = 1 + ((int)difficulty * 2); // 3 -> 5 -> 7 -> 9

    // variaveis para guardar as sequencias
    int randonSequence[sequenceSize];
    int playerSequence[sequenceSize];

    for (int i = 0; i < sequenceSize; i++)
    {
        randonSequence[i] = rand() % 10;
    }

    puts("===== MEMORY GAME =====");
    printf("Memoriza a sequência:");
    delay(1);
    for (short i = 0; i < sequenceSize; i++)
    {
        printf("%i ", randonSequence[i]);
    }
    // obriga a imprimir a sequencia no terminal, pois este espera por um '\n' que não tem, visto que precisa de ser tudo em uma linha
    fflush(stdout);
    //  espera 3 segundos e apaga a sequencia da consola
    delay(3);
    // limpa a linha com a sequência
    printf(CLEAR_LINE);
    puts("Agora escreve a sequencia pela mesma ordem. Um número de cada vez.");

    for (int i = 0; i < sequenceSize; i++)
    {
        int state = 0;

        while (1)
        {
            printf("Numero %d", i + 1);

            state = readDigitUserInput("(-1 para sair):", &playerSequence[i]);

            // LOG_DEBUG("Valor do estado: %i | Valor recebido: %i\n", state, playerSequence[i]);

            if (state == 1)
            {
                return 1;
            }

            if (state == -1)
            {
                LOG_INFO("Entrada invalida.");
                continue;
            }

            if (playerSequence[i] == -1)
            {
                LOG_INFO("Jogo abortado.");
                return 0;
            }
            break;
        }
    }

    for (int i = 0; i < sequenceSize; i++)
    {
        if (playerSequence[i] != randonSequence[i])
        {
            LOG_INFO("Erraste a sequência.");
            return 0;
        }
    }

    LOG_INFO("Acertaste a sequencia!");

    *points = calculateMemoryPoints(difficulty);

    createLine(50, '*');
    printf("Pontos ganhos: %lu\n", *points);
    printf("Pontos atuais: %lu  +\n", currentPoints);
    createLine(21, '-');
    printf("Pontos totais: %lu\n", currentPoints + *points);

    return 0;
}