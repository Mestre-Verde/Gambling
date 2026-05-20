#ifndef GAME_ENGINE
#define GAME_ENGINE

typedef enum
{
    UNKNOWN = -1,
    EASY = 1,
    MEDIUM = 2,
    HARD = 3
} Difficulty;


/**
 * @brief Função para obter a dificuldade que o jogador escolher
 * @return A dificuldade.
 */
Difficulty chooseDifficulty(void);

#endif