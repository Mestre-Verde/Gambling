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
 * Diferente de puts(), não adiciona automaticamente '\\n'.
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

/**
 * @brief Compara 2 strings com lenght
 * @param str1Len tamanho da string 1
 * @param str1 string 1
 * @param str2Len tamanho da string 2
 * @param str2 string 2
 * @return 0 = diferente, 1 = igual
 */
int stringCompareIgnoreCase(int str1Len, const char str1[str1Len], int str2Len, const char str2[str2Len]);

/**
 * @brief Obtem o comprimento da string contando com o caracter nulo '\0'
 * @param s string to get len
 * @return o valor de compriemnto da string.
 */
int stringLen(const char s[]);

#endif // AUX_STRING
