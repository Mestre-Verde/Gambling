#ifndef MAIN_MENU
#define MAIN_MENU

typedef enum
{
    MENU_UNKNOWN = -1,
    MENU_EXIT = 0,
    MENU_GAMES,
    MENU_PLAYER,
} MainMenuOption;

/**
 * @brief Menu inicial.
 * @return 0 se correu tudo bem, 1 se houve um problema.
 */
signed int mainMenu();

MainMenuOption getMainMenuChoice(void);

#endif