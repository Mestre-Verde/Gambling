#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "jogo_do_galo.h"
#include "aux_func.h"

const char jogadorX = 'X';
const char jogadorO = 'O';

int jogadorXWinnes = 0;
int jogadorOWinnes = 0;
int noWinnerCount = 0;

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
_Bool placeChar(char c, short int tamanho, short position[tamanho], char M[MAX][MAX])
{
    if (!isBetween(position[0], 0, MAX - 1) ||
        !isBetween(position[1], 0, MAX - 1))
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
    char turnText[] = "Vez de: \"%c\".\nIntroduza a posição [linha,coluna] ou 'S' para sair:";

    while (1)
    {
        char buffer[4];
        short int x, y;

        printf(turnText, playerTurn);

        if (!fgets(buffer, sizeof(buffer), stdin))
            continue;

        if (strchr(buffer, '\n') == NULL)
        {
            int c;

            while ((c = getchar()) != '\n' && c != EOF)
                ;
        }
        // saída
        if (toUpper(buffer[0]) == 'S')
            return 'S';

        // validar formato
        if (sscanf(buffer, "%hd,%hd", &x, &y) != 2)
        {
            puts("Input inválido. Usa formato: x,y");
            continue;
        }

        position[0] = x;
        position[1] = y;
        // printf("Coordenadas recebidas:%hi,%hi", position[0], position[1]);

        // tentar jogar
        if (!placeChar(playerTurn, tamanho, position, tabuleiro))
        {
            return 0; // jogada válida feita
        }

        puts("Jogada inválida (posição ocupada ou fora do tabuleiro).");
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
                return 0;
            }
        }
    }
    return 1;
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
    puts("Quem começa: X ou O (ou S para sair)");

    char input;

    while (1)
    {
        input = getchar();

        // ignora ENTER e lixo
        if (input == '\n' || input == ' ' || input == '\t')
            continue;

        input = toUpper(input);

        // limpa o resto da linha (evita bugs no fgets depois)
        while (getchar() != '\n')
            ;

        if (input == 'X' || input == 'O' || input == 'S')
            return input;

        puts("Entrada inválida. Usa X, O ou S.");
    }
}

_Bool galoMainProcess(void)
{

    short int coordenates[2];
    char playerTurn;
    char winner = 0;
    puts("!!!WELCOME TO THE GAME!!");

    while (1)
    {
        // limpa o tabuleiro no inicio de cada ronda.
        char tabuleiro[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

        // inicio do jogo, escolher quem vai ser o primeiro:
        playerTurn = chooseTheFirstPlayer();
        if (playerTurn == 'S')
        {
            return 0;
        }
        // inicia-se o jogo

        // proceso simples, o jogador obtido na parte acima vai ser o primeiro
        // então o primeiro jogador vai mandar as coordenadas
        while (!winner)
        {
            printMatrix2D(tabuleiro, 1);
            printMatrix2D(tabuleiro, 0);
            // manda obter as coordenadas
            if (getCoordenadas(playerTurn, sizeof(coordenates) / sizeof(coordenates[0]), coordenates, tabuleiro) == 'S')
            {
                return 0;
            }

            // verifica se o tabuleiro já está preeenchido:
            if (isFull(tabuleiro))
            {
                winner = 0;
                break;
            }

            // verifica se algum jogador fez 3 seguidos
            winner = checkWinner(tabuleiro);
            if (winner)
            {
                break;
            }

            // troca de jogador no final de 1 jogada.
            playerTurn = (playerTurn == jogadorX) ? jogadorO : jogadorX;
        }
        // ok agora que ou o tabuleiro ficou cheio ou algum teve 3 de uma vez verifica-se
        // qual é que ganheou para incrementar
        if (winner == jogadorO)
        {
            jogadorOWinnes++;
        }
        else if (winner == jogadorX)
        {
            jogadorOWinnes++;
        }
        else
        {
            puts("Empate entre os 2.");
            noWinnerCount++;
            continue;
        }

        printf("O jogador \"%c\"", winner);
    }

    return 0;
}