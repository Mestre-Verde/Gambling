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

    if (mainMenu())
    {
        LOG_ERROR("Houve um problema com a função \"mainMenu()\"");
    }
    return 0;
}
