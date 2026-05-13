#include <stdio.h>
#include "jogo_do_galo.h"
#include "guess_game.h"

int main(void)
{
    if (!galoMainProcess())
    {
        puts("Ocorreu um erro com o jogo do galo.");
    }

    if (!guess_main_processo())
    {
        puts("Ocorreu um erro com o jogo de adivinhação.");
    }


    puts("ola duarte");
    return 0;
}
