#include <stdio.h>
#include "setup.h"
#include "main_menu.h"
#include "aux_func.h"

void printCharTable(void)
{
    printf("Char   | Dec | Hex\n");
    printf("-------------------\n");

    for (int i = 0; i < 128; i++)
    {
        switch (i)
        {
        case '\0':
            printf("\\0     | %3d | %02X\n", i, i);
            break;
        case '\a':
            printf("\\a     | %3d | %02X\n", i, i);
            break;
        case '\b':
            printf("\\b     | %3d | %02X\n", i, i);
            break;
        case '\t':
            printf("\\t     | %3d | %02X\n", i, i);
            break;
        case '\n':
            printf("\\n     | %3d | %02X\n", i, i);
            break;
        case '\v':
            printf("\\v     | %3d | %02X\n", i, i);
            break;
        case '\f':
            printf("\\f     | %3d | %02X\n", i, i);
            break;
        case '\r':
            printf("\\r     | %3d | %02X\n", i, i);
            break;

        default:
            if (i >= 32 && i <= 126)
                printf("'%c'    | %3d | %02X\n", i, i, i);
            else
                printf("CTRL   | %3d | %02X\n", i, i);
        }
    }
}

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
