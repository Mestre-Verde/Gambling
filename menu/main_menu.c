/* Menu principal do programa.
   Permite aceder ao menu de jogos, ao menu de jogador ou terminar a aplicação.
   Aqui é onde se cria a variavel global currentplayer que vai ser usada nos outros ficheiros
*/

// Verifica se o valor introduzido corresponde a uma opção válida do enum.
#include <stdio.h>

#include "aux_func.h"

#include "main_menu.h"
#include "player_menu.h"
#include "games_menu.h"

#include "jogador.h"

Player currentPlayer = {0}; // Variável global que armazena o jogador atualmente selecionado.

MainMenuOption getMainMenuChoice(void)
{
    const char menuText[] =
        TEXT_BOLD COLOR_BRIGHT_CYAN
        "\n===== MENU PRINCIPAL =====" COLOR_RESET
        "\t|%s|\n" COLOR_RESET COLOR_BRIGHT_WHITE
        "1 - Menu de jogos\n"
        "2 - Definições de jogador\n"
        "0 - Sair\n" COLOR_RESET;
    int choice = MENU_UNKNOWN;

    printf(menuText, currentPlayer.id == 0 ? "Nenhum" : currentPlayer.nome);
    if (readDigitUserInput("Escolha: ", &choice))
    {
        // LOG_DEBUG("digito recebido: %i", choice);
        return MENU_UNKNOWN;
    }

    // verifica se há um valor correspondente ao enum.
    switch (choice)
    {
    case MENU_EXIT:
    case MENU_GAMES:
    case MENU_PLAYER:
        return (MainMenuOption)choice;

    default:
        return MENU_UNKNOWN;
    }
}

int mainMenu(void)
{
    while (1)
    {
        MainMenuOption option = getMainMenuChoice();
        // LOG_DEBUG("Valor de Enum recebido: %i", option);
        switch (option)
        {
        case MENU_UNKNOWN:
            puts(COLOR_GOLD "Opção inválida.\n" COLOR_RESET);
            break;

        case MENU_GAMES:
            if (gamesMenu())
            {
                LOG_ERROR("Ocorreu um erro com o menu de jogos.");
            }
            break;

        case MENU_PLAYER:
            if (playerMenu())
            {
                LOG_ERROR("Ocorreu um erro com o menu de jogador.");
            }
            break;

        case MENU_EXIT:
            return 0;

        default:
            LOG_WARN("\7Opção fora do escopo,reveja o enum.Valor:%i", option);
            return 1;
        }
    }
}