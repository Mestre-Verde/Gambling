#ifndef AUX_FUNC_H
#define AUX_FUNC_H
/**
 * @brief verifica se um valor está dentro de um intervalo.
 * @param value valor a comparar
 * @param min valor minimo
 * @param max valor maximo
 * @return 1 se verdade, 0 se falso
 */
bool isBetween(int value, int min_value, int max_value);

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
