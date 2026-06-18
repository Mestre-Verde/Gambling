#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "memory_game.h"
#include "aux_func.h"

static int getSequenceSizeByDifficulty(Difficulty difficulty)
{
    switch (difficulty)
    {
    case EASY:
        return 3;

    case MEDIUM:
        return 5;

    case HARD:
        return 7;

    default:
        return 3;
    }
}

static unsigned long int calculateMemoryPoints(Difficulty difficulty)
{
    switch (difficulty)
    {
    case EASY:
        return 100;

    case MEDIUM:
        return 200;

    case HARD:
        return 350;

    default:
        return 0;
    }
}

int memory_game_main_process(Difficulty difficulty, unsigned long int *points)
{
    int sequenceSize = getSequenceSizeByDifficulty(difficulty);

    int sequence[10];
    int playerSequence[10];

    srand((unsigned int)time(NULL));

    puts("===== MEMORY GAME =====");
    puts("Memoriza a sequencia:");

    for (int i = 0; i < sequenceSize; i++)
    {
        sequence[i] = rand() % 10;
        printf("%d ", sequence[i]);
    }

    putchar('\n');

    puts("\nMemoriza...");

#ifdef _WIN32
    system("timeout /t 3 > nul");
    system("cls");
#else
    system("sleep 3");
    system("clear");
#endif

    puts("===== MEMORY GAME =====");
    puts("Agora escreve a sequencia pela mesma ordem.");

    for (int i = 0; i < sequenceSize; i++)
    {
        printf("Numero %d: ", i + 1);

        if (readDigitUserInput("", &playerSequence[i]))
        {
            puts("Entrada invalida.");
            *points = 0;
            return 0;
        }
    }

    for (int i = 0; i < sequenceSize; i++)
    {
        if (playerSequence[i] != sequence[i])
        {
            puts("Erraste a sequencia.");
            *points = 0;
            return 0;
        }
    }

    puts("Acertaste a sequencia!");

    *points = calculateMemoryPoints(difficulty);

  
    return 0;
}