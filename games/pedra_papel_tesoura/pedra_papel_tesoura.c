
#include <stdio.h>   // Biblioteca usada para printf() e puts()
#include <stdbool.h> // Biblioteca usada para bool, true e false
#include <stdlib.h>  // Biblioteca usada para rand() e srand()
#include <time.h>    // Biblioteca usada para time(), para gerar numeros aleatorios diferentes

#include "pedra_papel_tesoura.h" // Header deste jogo. Tem MAX_VICTORIES e os pontos base
#include "aux_func.h"            // Header com funcoes auxiliares, como readStrUserInput()
#include "aux_string.h"          // Header com funcoes de strings, como printString() e stringCompareIgnoreCase()
#include "colors.h"              // Header com as cores usadas no terminal

#define MAX_VICTORIES 3

#define BASE_POINTS 50

#define RPS_MAX_LEN (7 + 1)

#define MAXBUFFER_LEN (67 + 1) // Tamanho maximo da resposta: 67 caracteres + 1 para o '\0'

PedraPapelTesouraOption getBotChoice()
{
    // Gera a escolha aleatoria do computador.
    int botRandomValue = rand() % 3; // rand() % 3 so pode dar 0, 1 ou 2.

    return (PedraPapelTesouraOption)botRandomValue; // Converte o numero aleatorio do computador para o enum.
}

