#include <stdio.h>
#include "setup.h"
#include "main_menu.h"
#include "aux_func.h"

int main(void)
{
    if (setup())
    {
        LOG_ERROR("Houve um problema com a função \"setup()\"");
        goto end;
    }
    else
    {
        LOG_INFO("O Setup foi concluído com sucesso!");
    }

    if (mainMenu())
    {
        LOG_ERROR("Houve um problema com a função \"mainMenu()\"");
        goto end;
    }
    else
    {
        LOG_INFO("Saiu do Menu principal.");
    }
end:
    return 0;
}
