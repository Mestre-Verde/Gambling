
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "pedra_papel_tesoura.h"
#include "jogador.h"
#include "aux_func.h"
#include "Engine.h"
#include "aux_string.h"
#define MAXBUFFER_LEN 68 // define o tamanho max da respota do array ( no caso 67 mais 1 para o \0 (fim da string))

typedef enum
{

    PEDRA = 0,
    PAPEL = 1,
    TESOURA = 2,

} PedraPapelTesouraOption;

int main_process_pedra_papel_tesoura(const unsigned long int currentPoints, unsigned long int *points)
{

    int vitorias_jogador = 0;
    int vitorias_computador = 0;

    while (vitorias_jogador < MAX_VICTORIES && vitorias_computador < MAX_VICTORIES)
    {
        char resposta[MAXBUFFER_LEN] = {0}; // buffer onde fica guardada a resposta do utilizador  ['p' 'e' 'd' 'r' 'a' '\0']

        int result_random = rand() % 3; // Gera a escolha aleatoria do computador: 0 = PEDRA, 1 = PAPEL, 2 = TESOURA

        printString("Escolhe Pedra, Papel ou Tesoura\n"); // Mostra uma mensagem ao utilizador

        int estado = readStrUserInput("Resposta", MAXBUFFER_LEN, resposta, 0, "");
        // "Resposta" -> texto mostrado ao utilizador
        // MAXBUFFER_LEN -> tamanho máximo do buffer
        // resposta -> buffer onde fica guardado o texto escrito
        // 0 -> não usa filtro de caracteres se for !=0 (diferente de 0 logo é igual a erro)
        // "" -> sem caracteres permitidos porque o filtro está desligado

        // if (estado == 0) logo a respota foi lida com sucesso e passa para as condições

        if (estado != 0)
        {
            puts("Erro ao ler a respota"); // Se estado for diferente de 0, houve erro na leitura da resposta.
                                           // Então mostra mensagem de erro e sai da função com return 1.
            return 1;
        }

        // Condições
        PedraPapelTesouraOption escolha_utilizador;
        PedraPapelTesouraOption escolha_computador = (PedraPapelTesouraOption)result_random;

        if (stringCompareIgnoreCase(resposta, "pedra") == 0)
        {
            escolha_utilizador = PEDRA;
        }
        else if (stringCompareIgnoreCase(resposta, "papel") == 0)
        {
            escolha_utilizador = PAPEL;
        }
        else if (stringCompareIgnoreCase(resposta, "tesoura") == 0)
        {
            escolha_utilizador = TESOURA;
        }
        else
        {
            puts("Escolha inválida. Por favor, escolha Pedra, Papel ou Tesoura.");
            return 1; // Escolha inválida
        }

        printString("O computador escolheu: ");
        switch (escolha_computador)
        {
        case PEDRA:
            printString("Pedra\n");
            break;
        case PAPEL:
            printString("Papel\n");
            break;
        case TESOURA:
            printString("Tesoura\n");
            break;
        }

        // Condições para determinar o vencedor
        if (escolha_utilizador == escolha_computador)
        {
            printString("Empate!\n");
            *points = 0; // Nenhum ponto ganho
        }
        else if ((escolha_utilizador == PEDRA && escolha_computador == TESOURA) ||
                 (escolha_utilizador == PAPEL && escolha_computador == PEDRA) ||
                 (escolha_utilizador == TESOURA && escolha_computador == PAPEL))
        {
            printString("Ganhaste a ronda!\n");

            vitorias_jogador++;
            *points = BASE_POINTS_EASY; // Pontos ganhos pelo jogador
        }
        else
        {
            printString("O computador ganhou a ronda!\n");

            vitorias_computador++;
        }

        printf("Resultados: Jogador %d / Computador %d", vitorias_jogador, vitorias_computador);
        printf("\nPontos ganhos nesta ronda: %lu\n", *points);
    }
    if (vitorias_jogador == MAX_VICTORIES)
    {
        printf("Ganhaste a melhor de 5\n");
    }
    else
    {
        printf("O computador ganhou a melhor de 5\n");
    }
    printf("Total de pontos ganhos: %lu\n", *points);
    return 0; // Sucesso
}