/*
Este jogo não tem logica de jogador pois para isso necessitaria de logica
para ter 2 jogadores ativos o que não vai acontecer.

De resto, este ficheiro é o jogo do galo normal.
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "jogo_do_galo.h"
#include "aux_func.h"

#define MAX 3

const char jogadorX = 'X';
const char jogadorO = 'O';

int jogadorXWinnes = 0;
int jogadorOWinnes = 0;
int noWinnerCount = 0;

void printPlayCounts(void)
{
    createLine('#', 30);
    printf("Vitórias do jogador X: %i\n", jogadorXWinnes);
    printf("Vitórias do jogador O: %i\n", jogadorOWinnes);
    printf("Empates: %i\n", noWinnerCount);
    createLine('#', 30);
}

/**
 * @brief Imprime no terminal o tabuleiro.
 * @param M coloque aqui o array que pretente mostrar
 * @param showContent 0 para mostrar as coordenadas, 1 para mostrar o conteudo em cada membro do array.
 */
void printMatrix2D(char M[MAX][MAX], short int showContent)
{
    for (int linha = 0; linha < MAX; linha++)
    {
        if (showContent)
        {
            createLine(7, '-');
        }
        else
        {
            createLine(13, '-');
        }
        putchar('|');
        for (int coluna = 0; coluna < MAX; coluna++)
        {
            if (showContent)
                printf("%c|", M[linha][coluna]);
            else
                printf("%i,%i|", linha, coluna);
        }
        putchar('\n');
    }

    if (showContent)
    {
        createLine(7, '-');
    }
    else
    {
        createLine(13, '-');
    }
}

/**
 * @brief Coloca um caracter no tabuleiro.
 * @param c caracter a colocar
 * @param tamanho tamanho e position
 * @param position array com as coordenadas
 * @param M matriz do tabuleiro
 * @return 0 se colocou com sucesso, 1 se não conseguiu
 */
int placeChar(char c, short int tamanho, short position[tamanho], char M[MAX][MAX])
{
    if (!isBetween(position[0], 0, MAX - 1) || !isBetween(position[1], 0, MAX - 1))
    {
        return 1;
    }

    if (M[position[0]][position[1]] != ' ')
    {
        return 1;
    }

    M[position[0]][position[1]] = c;

    return 0;
}

char getCoordenadas(char playerTurn, short int tamanho, short int position[tamanho], char tabuleiro[MAX][MAX])
{
    // só é aceitavel (x,y\n\0)
    const int MAX_BUFFER_LEN = (4 + 1);

    while (1)
    {
        // Informa de quem é o turno
        LOG_INFO("Vez de: \"%c\".", playerTurn);

        // obtem a imput do user
        char buffer[MAX_BUFFER_LEN];
        int state = readStrUserInput("Introduza a posição [linha,coluna] ou 'S' para sair", MAX_BUFFER_LEN, buffer, 1, "0123456789,sS");
        if (state == 1)
        {
            return 1;
        }

        // verifica se é para sair
        if (toUpper(buffer[0]) == 'S')
            return 'S';

        // validar formato
        if (sscanf(buffer, "%hi,%hi", &position[0], &position[1]) != 2)
        {
            LOG_INFO("Input inválido. Usa formato: x,y .");
            continue;
        }

        // LOG_DEBUG("Coordenadas recebidas:%hi,%hi", position[0], position[1]);

        // tentar jogar
        if (!placeChar(playerTurn, tamanho, position, tabuleiro))
        {
            putchar('\n');
            return 0; // jogada válida feita
        }

        LOG_INFO("Jogada inválida (posição ocupada ou fora do tabuleiro).");
    }
}

_Bool isFull(char M[MAX][MAX])
{

    for (short linha = 0; linha < MAX; linha++)
    {
        for (short coluna = 0; coluna < MAX; coluna++)
        {
            if (isSpace(M[linha][coluna]))
            {
                return false;
            }
        }
    }
    return true;
}

char checkWinner(char tabuleiro[MAX][MAX])
{
    // linhas
    for (int i = 0; i < MAX; i++)
    {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
        {
            return tabuleiro[i][0];
        }
    }

    // colunas
    for (int i = 0; i < MAX; i++)
    {
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
        {
            return tabuleiro[0][i];
        }
    }

    // diagonal principal
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
    {
        return tabuleiro[0][0];
    }

    // diagonal secundária
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
    {
        return tabuleiro[0][2];
    }

    return 0;
}

/**
 * @brief Lê uma entrada correpsondente a "X","O","S"
 * @return Um dos 3 caracteres.
 */
char chooseTheFirstPlayer()
{
    const char promptText[] = "Quem começa: X ou O (ou S para sair)";
    // formato (char\n\0);
    const int MAX_BUFFER_LEN = (2 + 1);
    while (1)
    {
        char buffer[MAX_BUFFER_LEN];

        // obtem input do user
        if (readStrUserInput(promptText, MAX_BUFFER_LEN, buffer, 1, "XxOoSs"))
        {
            LOG_INFO("Entrada inválida.");
            continue;
        }

        // ora vamos ter em mãos um unico char.
        return toUpper(buffer[0]);
    }
}

int galoMainProcess(void)
{
    puts("!!!WELCOME TO THE GAME!!");

    while (1)
    {
        // limpa o tabuleiro no inicio de cada ronda.
        char tabuleiro[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

        // Escolha de quem vai ser o primeiro.
        char playerTurn = chooseTheFirstPlayer();
        if (playerTurn == 'S')
        {
            return 0;
        }
        // inicia-se o jogo

        // proceso simples, o jogador obtido na parte acima vai ser o primeiro
        // então o primeiro jogador vai mandar as coordenadas
        // nisso vai-se alternando entre jogador até um ganhar.
        short int coordenadas[2] = {-1, -1};
        char winner = '\0';
        while (!winner)
        {
            printMatrix2D(tabuleiro, 1);
            printMatrix2D(tabuleiro, 0);

            // manda obter as coordenadas
            char coordState = getCoordenadas(playerTurn, sizeof(coordenadas) / sizeof(coordenadas[0]), coordenadas, tabuleiro);
            if (coordState == 'S')
            {
                return 0;
            }
            else if (coordState == 1)
            {
                return 1;
            }

            // verifica se algum jogador fez 3 seguidos
            winner = checkWinner(tabuleiro);

            // verifica se o tabuleiro já está preeenchido
            if (isFull(tabuleiro))
            {
                break;
            }

            // troca de jogador no final de 1 jogada.
            playerTurn = (playerTurn == jogadorX) ? jogadorO : jogadorX;
        }
        // ok agora que ou o tabuleiro ficou cheio ou algum teve 3 de uma vez verifica-se
        // qual é que ganhou para incrementar
        if (winner == jogadorO)
        {
            jogadorOWinnes++;
        }
        else if (winner == jogadorX)
        {
            jogadorXWinnes++;
        }
        else
        {
            noWinnerCount++;
            printPlayCounts();
            continue;
        }

        createLine(33, '!');
        printf("!!!O jogador \"%c\" ganhou o jogo!!!\n", winner);
        createLine(33, '!');
        printPlayCounts();
    }
}