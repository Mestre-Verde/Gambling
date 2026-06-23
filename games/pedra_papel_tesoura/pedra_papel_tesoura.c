
#include <stdio.h>   // Biblioteca usada para printf() e puts()
#include <stdbool.h> // Biblioteca usada para bool, true e false
#include <stdlib.h>  // Biblioteca usada para rand() e srand()
#include <time.h>    // Biblioteca usada para time(), para gerar numeros aleatorios diferentes

#include "pedra_papel_tesoura.h" // Header deste jogo. Tem MAX_VICTORIES e os pontos base
#include "aux_func.h"            // Header com funcoes auxiliares, como readStrUserInput()
#include "aux_string.h"          // Header com funcoes de strings, como printString() e stringCompareIgnoreCase()
#include "colors.h"              // Header com as cores usadas no terminal

#define MAX_VICTORIES 3

#define BASE_POINTS_EASY 100
#define BASE_POINTS_MEDIUM 150
#define BASE_POINTS_HARD 250

#define MAXBUFFER_LEN (67 + 1) // Tamanho maximo da resposta: 67 caracteres + 1 para o '\0'

int main_process_pedra_papel_tesoura(const unsigned long int currentPoints, unsigned long int *points)
{
    // variavel do numero de ronda
    int n_ronda_atual = 1;

    // Contador das vitorias do jogador.
    // Comeca em 0 porque no inicio ninguem ganhou nenhuma ronda.
    int vitorias_jogador = 0;

    // Contador das vitorias do computador.
    // Tambem comeca em 0.
    int vitorias_computador = 0;

    // Titulo do jogo com cor.
    printString(TEXT_BOLD COLOR_BRIGHT_CYAN "\n===== PEDRA, PAPEL E TESOURA =====\n" COLOR_RESET);

    // Explicacao inicial da regra da melhor de 3.
    printf(COLOR_YELLOW "Melhor de %i: quem chegar primeiro a %d vitorias ganha.\n" COLOR_RESET, MAX_VICTORIES, MAX_VICTORIES);

    // O ciclo continua enquanto nenhum dos dois chegou ao numero maximo de vitorias.
    // MAX_VICTORIES deve estar definido no ficheiro .h como 3.
    // Como e uma melhor de 5, quem chegar primeiro a 3 vitorias ganha.
    while (vitorias_jogador < MAX_VICTORIES && vitorias_computador < MAX_VICTORIES)
    {
        const char RPS_MENU_TEXT[] =
            COLOR_BRIGHT_WHITE "Escolhe " COLOR_RESET COLOR_GRAY_SOFT "Pedra" COLOR_RESET COLOR_BRIGHT_WHITE ", " COLOR_RESET COLOR_YELLOW "Papel" COLOR_RESET COLOR_BRIGHT_WHITE " ou " COLOR_RESET COLOR_PURPLE_SOFT "Tesoura\n" COLOR_RESET;
        // Buffer onde fica guardada a resposta escrita pelo utilizador.
        // Exemplo da palavra "pedra" em memoria:
        // ['p', 'e', 'd', 'r', 'a', '\0']
        char resposta[MAXBUFFER_LEN] = {0};

        // Gera a escolha aleatoria do computador.
        // rand() % 3 so pode dar 0, 1 ou 2.
        // 0 = PEDRA, 1 = PAPEL, 2 = TESOURA.
        int result_random = rand() % 3;

        // Mostra o inicio de uma nova ronda.
        printf(TEXT_BOLD COLOR_SKY_BLUE "\n--- %dª RONDA ---\n" COLOR_RESET, n_ronda_atual);

        // Mostra ao jogador o que deve escrever.
        printString(RPS_MENU_TEXT);

        int estado = 0;
        do
        {
            // Le a resposta do utilizador.
            //
            // "Resposta"    -> texto mostrado antes do input
            // MAXBUFFER_LEN -> tamanho maximo do buffer
            // resposta      -> buffer onde a resposta vai ser guardada
            // false         -> nao usa filtro de caracteres
            // ""            -> lista de caracteres permitidos vazia porque o filtro esta desligado
            int estado = readStrUserInput("Resposta", MAXBUFFER_LEN, resposta, false, "");
            switch (estado)
            {
            case -1:
                puts(COLOR_BRIGHT_RED "Entrada inválida;" COLOR_RESET);
                break;

            case 0:
                break;

            case 1:
                return 1;

            default:
                LOG_WARN("Estado desconhecido de readStrUserInput!. Valor:%i.", estado);
                return 1;
            }
        } while (estado);

        // Variavel que vai guardar a escolha do utilizador ja convertida para enum.
        PedraPapelTesouraOption escolha_utilizador;

        // Converte o numero aleatorio do computador para o enum.
        // Exemplo:
        // se result_random for 0, escolha_computador fica PEDRA.
        // se result_random for 1, escolha_computador fica PAPEL.
        // se result_random for 2, escolha_computador fica TESOURA.
        PedraPapelTesouraOption escolha_computador = (PedraPapelTesouraOption)result_random;

        // Compara a resposta do utilizador com "PEDRA", ignorando maiusculas e minusculas.
        // Assim aceita "pedra", "Pedra", "PEDRA", etc.
        if (stringCompareIgnoreCase(resposta, "PEDRA") == 0)
        {
            escolha_utilizador = PEDRA;
        }
        else if (stringCompareIgnoreCase(resposta, "PAPEL") == 0)
        {
            escolha_utilizador = PAPEL;
        }
        else if (stringCompareIgnoreCase(resposta, "TESOURA") == 0)
        {
            escolha_utilizador = TESOURA;
        }
        else
        {
            // Se nao for pedra, papel ou tesoura, a escolha e invalida.
            puts(COLOR_BRIGHT_RED "Escolha invalida. Escolhe Pedra, Papel ou Tesoura." COLOR_RESET);
            return 1; // retorna erro
        }

        // Mostra qual foi a escolha do computador.
        printString(COLOR_CYAN "O computador escolheu: " COLOR_RESET);

        // Usa switch para imprimir o nome da escolha do computador com cor diferente.
        switch (escolha_computador)
        {
        case PEDRA:
            printString(COLOR_GRAY_SOFT "Pedra\n" COLOR_RESET);
            break;

        case PAPEL:
            printString(COLOR_YELLOW "Papel\n" COLOR_RESET);
            break;

        case TESOURA:
            printString(COLOR_PURPLE_SOFT "Tesoura\n" COLOR_RESET);
            break;
        }

        // Primeiro verifica se houve empate.
        // Se as duas escolhas forem iguais, ninguem ganha a ronda.
        if (escolha_utilizador == escolha_computador)
        {
            printString(COLOR_BRIGHT_YELLOW "Empate!\n" COLOR_RESET);
            n_ronda_atual++;
        }

        // Aqui estao as tres situacoes em que o jogador ganha:
        //
        // PEDRA ganha a TESOURA
        // PAPEL ganha a PEDRA
        // TESOURA ganha a PAPEL
        else if ((escolha_utilizador == PEDRA && escolha_computador == TESOURA) ||
                 (escolha_utilizador == PAPEL && escolha_computador == PEDRA) ||
                 (escolha_utilizador == TESOURA && escolha_computador == PAPEL))
        {
            printString(COLOR_BRIGHT_GREEN "Ganhaste a ronda!\n" COLOR_RESET);

            // Aumenta 1 vitoria ao jogador.
            vitorias_jogador++;

            n_ronda_atual++;

            // Soma pontos ao total desta partida.
            // Usa += porque os pontos devem acumular.
            *points += BASE_POINTS_EASY;
        }

        // Se nao foi empate e o jogador nao ganhou,
        // entao o computador ganhou a ronda.
        else
        {
            printString(COLOR_BRIGHT_RED "O computador ganhou a ronda!\n" COLOR_RESET);

            // Aumenta 1 vitoria ao computador.
            vitorias_computador++;
            n_ronda_atual++;
        }

        // Mostra o resultado atual da melhor de 5.
        printf(TEXT_BOLD "Resultado: " COLOR_RESET);
        printf(COLOR_BRIGHT_GREEN "Jogador %d" COLOR_RESET, vitorias_jogador);
        printf(COLOR_WHITE " / " COLOR_RESET);
        printf(COLOR_BRIGHT_RED "Computador %d\n" COLOR_RESET, vitorias_computador);

        // Mostra os pontos acumulados nesta partida.
        printf(COLOR_GOLD "Pontos atuais neste jogo: %lu\n" COLOR_RESET, *points);
    }

    // Quando o while acaba, significa que alguem chegou a MAX_VICTORIES.
    // Se foi o jogador, ele ganhou a melhor de 5.
    if (vitorias_jogador == MAX_VICTORIES)
    {
        printString(TEXT_BOLD COLOR_BRIGHT_GREEN "\nGanhaste a melhor de 5!\n" COLOR_RESET);

        // Bonus final por ganhar a partida completa.
        *points += BASE_POINTS_HARD;
    }
    else
    {
        // Se o jogador nao chegou a MAX_VICTORIES,
        // entao foi o computador que ganhou.
        printString(TEXT_BOLD COLOR_BRIGHT_RED "\nO computador ganhou a melhor de 5!\n" COLOR_RESET);
    }

    // Mostra o total de pontos ganhos nesta execucao do jogo.
    printf(TEXT_BOLD COLOR_GOLD "Total de pontos ganhos: %lu\n" COLOR_RESET, *points);

    return 0; // retorna sucesso
}
