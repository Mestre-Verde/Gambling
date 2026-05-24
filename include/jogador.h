#ifndef JOGADOR
#define JOGADOR

#define MAX_NAME_LENGTH 20 + 1
typedef struct
{
    unsigned short int id;
    char nome[MAX_NAME_LENGTH];
    // password
    unsigned int vitórias_galo;
    unsigned int derrotas_galo;
    unsigned long int pontos_guess;

} Player;

void showPlayerInfo(Player);

int choosePlayer(void);

int buildPlayer(void);

int removePlayer(void);

void playerStats(Player p);

#endif