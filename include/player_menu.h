#ifndef PLAYER_MENU
#define PLAYER_MENU

typedef enum
{
    PLAYER_MENU_UNKNOWN = -1,
    PLAYER_MENU_EXIT = 0,
    CHOOSE_PLAYER,
    CREATE_PLAYER,
    REMOVE_PLAYER,
    PLAYER_STATS
} PlayerMenuOption;

/**
 * @brief Menu para jogador
 * @return 0 se correu tudo bem, 1 se houve algum problema
 */
signed int playerMenu(void);

PlayerMenuOption getPlayerMenuChoice(void);

#endif