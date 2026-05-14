#include <stdio.h>
#include "main_menu.h"

int main(void)
{
    if (mainMenu())
    {
        perror("Houve um problema com a função \"mainMenu\"");
    }
    return 0;
}
