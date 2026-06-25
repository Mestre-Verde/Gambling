/*
Este jogo não tem logica de jogador pois para isso necessitaria de logica
para ter 2 jogadores ativos o que não vai acontecer.

De resto, este ficheiro é o jogo do galo normal.
*/
#include <stdio.h>
#include <stdbool.h>

#include "jogo_do_galo.h"
#include "aux_func.h"
#include "colors.h"

#define MAX 3 // define o tamanho do tabuleiro como 3x3

const char jogadorX = 'X'; // define o caracter do jogador X
const char jogadorO = 'O'; // define o caracter do jogador O

// contadores globais para guardar o hitorico de vitórias de cada jogador e o número de empates
int jogadorXWinnes = 0; //  vitorias do jogador X
int jogadorOWinnes = 0; // vitorias do jogador O
int noWinnerCount = 0; // empates

void printPlayCounts(void) // função que imprime no terminal o número de vitórias de cada jogador e o número de empates no final do jogo
{
    createLine('#', 30);
    printf(BG_BLUE COLOR_BRIGHT_WHITE " Vitórias do jogador X " COLOR_RESET " %i", jogadorXWinnes);
    putchar('\n');

    printf(BG_MAGENTA COLOR_BRIGHT_WHITE " Vitórias do jogador O " COLOR_RESET " %i", jogadorOWinnes);
    putchar('\n');

    printf(BG_YELLOW COLOR_BLACK " Empates " COLOR_RESET " %i", noWinnerCount);
    putchar('\n');
    createLine('#', 30);
}

/**
 * @brief Imprime no terminal o tabuleiro.
 * @param M coloque aqui o array que pretente mostrar
 * @param showContent 0 para mostrar as coordenadas, 1 para mostrar o conteudo em cada membro do array.
 */
