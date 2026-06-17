#include <stdio.h>

#include "main_menu.h"
#include "aux_func.h"

int main(void)
{ /*
     LOG_DEBUG("olá.");
     LOG_INFO("olá");
     LOG_ERROR("olá");
     LOG_WARN("olá");*/
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
