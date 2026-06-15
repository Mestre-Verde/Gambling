#if !defined(GAME_MENU)
#define GAME_MENU

typedef enum
{
    GAMES_MENU_UNKNOWN = -1,
    GAMES_MENU_EXIT = 0,
    JOGO_DO_GALO,
    GUESS_GAME,
    GAME3,
    GAME4,
} GamesMenuOptions;

/**
 * @brief Menu dos jogos
 * @return 0 se sucesso,1 se ocurreu um erro
 */
signed int gamesMenu(void);

#endif // GAME_MENU
