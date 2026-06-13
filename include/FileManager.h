#if !defined(FILE_MANAGER)
#define FILE_MANAGER

#include <stdbool.h>

#define PLAYERDB_DIR "base_de_dados/playerdb.bin"
#define TEMP_FILE_PATH "base_de_dados/playerdb.tmp"

/**
 * @brief Verifica o estado de um ficheiro.
 * @details Vai para o final do ficheiro para verficar o tamanho, e depois de obter o tamanho volta ao inicio do ficheiro.
 * @param file ponteiro para o stream.
 * @return 0 se existe e tem conteudo, 1 se não existe, 2 se existe mas não tem conteudo.
 */
int checkDataBase(FILE *file);

/**
 * @brief Guarda um Player na base de dados (ficheiro binário)
 * @param player Estrutura Player a ser guardada
 * @param PATH caminho do ficheiro a guardar.
 * @return 0 em sucesso, 1 em erro
 */
int savePlayerInDataBase(Player player, char PATH[]);

/**
 * @brief Obtém o próximo ID disponível para Player
 * @param nextId apontador onde será guardado o próximo ID
 * @return 0 = sucesso, 1 = erro
 */
int getNextPlayerId(unsigned short int *nextId, char PATH[]);

/**
 * @brief Lista os jogadores de uma base de dados
 * @param withIndex mostra separação com ID
 * @param PATH string com o caminho do path
 * @return 0 se sucesso, 1 se algo não corre bems, -1 se não há jogadores
 */
int listPlayersInDataBase(bool withIndex, char PATH[]);

/**
 * @brief Função para remover um jogador de uma base de dados
 * @details É usado o metudo simples de criar um ficheiro temporario para escrever todos
 * os jogadores menos o a remover e no final substituir a base de dados original pela temporaria.
 * @param id ponteiro para onde está armazenado o id
 * @param PATH caminho da base de dados
 * @return 0 se sucesso, 1 se algo correu mal, -1 se não encontrou o jogador
 */
int removePlayerFromDB(const unsigned short int id, char PATH[]);

#endif // FILE_MANAGER
