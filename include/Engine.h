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

/**
 * @brief Função para obter uma dificuldade do user
 * @return Um dificuldade.
 */
Difficulty chooseDifficulty(void);

/**
 * @brief Função para inciar os jogos.
 * @param game Jogo a inicar.
 * @return 0 = sucesso , 1 = erro no galo, 2 = erro no guess, 3 = erro no PPT, 4 = erro no da memória, 5 = erro de enum, 6 erro nos pontos.
 */
int engineStartGame(GamesMenuOptions game);

#endif