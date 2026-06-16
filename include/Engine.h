#ifndef GAME_ENGINE
#define GAME_ENGINE

#include "games_menu.h"

typedef enum
{
    DIFFICULTY_UNKNOWN = -1,
    DIFFICULTY_EXIT = 0,
    EASY = 1,
    MEDIUM = 2,
    HARD = 3
} Difficulty;

Difficulty chooseDifficulty(void);

int engineStartGame(GamesMenuOptions game);

#endif