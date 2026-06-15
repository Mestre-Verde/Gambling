#include <stdio.h>

#include "main_menu.h"
#include "aux_func.h"

int main(void)
{
    LOG_INFO("Olá amigos");
    LOG_DEBUG("Olá amigos");
    LOG_WARN("Olá amigos");
    LOG_ERROR("Olá amigos");
    goto end;
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
