#include <stdio.h>
#include "setup.h"
#include "main_menu.h"
#include "aux_func.h"

int main(void)
{
    if (setup())
    {
        LOG_ERROR("Houve um problema com a função \"setup()\"");
    }
    else
    {
        LOG_INFO("O Setup foi concluído com sucesso!");
    }

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
