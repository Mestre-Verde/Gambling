#ifndef AUX_FUNC_H
#define AUX_FUNC_H

// MACROS--------------

#define LOG_INFO(msg, ...) printf("[INFO] " msg "\n", ##__VA_ARGS__)

#define LOG_DEBUG(msg, ...)               \
    printf("[DEBUG] [%s():%d] " msg "\n", \
           __func__, __LINE__, ##__VA_ARGS__)

#define LOG_WARN(msg, ...)               \
    printf("[WARN] [%s | %s] " msg "\n", \
           __FILE__, __func__, ##__VA_ARGS__)

#define LOG_ERROR(msg, ...)                    \
    printf("[ERROR] [%s:%d | %s()] " msg "\n", \
           __FILE__, __LINE__, __func__, ##__VA_ARGS__)

// string RELATED--------------

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

/**
 * @brief Procura por um caracter em uma string
 * @param str String para procurar.
 * @param c caracter a procurar.
 * @return Se existir, o index do caracter na string, -1 se não encontrar.
 */
int findCharInStr(char str[], char c);

// INPUT RELATED--------------

/*Limpa a stream de entrada */
void clearStdinTrash(void);

/**
 * @brief Generic function to ask integers to the user.
 * @param prompt Text to show before the user input
 * @param var pointer to the var that will save the input
 * @return 0 if all fine, 1 if something whent wrong
 */
int readDigitUserInput(const char prompt[], int *var);

/**
 * @brief Função generalizada para receber inputs do tipo string com filtro.
 * @param prompt Texto de prompt
 * @param varSize Tamanho da var.
 * @param var ponteiro a apontar para a variavel que vai armazenar o valor
 * @param useFilter 1 se vai ter caracteres aceitaveis, 0 se não vai ter
 * @param allowedChars string com os caracteres aceitaveis
 * @return 0 if all fine, 1 if something whent wrong
 */
int readStrUserInput(const char prompt[], const size_t varSize, char var[varSize], bool useFilter, const char allowedChars[]);

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

// MATH RELATED--------------

/**
 * @brief verifica se um valor está dentro de um intervalo.
 * @param value valor a comparar
 * @param min valor minimo
 * @param max valor maximo
 * @return true if inside the interval, false if not inside
 */
bool isBetween(int value, int min_value, int max_value);

#endif
