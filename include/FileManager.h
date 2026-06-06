#if !defined(FILE_MANAGER)
#define FILE_MANAGER

/**
 * @brief Guarda um Player na base de dados (ficheiro binário)
 * @param player Estrutura Player a ser guardada
 * @return 0 em sucesso, 1 em erro
 */
int savePlayerInDataBase(Player player);

/**
 * @brief Obtém o próximo ID disponível para Player
 * @param nextId apontador onde será guardado o próximo ID
 * @return 0 = sucesso, 1 = erro
 */
int getNextPlayerId(unsigned short int *nextId);

int listPlayersInDataBase(bool withIndex);
#endif // FILE_MANAGER
