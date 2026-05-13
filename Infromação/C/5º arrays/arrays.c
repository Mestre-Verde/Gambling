#include <stdio.h>
//#define MAX = 3
/*
float max(float v[], int n)
{
    int bigNumber = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > bigNumber)
            bigNumber = v[i];
    }
    return bigNumber;
}
void useMaxFunc()
{
    float array[10] = {1.23, 2.1, 3.3454, 4.33, 5.12, 6.57, 8.97, 999.0};

    float maxNumber = max(array, sizeof(array) / sizeof(array[0]));

    printf("O maior valor no array é: %f\n", maxNumber);
}
*/

void print2dMatrix(int MAX, int M[MAX][MAX])
{
    // passa por cada linha
    for (int linha = 0; linha < MAX; linha++)
    {
        //  passa por cada coluna
        for (int coluna = 0; coluna < MAX; coluna++)
        {
            printf("%i ", M[linha][coluna]);
        }
        putchar('\n');
    }
}
// Transposta da matriz
// 1ª coluna passa para 1ª linha
void transpose(int MAX, int M[MAX][MAX])
{
    /*  Base fundamental
        T[0][i] = M[i][0];
        T[1][i] = M[i][1];
        T[2][i] = M[i][2];
    */
    int T[MAX][MAX];

    // loop responsável por incrementar as linhas M[i][]
    for (int linha = 0; linha < MAX; linha++)
    {
        // primeira linha vai ser a coluna da matriz de entrada
        for (int i = 0; i < MAX; i++)
        {
            T[linha][i] = M[i][linha];
        }
    }

    // para cada linha
    print2dMatrix(MAX, T);
}
void callTranspose()
{
    int Matrix[3][3] = {{1, 2, 3},
                        {4, 5, 6},
                        {7, 8, 9}};
    puts("A matriz original:");
    print2dMatrix(3, Matrix);
    puts("A matriz trasnposta:");
    transpose(sizeof(Matrix) / sizeof(Matrix[0]), Matrix);
}

// ou tambem :char * memcpy(char dest[],char *origin,int n)
char * memcpy(char (*dest),char *origin,int n){



    return dest;
}

int main(void)
{
    //callTranspose();
    
    return 0;
}
