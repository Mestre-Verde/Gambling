#ifndef AUX_STRING
#define AUX_STRING



/**
 * @brief Copia uma string para outra
 * @param inicial string a copiar
 * @param final destino a colar
 */
void stringCopy(const char inicial[], char final[]);

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
 * @brief Imprime uma string na forma decimal
 * Esta é somente para debug.A tool
 * @param strLen até onde converter .
 * @param str string a converter.
 */
void printHex(int strLen, char str[strLen]);

/**
 * @brief Procura por um caracter em uma string
 * @param str String para procurar.
 * @param c caracter a procurar.
 * @return Se existir, o index do caracter na string, -1 se não encontrar.
 */
int findCharInStr(char str[], char c);

#endif // AUX_STRING
