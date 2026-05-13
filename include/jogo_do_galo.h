#define MAX 3

char tabuleiro[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
short coordenates[2];

const char jogadorX = 'X';
const char jogadorO = 'O';

int jogadorXWinnes = 0;
int jogadorOWinnes = 0;
int noWinnerCount = 0;

char playerTurn;

/**
 * @brief função principal.
 * @return 0 se não houve problemas,1 se have um erro.
 */
_Bool galoMainProcess(void);

_Bool placeChar(char c, short position[2], char M[MAX][MAX]);
void clearMatrix(char M[MAX][MAX]);
void printMatrix2D(char M[MAX][MAX], short int showContent);
char checkWinner();
