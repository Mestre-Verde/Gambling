#ifndef JOGADOR
#define JOGADOR

#define MAX_NAME_LENGTH (20 + 1)

typedef struct
{
    unsigned short int id;
    char nome[MAX_NAME_LENGTH];
    unsigned long int pontos_guess;

} Player;

// permite partilhar a variavel pelos outros ficheiros
extern Player currentPlayer;

/**
 * @brief Cria um jogador para depois guardar na base de dados.
 * Não é suposto ser escolhido o jogador criado, para escolher o jogador é noutra função.
 * @return 0 se sucesso, 1 se houve um problema.
 */
int buildPlayer(void);

/**
 * @brief Imprime os valores de um Player
 * @param player jogador a imprimir.
 * @param wihLine 1 para mostar o separador, 0 para não mostrar.
 */
void showPlayerInfo(Player player, bool withLine);

/**
 * @brief Função para escolher o jogador atual.
 * @return
 */
int choosePlayer(void);

/**
 * @brief Função para escolher um jogador para remover.
 * @return 0 se removeu com sucesso, 1 se ocorreu um erro
 */
int removePlayer(void);

#endif