#include <stdio.h>
#include "aux_func.h"

typedef struct
{
    char nome[20 + 1];
    unsigned int vitórias_galo;
    unsigned int derrotas_galo;
    unsigned long int pontos_guess;

} Player;

void showPlayerInfo(Player p)
{
    printf("Nome do jogador:%s", p.nome);
    printf("Nº de vitórias no jogo do Galo: %u\n", p.vitórias_galo);
    printf("Nº de derrotas no jogo do Galo: %u\n", p.derrotas_galo);
    printf("Pontos no jogo da Adivinha: %lu\n", p.pontos_guess);
}