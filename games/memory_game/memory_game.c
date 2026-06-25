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

/**
 * @brief Calcula os pontos ganhos com base na dificuldade do jogo.
 * @param difficulty dificuldade do jogo (EASY, MEDIUM, HARD)
 * @return Pontos ganhos pelo jogador.
 */
unsigned long int calculateMemoryPoints(Difficulty difficulty) // calcula os pontos ganhos com base na dificuldade do jogo
{
    switch (difficulty)
    {
    case EASY:
        return 50; // Para dificuldade fácil, o jogador ganha 50 pontos.

    case MEDIUM:
        return 100; // Para dificuldade média, o jogador ganha 100 pontos.

    case HARD:
        return 300; // Para dificuldade difícil, o jogador ganha 300 pontos.

    default:     // Se a dificuldade não for reconhecida, retorna 0 pontos.
        return 0;
    }
}

/**
 * @brief Imprime uma sequencia de inteiros em uma linha.
 * @param size Tamanho da sequência.
 * @param sequence Sequancia a imprimir.
 */
void showSequence(const int size, int sequence[]) // função percorre o array e imprime cada elemento, separando-os por espaço; ex: 1 2 3 4 5
{
    for (int i = 0; i < size; i++) // para cada elemento da sequancia, percorre o array 
    {
        printf("%i ", sequence[i]); // imprime cada elemento da sequencia separado por um espaço
    }
}

int memory_game_main_process(Difficulty difficulty, const unsigned long int currentPoints, unsigned long int *points)
{
    // define o tamanho da sequência com base na dificuldade: fácil = 3, médio = 5, difícil = 7; ex : dificuldade fácil -> 1 + (1*2) = 3; dificuldade média -> 1 + (2*2) = 5; dificuldade difícil -> 1 + (3*2) = 7
    const int sequenceSize = 1 + ((int)difficulty * 2); // enum Difficulty: EASY = 1, MEDIUM = 2, HARD = 3; então sequenceSize = 1 + (dificuldade * 2) -> fácil = 3, médio = 5, difícil = 7

    // Array que vao armazenar a sequência aleatória gerada pelo computador e a sequência digitada pelo jogador e depois comparadas entre si
    int randonSequence[sequenceSize]; // array para armazenar a sequência aleatória gerada pelo computador
    int playerSequence[sequenceSize]; // array para armazenar a sequência digitada pelo jogador

    for (int i = 0; i < sequenceSize; i++) // gera a sequência aleatória de números entre 0 e 9, e armazena no array randonSequence
    {
        randonSequence[i] = rand() % 10; // aqui gera um número aleatório entre 0 e 9, e armazena no array randonSequence
    }

    puts("===== MEMORY GAME =====");
    printString("Memoriza a sequência:");
    delay(1); //espera 1 segundo
    // mostra a sequência gerada pelo computador ao jogador, que o jogador deve memorizar
    showSequence(sequenceSize, randonSequence);
    fflush(stdout);// força a imprimir a sequência no terminal, pois este espera por um '\n' que não tem, visto que precisa de ser tudo em uma linha
    delay(3);//  espera 3 segundos e apaga a sequencia da consola
    printf(CLEAR_LINE);// limpa a linha com a sequência, para que o jogador não veja mais a sequência e tenha que memorizar

    puts("Agora escreve a sequencia pela mesma ordem. Um número de cada vez.");

    for (int i = 0; i < sequenceSize; i++) // para cada elemento da sequência, pede ao jogador para digitar o número correspondente, e armazena no array playerSequence ex : se a sequência gerada pelo computador for 1 2 3, o jogador deve digitar 1, depois 2, depois 3, e cada número digitado é armazenado no array playerSequence
    {
        int state = 0; // variável para armazenar o estado da leitura do input do jogador, 0 = sucesso, 1 = erro, -1 = input inválido

        while (1) // enquanto o jogador não digitar um número válido, continua a pedir para digitar o número correspondente, só aceita números entre 0 e 9, e -1 para desistir do jogo
        {
            printf("Numero %d", i + 1);

            state = readDigitUserInput("(-1 para sair):", &playerSequence[i]); // lê o input do jogador, e armazena no array playerSequence, e retorna o estado da leitura do input do jogador, 0 = sucesso, 1 = erro, -1 = input inválido

            // LOG_DEBUG("Valor do estado: %i | Valor recebido: %i\n", state, playerSequence[i]);

            if (state == 1) // se houve um erro na leitura do input, retorna 1 para indicar falha
            {
                return 1;
            }

            if (state == -1) // emtrada invalida, o jogador digitor ex letras entre outra coisas 
            {
                printString(COLOR_GOLD "Opção inválida.\n" COLOR_RESET);
                continue;
            }

            if (playerSequence[i] == -1)  // se o jogador digita -1, o jogo termina 
            {
                LOG_INFO("Jogo abortado.");
                return 0;
            }
            break; // se o jogador digitou um número válido, sai do loop e passa para o próximo número da sequência
        }
    }

    for (int i = 0; i < sequenceSize; i++)  // compara a sequência digitada pelo jogador com a sequência gerada pelo computador, se algum número estiver errado, o jogador perde e o jogo termina
    {
        if (playerSequence[i] != randonSequence[i]) // se algum numero for diferente, o jogador errou a sequência, e o jogo termina
        {
            printString("\n" BG_MAGENTA COLOR_BLACK "Erraste a sequência." COLOR_RESET "\n");
            printString("A sequencia correta era:");
            showSequence(sequenceSize, randonSequence);
            putchar('\n');
            return 0;
        }
    }

    *points = calculateMemoryPoints(difficulty); // se o jogador acertou a sequência, calcula os pontos ganhos com base na dificuldade do jogo, e armazena na variável points, que é um ponteiro para a variável que vai guardar os pontos ganhos nesta partida

    createLine(50, '*');
    puts(TEXT_BOLD COLOR_BRIGHT_GREEN "Acertaste a sequência!" COLOR_RESET);

    printf("Pontos ganhos : " COLOR_BRIGHT_GREEN "%lu\n" COLOR_RESET, *points);
    printf("Pontos atuais : " COLOR_BRIGHT_CYAN "%lu\n", currentPoints);
    printf("               + %lu\n", *points);
    createLine(21, '-');
    printf(TEXT_BOLD "Pontos totais : " COLOR_GOLD "%lu\n" COLOR_RESET, currentPoints + *points);

    createLine(50, '*');
    delay(2);

    return 0;
}