int main_process_pedra_papel_tesoura(const unsigned long int currentPoints, unsigned long int *points)
{
    const char RPS[][RPS_MAX_LEN] = {"Pedra", "Papel", "Tesoura"};

    int correntRound = 1; // contador de rondas

    int playerWins = 0; // Contador das vitorias do jogador. Comeca em 0 porque no inicio ninguem ganhou nenhuma ronda.
    int botWins = 0;    // Contador das vitorias do computador.

    // Titulo do jogo com cor.
    printString(TEXT_BOLD COLOR_BRIGHT_CYAN "\n===== PEDRA, PAPEL E TESOURA =====\n" COLOR_RESET);

    // Explicacao do jogo incial.
    printf(COLOR_YELLOW "Melhor de %i: quem chegar primeiro a %d vitorias ganha.\n" COLOR_RESET, MAX_VICTORIES + 2, MAX_VICTORIES);
    delay(2);

    // O ciclo continua enquanto nenhum dos dois chegou ao numero maximo de vitorias.
    // MAX_VICTORIES deve estar definido no ficheiro .h como 3.
    // Como e uma melhor de 5, quem chegar primeiro a 3 vitorias ganha.
    while (playerWins < MAX_VICTORIES && botWins < MAX_VICTORIES)
    {
        const char RPS_MENU_TEXT[] =
            COLOR_BRIGHT_WHITE "Escolhe " COLOR_RESET COLOR_GRAY_SOFT "Pedra(%i)" COLOR_RESET COLOR_BRIGHT_WHITE ", " COLOR_RESET COLOR_YELLOW "Papel(%i)" COLOR_RESET COLOR_BRIGHT_WHITE " ou " COLOR_RESET COLOR_PURPLE_SOFT "Tesoura(%i).\n" COLOR_RESET;

        printf(TEXT_BOLD COLOR_SKY_BLUE "\n--- %dª RONDA ---\n" COLOR_RESET, correntRound); // Mostra o inicio de uma nova ronda.

        printf(RPS_MENU_TEXT, (int)PEDRA, (int)PAPEL, (int)TESOURA);

        // Mostra ao jogador o que deve escrever.
        // Buffer onde fica guardada a resposta escrita pelo utilizador.
        char playerInput[MAXBUFFER_LEN] = {0}; // Exemplo da palavra "pedra" em memoria:['p', 'e', 'd', 'r', 'a', '\0']

        PedraPapelTesouraOption escolha_utilizador; // Variavel que vai guardar a escolha do utilizador convertida para enum.

        // obtem uma entrada e válida
        bool isValid = false;
        while (!isValid)
        {
            // obtem a entrada do user (string valida)
            int estado = 0;
            do
            {
                estado = readStrUserInput("Insira aqui a sua escolha", MAXBUFFER_LEN, playerInput, false, "");
                switch (estado)
                {
                case -1: // invalida se for só enter.
                    puts(COLOR_BRIGHT_RED "Entrada inválida;" COLOR_RESET);
                    continue;

                case 0: // tem uma string valida
                    break;

                case 1: // erro
                    return 1;

                default:
                    LOG_WARN("Estado desconhecido de readStrUserInput!. Valor:%i.", estado);
                    return 1;
                }

            } while (estado);
            // chega um a string aprovada
            // temos de verificar se string ==(ignore case)playerInput!LITERAL!, ou é igual ao valor de enum

            int inputLen = stringLen(playerInput);
            // filtra a string
            if (stringCompareIgnoreCase(inputLen, playerInput, stringLen(RPS[0]), RPS[0]) || stringCompareIgnoreCase(inputLen, playerInput, 2, "0"))
            {
                escolha_utilizador = PEDRA;
            }
            else if (stringCompareIgnoreCase(inputLen, playerInput, stringLen(RPS[1]), RPS[1]) || stringCompareIgnoreCase(inputLen, playerInput, 2, "1"))
            {
                escolha_utilizador = PAPEL;
            }
            else if (stringCompareIgnoreCase(inputLen, playerInput, stringLen(RPS[2]), RPS[2]) || stringCompareIgnoreCase(inputLen, playerInput, 2, "2"))
            {
                escolha_utilizador = TESOURA;
            }
            else
            {
                puts(COLOR_BRIGHT_RED "Entrada inválida;" COLOR_RESET);
                continue;
            }
            isValid = true;
        }
        // mostra resumo da ronda
        PedraPapelTesouraOption botChoice = getBotChoice();
        printString("\nJogador\t\t|\tComputador\n");
        printf("%s\t\tvs\t%s\n", RPS[(int)escolha_utilizador], RPS[(int)botChoice]);

        // Primeiro verifica se houve empate.
        if (escolha_utilizador == botChoice)
        {
            printString(COLOR_BRIGHT_YELLOW "Empate!\n" COLOR_RESET);
        }
        else if ((escolha_utilizador == PEDRA && botChoice == TESOURA) ||
                 (escolha_utilizador == PAPEL && botChoice == PEDRA) ||
                 (escolha_utilizador == TESOURA && botChoice == PAPEL)) // Aqui estao as tres situacoes em que o jogador ganha:
        {
            printString(COLOR_BRIGHT_GREEN "\nGanhaste a ronda!\n" COLOR_RESET);
            // Aumenta 1 vitoria ao jogador.
            playerWins++;

            // Soma pontos ao total desta partida.
            *points += BASE_POINTS; // Usa += porque os pontos devem acumular.
        }
        else // Se nao foi empate e o jogador nao ganhou, entao o computador ganhou a ronda.
        {
            printString(COLOR_BRIGHT_RED "\nO computador ganhou a ronda!\n" COLOR_RESET);

            // Aumenta 1 vitoria ao computador.
            botWins++;
        }
        correntRound++;
        // Mostra o resultado atual da melhor de 5.
        printf(TEXT_BOLD "Resultado: " COLOR_RESET);
        printf(COLOR_BRIGHT_GREEN "Jogador %d" COLOR_RESET, playerWins);
        printf(COLOR_WHITE " / " COLOR_RESET);
        printf(COLOR_BRIGHT_RED "Computador %d\n" COLOR_RESET, botWins);

        // Mostra os pontos acumulados nesta partida.
        printf(COLOR_GOLD "Pontos atuais neste jogo: %lu\n" COLOR_RESET, *points);
    }

    // Quando o while acaba, significa que alguem chegou a MAX_VICTORIES.
    // Se foi o jogador, ele ganhou a melhor de 5.
    if (playerWins == MAX_VICTORIES)
    {
        LOG_INFO("\nGanhaste a melhor de %i!\n", MAX_VICTORIES + 2);

        // Bonus final por ganhar a partida completa.
        *points += BASE_POINTS;
    }
    else // o computador que ganhou.
    {
        // Se o jogador nao chegou a MAX_VICTORIES,
        // entao foi
        LOG_INFO("\nPerdeste a melhor de %i!\n", MAX_VICTORIES + 2);
    }

    // Mostra o total de pontos ganhos nesta execucao do jogo.
    printf(TEXT_BOLD COLOR_GOLD "Total de pontos ganhos: %lu\n" COLOR_RESET, *points);

    return 0; // retorna sucesso
}
