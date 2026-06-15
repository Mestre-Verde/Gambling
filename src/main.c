#include <stdio.h>

#include "main_menu.h"
#include "aux_func.h"

int main(void)
{
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
