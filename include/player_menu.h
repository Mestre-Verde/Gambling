#ifndef PLAYER_MENU
#define PLAYER_MENU

typedef enum
{
    PLAYER_MENU_UNKNOWN = -1,
    PLAYER_MENU_EXIT = 0,
    CREATE_PLAYER = 1,
    CHOOSE_PLAYER = 2,
    REMOVE_PLAYER = 3,
    PLAYER_STATS = 4
} PlayerMenuOption;

/**
 * @brief Menu para jogador
 * @return 0 se correu tudo bem, 1 se houve algum problema
 */
signed int playerMenu(void);

PlayerMenuOption getPlayerMenuChoice(void);

#endif