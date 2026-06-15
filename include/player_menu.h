#ifndef PLAYER_MENU
#define PLAYER_MENU

typedef enum
{
    PLAYER_MENU_UNKNOWN = -1,
    PLAYER_MENU_EXIT = 0,
    CREATE_PLAYER,
    CHOOSE_PLAYER,
    REMOVE_PLAYER,
} PlayerMenuOption;

/**
 * @brief Menu do jogador
 * @return 0 se correu tudo bem, 1 se houve algum problema
 */
signed int playerMenu(void);

PlayerMenuOption getPlayerMenuChoice(void);

#endif