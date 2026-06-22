/*
 * player_menu.c
 * Menu responsável por criar, selecionar e remover jogadores.
 * Funções principais:
 * - getPlayerMenuChoice(): apresenta opções e valida a escolha do utilizador
 * - playerMenu(): loop principal do menu de jogador que chama as ações correspondentes
 * Utiliza `jogador.h` e funções utilitárias em `aux_func.h`.
 */

#include <stdio.h>

#include "aux_func.h"
#include "colors.h"

#include "player_menu.h"
#include "jogador.h"

PlayerMenuOption getPlayerMenuChoice(void)
{
    // variaveis
    const char menuText[] =
        TEXT_BOLD COLOR_BRIGHT_CYAN
        "\n===== MENU JOGADOR =====" COLOR_RESET
        "\t|%s|\n" COLOR_RESET COLOR_BRIGHT_WHITE
        "1 - Criar jogador\n"
        "2 - Selecionar jogador\n"
        "3 - Remover jogador\n"
        "0 - Voltar\n" COLOR_RESET;
    int choice = PLAYER_MENU_UNKNOWN;

    // imprimir textMenu e obter a resposta do user.
    printf(menuText, currentPlayer.id == 0 ? "Nenhum" : currentPlayer.nome);
    if (readDigitUserInput("Escolha:", &choice))
    {
        return PLAYER_MENU_UNKNOWN;
    }

    switch (choice)
    {
    case PLAYER_MENU_EXIT:
    case CREATE_PLAYER:
    case CHOOSE_PLAYER:
    case REMOVE_PLAYER:
        return (PlayerMenuOption)choice;
        break;

    default:
        return PLAYER_MENU_UNKNOWN;
        break;
    }
}

int playerMenu(void)
{
    while (1)
    {
        int option = getPlayerMenuChoice();

        switch (option)
        {
        case PLAYER_MENU_UNKNOWN:
            puts(COLOR_GOLD "Opção inválida." COLOR_RESET);
            break;

        case CREATE_PLAYER:
            if (buildPlayer())
            {
                LOG_ERROR("O processo de criar um jogador foi abortado.");
            }
            else
            {
                LOG_INFO("Processo de criação terminado com sucesso!");
            }
            break;

        case CHOOSE_PLAYER:
            if (choosePlayer())
            {
                LOG_ERROR("O processo de seleção do jogador falhou.");
            }
            else
            {
                LOG_INFO("Processo de seleção terminado com sucesso.");
            }
            break;

        case REMOVE_PLAYER:
            if (removePlayer())
            {
                LOG_ERROR("O processo de remoção de jogador falhou.");
            }
            else
            {
                LOG_INFO("Processo de remoção completada com sucesso.");
            }
            break;

        case PLAYER_MENU_EXIT:
            return 0;

        default:
            LOG_WARN("\7Opção fora do escopo,reveja o enum.Valor:%i", option);
            return 1;
        }
    }
}