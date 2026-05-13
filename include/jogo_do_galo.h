#ifndef JOGO_DO_GALO
#define JOGO_DO_GALO

#define MAX 3

/**
 * @brief função principal.
 * @return 0 se não houve problemas,1 se have um erro.
 */
_Bool galoMainProcess(void);

/**
 * @brief Imprime no terminal o tabuleiro.
 * @param M coloque aqui o array que pretente mostrar
 * @param showContent 0 para mostrar as coordenadas, 1 para mostrar o conteudo em cada membro do array.
 */
void printMatrix2D(char M[MAX][MAX], short int showContent);

#endif