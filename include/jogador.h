#ifndef JOGADOR
#define JOGADOR

#define MAX_NAME_LENGTH (20 + 1)

typedef struct
{
    unsigned short int id;
    char nome[MAX_NAME_LENGTH];
    unsigned long int pontos_guess;

} Player;

/**
 * @brief Cria um jogador para depois guardar na base de dados.
 * Não é suposto ser escolhido o jogador criado, para escolher o jogador é noutra função.
 * @return 0 se sucesso, 1 se houve um problema.
 */
int buildPlayer(void);

void showPlayerInfo(Player player);

int choosePlayer(void);

int removePlayer(void);

#endif