#include <stdio.h>
#include <stdbool.h>

#include "include/jogo_do_galo.h"
#include "include/aux_func.h"

void printMatrix2D(char M[MAX][MAX], short int showContent)
{
    for (int linha = 0; linha < MAX; linha++)
    {
        if (showContent)
            createLine(7, '-');
        else
            createLine(13, '-');
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

void clearMatrix(char M[MAX][MAX])
{
    for (short linha = 0; linha < MAX; linha++)
    {
        for (short coluna = 0; coluna < MAX; coluna++)
        {
            M[linha][coluna] = ' ';
        }
    }
}

bool placeChar(char c, short position[2], char M[MAX][MAX])
{
    char caracter = M[position[0]][position[1]];
    if (caracter == ' ' && isBetween(position[0], 0, MAX) && isBetween(position[1], 0, MAX))
    {
        M[position[0]][position[1]] = c;
        return 0;
    }
    else
    {
        return 1;
    }
}

char checkWinner()
{
    short countX = 0;
    short countO = 0;
    for (short i = 0; i < MAX; i++)
    {
        if (tabuleiro[i][i] == 'X')
            countX++;
        else if (tabuleiro[i][i] == 'O')
            countO++;
    }
    if (countX == MAX)
    {
        jogadorXWinnes++;
        return 'X';
    }
    else if (countO == MAX)
    {
        jogadorOWinnes++;
        return 'O';
    }
    else
    {
        countX = countO = 0;
    }
    return 0;
}

char chooseTheFirstPlayer()
{
    puts("Neste jogo há 2 jogadores insira quem vai ser o primeiro,digite \"X\" ou \"O\":");
    char input;
    do
    {
        input = getchar();
    } while (input != 'X' && input != 'O');
    playerTurn = input;
}

bool galoMainProcess(void)
{
    char turnText[] = "Vez de:\"%c\".\nIntroduza a posição da jogada  [linha,coluna]:";

    puts("!!!WELCOME TO THE GAME!!");
    puts("Para sair do jogo deve enviar um unico 'S'.");

    bool exit = 0;
    while (!exit)
    {
        char winner = 0;
        playerTurn = chooseTheFirstPlayer();

        if (toUpper(playerTurn) == 'S')
        {
            exit = 1;
            break;
        }

        do
        {
            printMatrix2D(tabuleiro, 1);
            printMatrix2D(tabuleiro, 0);

            int sucesso = 0;
            do
            {
                printf(turnText, playerTurn);
                scanf(" %hi,%hi", &coordenates[0], &coordenates[1]);

                sucesso = placeChar(playerTurn, coordenates, tabuleiro);
            } while (sucesso);

            if (playerTurn == jogadorX)
            {
                playerTurn = jogadorO;
            }
            else
            {
                playerTurn = jogadorX;
            }
            winner = checkWinner();
        } while (!winner);

        if (winner == 'X' || winner == 'O')
        {
            printf("O jagador \"%c\" ganhou esta partida\n", winner);
        }
        else if (winner == '0')
        {
            puts("Sem vencedor.");
            noWinnerCount++;
        }
        else
        {
            return 1;
        }
    }

    return 0;
}