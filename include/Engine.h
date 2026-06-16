#ifndef GAME_ENGINE
#define GAME_ENGINE

#include "games_menu.h"

typedef enum
{
    UNKNOWN = -1,
    EASY = 1,
    MEDIUM = 2,
    HARD = 3
} Difficulty;

int engineStartGame(GamesMenuOptions game);
Difficulty chooseDifficulty(void);

#endif