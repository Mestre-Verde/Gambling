#ifndef AUX_FUNC_H
#define AUX_FUNC_H

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

/**
 * @brief verifica se um valor está dentro de um intervalo.
 * @param value valor a comparar
 * @param min valor minimo
 * @param max valor maximo
 * @return 1 se verdade, 0 se falso
 */
_Bool isBetween(int value, int min_value, int max_value);

/**
 * @brief Imprime um carater em linha e no final dá /n
 * @param n numero de vezes a repetir o caracter
 * @param c o caracter a imprimir 'C'
 */
void createLine(short n, char c);

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

#endif
