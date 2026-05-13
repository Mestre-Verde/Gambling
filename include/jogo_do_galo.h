#ifndef JOGO_DO_GALO
#define JOGO_DO_GALO

#define MAX 3

/**
 * @brief função principal.
 * @return 0 se não houve problemas,1 se have um erro.
 */
_Bool galoMainProcess(void);

_Bool placeChar(char c, short position[2], char M[MAX][MAX]);
void clearMatrix(char M[MAX][MAX]);
void printMatrix2D(char M[MAX][MAX], short int showContent);
char checkWinner();
#endif