void printMatrix2D(char M[MAX][MAX], short int showContent) // função que imprime o tabuleiro, ShowContent = 0 -> mostra as coordenadas, ShowContent = 1 -> mostra o conteudo do tabuleiro(x ou o)
{
    for (int linha = 0; linha < MAX; linha++) // este for percorre as linhas do tabuleiro, e para cada linha, percorre as colunas, imprimindo o conteúdo de cada célula do tabuleiro. como MAX = 3, vai percorrer as linhas 0, 1 , 2 e para cada linha, vai percorrer as colunas 0, 1, 2, imprimindo o conteúdo de cada célula do tabuleiro.
    {
        if (showContent)
        {
            createLine(7, '-'); // ex : 7 vezes o caracter '-' -> -------
        }
        else
        {
            createLine(13, '-'); // ex : 13 vezes o caracter '-' -> -------------
        }
        putchar('|'); // separador vertical 

        for (int coluna = 0; coluna < MAX; coluna++) // este for percorre percorre as linhas do tabuleiro, lovo vai percorrer 3 colunas
        {
            if (showContent)
                printf("%c|", M[linha][coluna]); // se o showContent for 1 mostra o conteudo da matriz (tabuleiro) com 'X'/'Y'; 
            else
                printf("%i,%i|", linha, coluna);// se o showContent for 0 mostra as coordenadas; ex: 1,2  para o jogador saber onde pode jogar 
        }
        putchar('\n'); // passa para a linha seguinte depois de imprimir tudo(linhas/colunas) 
    }

    if (showContent) // depois de imprimir tudo, imprime a linha separadora central 
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
int placeChar(char c, short int tamanho, short position[tamanho], char M[MAX][MAX]) // antes de colocar o caracter ( X OU Y ), verifica se estão detro do tabuleiro e se a posição ainda está vazia 
{
    if (!isBetween(position[0], 0, MAX - 1) || !isBetween(position[1], 0, MAX - 1)) // como MAX = 3, logo só tem receber linha -> 0, 1, 2 / colunas -> 0, 1, 2, ou seja verifica se está dentro do tabuleiro   
    {
        return 1;                                                                  // position[0] representa a linha e position[1] representa a coluna 
    }

    if (M[position[0]][position[1]] != ' ')   // verifica se a posição está vazia 
    {
        return 1;
    }

    M[position[0]][position[1]] = c; // coloca o caracter ( X OU Y )

    return 0;
}

char getCoordenadas(char playerTurn, short int tamanho, short int position[tamanho], char tabuleiro[MAX][MAX]) // função responsável por pedir as coordenadas ao jogador atual aonde quer jogar 
{
    // só é aceitavel (x,y\n\0)
    const int MAX_BUFFER_LEN = (4 + 1); // input esperado tem no máximo caracteres; '1' ',' '2' '\n' '\0'

    while (1) // ciclo repete até que o jogador atual insira uma jogada válida 
    {
        // Informa de quem é o turno
        LOG_INFO("Vez de: \"%c\".", playerTurn);

        // obtem a imput do user
        char buffer[MAX_BUFFER_LEN]; // ex: se o jogador escrever 1,2 fica guardado "1,2" no buffer 
        int state = readStrUserInput("Introduza a posição [linha,coluna] ou 'S' para sair", MAX_BUFFER_LEN, buffer, 1, "0123456789,sS"); // texto mostrado ao utilizadotor, tamanho maximo do buffer(5), onde fica guardado o texto escrito, ativa o filtro de caracteres, só permite /numeros /vírgulas/ s ou S 
        if (state == 1) // se for 1, houve um erro então a função termina e devolve 1
        {
            return 1;
        }

        // verifica se é para sair
        if (toUpper(buffer[0]) == 'S')
            return 'S';

        // validar formato
        if (sscanf(buffer, "%hi,%hi", &position[0], &position[1]) != 2) // tenta ler os 2 numeros separados por 1 virgula
        {
            LOG_INFO("Input inválido. Usa formato: x,y .");
            continue;
        }

        // LOG_DEBUG("Coordenadas recebidas:%hi,%hi", position[0], position[1]);

        // tentar jogar
        if (!placeChar(playerTurn, tamanho, position, tabuleiro)) // a função placeChar(X ou Y) verifica se a posição está dentro do tabuleiro e se está vazia 
        {
            putchar('\n');
            return 0; // jogada válida feita
        }

        LOG_INFO("Jogada inválida (posição ocupada ou fora do tabuleiro).");
    }
}

_Bool isFull(char M[MAX][MAX]) // função para ver se o tabuleiro está cheio, ou seja o 1 for verifica as linhas, o 2 for verifica as colunas, se encontrar alguma posição vazia, devolve false( ainda da para jogar). Se estiver tudo cheio = empate 
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

char checkWinner(char tabuleiro[MAX][MAX]) // função que verifa se algum jogador fez 3 caracteres seguidos 
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
char chooseTheFirstPlayer() // função para ver quem começa a jogar primeiro 
{
    const char promptText[] = "Quem começa: X ou O (ou S para sair)";
    // formato (char\n\0);
    const int MAX_BUFFER_LEN = (2 + 1);// tamanho maximo buffer, só aceita X, O ou S  
    while (1)// ciclo repete até que o utilizador insira um entrada válida 
    {
        char buffer[MAX_BUFFER_LEN];

        // obtem input do user
        if (readStrUserInput(promptText, MAX_BUFFER_LEN, buffer, 1, "XxOoSs"))
        {
            LOG_INFO("Entrada inválida.");
            continue;
        }

        // ora vamos ter em mãos um unico char.
        return toUpper(buffer[0]); // converte para maiusculas o 'x' 'O' 's'
    }
}

int galoMainProcess(void)
{
    puts("\n!!!WELCOME TO THE GAME!!");

    while (1) // quando a partida acaba, o programa volta ao inicio deste ciclo e começa uma nova partida com o tabuleiro limpo 
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

        // processo simples, o jogador obtido na parte acima vai ser o primeiro
        // então o primeiro jogador vai mandar as coordenadas
        // nisso vai-se alternando entre jogador até um ganhar.
        short int coordenadas[2] = {-1, -1}; // array usado para guardar as coordenadas da jogada. Começa com -1 porque ainda não foi escolhida nehuma posição 
        char winner = '\0'; // variável que guarda o vencedor da partida. Começa com \0 pq ainda não existe vencedor, se alguem ganhar vai ter 'X' OU 'O'

        while (!winner) // enquanto não existe vencedor continua  
        {
            printMatrix2D(tabuleiro, 1); // mostra o tabuleiro com os X OU O
            printMatrix2D(tabuleiro, 0); // mostra o tabuleiro das coordenadas 

            // manda obter as coordenadas e tenta colocar a jogada no tabuleiro 
            char coordState = getCoordenadas(playerTurn, sizeof(coordenadas) / sizeof(coordenadas[0]), coordenadas, tabuleiro);
            if (coordState == 'S')// se o jogador escrever s, termina o jogo 
            {
                return 0;
            }
            else if (coordState == 1) // se o coorState for 1, ocorreu algum erro 
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

            // troca de jogador no final da jogada.
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
        // Resumo do que aconteceu na partida 
        printf(COLOR_BRIGHT_RED);
        createLine(35, '!');
        printf(COLOR_RESET);

        printf(TEXT_BOLD COLOR_BRIGHT_GREEN "!!! O jogador \"%c\" ganhou o jogo !!!" COLOR_RESET "\n", winner);

        printf(COLOR_BRIGHT_RED);
        createLine(35, '!');
        printf(COLOR_RESET);
        printPlayCounts();
    }
}
