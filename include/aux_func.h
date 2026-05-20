#ifndef AUX_FUNC_H
#define AUX_FUNC_H

// MACROS--------------

/* INFO */
#define LOG_INFO(msg, ...) \
    printf("[INFO] " msg "\n", ##__VA_ARGS__)

/* DEBUG */
#define LOG_DEBUG(msg, ...)               \
    printf("[DEBUG] [%s():%d] " msg "\n", \
           __func__, __LINE__, ##__VA_ARGS__)

/* WARNING */
#define LOG_WARN(msg, ...)               \
    printf("[WARN] [%s | %s] " msg "\n", \
           __FILE__, __func__, ##__VA_ARGS__)

/* ERROR */
#define LOG_ERROR(msg, ...)                    \
    printf("[ERROR] [%s:%d | %s()] " msg "\n", \
           __FILE__, __LINE__, __func__, ##__VA_ARGS__)

// string print RELATED--------------

/**
 * @brief Imprime uma string caractere a caractere até '\0'.
 *
 * Diferente de puts(), não adiciona automaticamente '\n'.
 * Evita overhead de formatação do printf().
 *
 * @param str String a imprimir
 */
void printString(const char str[]);

/**
 * @brief Imprime um carater em linha e no final dá /n
 * @param n numero de vezes a repetir o caracter
 * @param c o caracter a imprimir 'C'
 */
void createLine(short n, char c);

// Mostra o HEX de uma array
void printHex(int strLen, char str[strLen]);

// INPUT RELATED--------------

/*Limpa a stream de entrada */
void clearStdinTrash(void);

/**
 * @brief Obtem uma input do user.
 * Depois desta função pode se usar um filtro de um enum especifico
 * @param str Texto a apresentar em cada pedido
 * @param var Endereço da variavel para substituir com a entrada valida.
 * @return 0 se sucesso, 1 se houve problemas.
 */
int readDigitUserInput(const char str[], int *var);

// CHAR RELATED--------------

/**
 * @brief  Converte um caracter para maiusculo.
 * @param ch caracter para converter
 * @return o caracter em maiusculo
 */
int toUpper(int ch);

/**
 * @brief  verifica se o caracter é espaço
 * @param ch caracter para comparar
 * @return 1 se é espaço, 0 se não é.
 */
int isSpace(int ch);

/**
 * @brief Procura por um caracter em uma string
 * @param str String para procurar.
 * @param c caracter a procurar.
 * @return Se existir, o index do caracter na string,-1 se não encontrar.
 */
int findCharInStr(char str[], char c);

// MATH RELATED--------------

/**
 * @brief verifica se um valor está dentro de um intervalo.
 * @param value valor a comparar
 * @param min valor minimo
 * @param max valor maximo
 * @return 1 se verdade, 0 se falso
 */
_Bool isBetween(int value, int min_value, int max_value);

#endif
