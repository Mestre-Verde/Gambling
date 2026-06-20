/* A função main é o ponto de entrada do programa.
Aqui é inicializada a semente usada para gerar números aleatórios.
Em seguida, é chamada a função do menu principal, passando-lhe a responsabilidade pela execução do programa.
*/
#include <stdio.h>

#include "main_menu.h"
#include "aux_func.h"
#include <stdlib.h>
#include <time.h>

int main(void)
{
    // Obtém uma semente aleatória que será usada sempre que, em qualquer parte do programa, for chamada a função rand().
    srand(time(NULL));

    // Entra no menu principal.
    if (mainMenu())
    {
        LOG_ERROR("Houve um problema com a função \"mainMenu()\"");
    }
    else
    {
        LOG_INFO("Saiu do Menu principal.");
    }
    return 0;
}
