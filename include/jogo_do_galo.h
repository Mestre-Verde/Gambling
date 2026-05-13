#define MAX 3

char tabuleiro[MAX][MAX] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
short coordenates[2];

const char jogadorX = 'X';
const char jogadorO = 'O';

int jogadorXWinnes = 0;
int jogadorOWinnes = 0;
int noWinnerCount = 0;

char playerTurn;

void chooseTheFirstPlayer();
void createLine(short, char);
_Bool placeChar(char c, short position[2], char M[MAX][MAX]);
void clearMatrix(char M[MAX][MAX]);
void printMatrix2D(char M[MAX][MAX], short int showContent);
char checkWinner();
_Bool galoMainProcess(void);