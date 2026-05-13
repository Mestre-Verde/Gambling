#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int Abs(int x) {
  return x < 0 ? x *= -1 : x;
}

float getVAL(float x, int n, float t) {
  // VAL = x/(1+t)^n + ...
  float VAL = 0.0f;

  for (unsigned int term = 1; term <= n; term++) {
    printf("Termo nº: %u .\v Valor atual de VAL: %f .\n", term, VAL);
    float denominador = 1;  // 1* denominador = denominador | random number * denominador = imprevisibilidade;
    for (unsigned int n_factor = 0; n_factor < term; n_factor++) {
      printf("No fator: %i ,Valor do denominado: %f\n", n_factor, denominador);
      denominador *= (1 + t);  // (1+x)^n = (1+x)*(1+x)*...repete n vezes
    }

    VAL += x / denominador;
    printf("%f / %f = %f\v VAL right now = %f\n", x, denominador, x / denominador, VAL);
    putchar('\n');
  }
  return VAL;
}

void exitWithState(int anyProblem) {
  anyProblem ? exit(EXIT_FAILURE) : exit(EXIT_SUCCESS);
}

long int n_segundos(int h_horas) {
  return h_horas * 3600;
}

/**
 * @param type to what i will convert [h(hour);m(minuts);s(secunds)]
 */
long int hourToMinOrSec(int h_horas, char type) {
  switch (type) {
    case 'h': return h_horas;

    case 'm': return h_horas * 60;

    case 's': return h_horas * 3600;

    default: return 0;
  }
}

void repeatCharInLine(short n_times, char caracter) {
  for (size_t i = 0; i < n_times; i++) {
    putchar(caracter);
  }
  putchar('\n');
  return;
}

float max3(float x, float y, float z) {
  if (x > y && x > z)
    return x;

  else if (y > z)
    return y;

  else
    return z;
}

int isImpar(int valor) {
  return valor % 2;
}

int isBetween(int min_value, int value, int max_value) {
  return min_value <= value && value <= max_value;
}

int isDigit(int ch) {
  return '0' <= ch && ch <= '9';
}

int isAlpha(int ch) {
  return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int isAlnum(int ch) {
  return ('0' <= ch && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

int isLower(int ch) {
  return (ch >= 'a' && ch <= 'z');
}
int isUpper(int ch) {
  return (ch >= 'A' && ch <= 'Z');
}
int isSpace(int ch) {
  return ch == 32;
}
int toLower(int ch) {
  if (isUpper(ch)) return ch + 32;
}

int toUpper(int ch) {
  if (isLower(ch)) return ch - 32;
}

unsigned long long countBitCombinations(int bits) {
  return 1ULL << bits;
}

int isSquare(int x, int y) {
  return x == (y * y);
}
int Minus(int x) {
  return x < 0 ? x : -x;
}

int isSpecial(int x) {
  return (2 * x == x * x);
}

int Cubo(int x) {
  return x * x * x;
}
int isVowell(char ch) {
  // a,A,e,E,i,I,o,O,u,U
  return (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U');
}

int Inverso(int x) {
  return x == 0 ? x : (1 / x);
}

void Triangulo(int n) {
  for (int linha = 1; linha < n + 1; linha++) {
    for (int i = 0; i < n - linha; i++) {
      putchar(' ');
    }
    for (int i = 0; i < linha; i++) {
      putchar('*');
    }
    putchar('\n');
  }
}

int main(void) {
  /*
      int a = 8, b = -100, c = -22222, d = 0;
      printf("Módulos dos valores:\n|%i| = %i\n|%i| = %i\n|%i| = %i\n|%i| = %i\n", a, Abs(a), b, Abs(b), c, Abs(c), d, Abs(d));

     repeatCharInLine(40, '-');

         float x, t;
         int n;
         puts("insira valores no respetivo formato:\"float int float\"");
         scanf(" %f %i %f", &x, &n, &t);
         float VAL = getVAL(x, n, t);
         printf("O resultado de VAL é : %f\n", VAL);

     repeatCharInLine(40, '-');

         int horas = 0;

         puts("Digite o nº de horas.");
         scanf(" %i", &horas);
         printf("%i horas -> %li segundos\n", horas, n_segundos(horas));

         repeatCharInLine(40, '-');
         char type;
         puts("Digite o nº de horas.");
         scanf(" %i", &horas);
         puts("Digite para que tipo converter(h,m,s):");
         scanf(" %c", &type);
         printf("Resultado: %li\n", hourToMinOrSec(horas, type));

     float x, y, z;
     puts("Escreva 3 valores separados por virgula");
     scanf(" %f,%f,%f", &x, &y, &z);
     printf("Valor máximo: %f\n",max3(x,y,z));

     int valor;
     puts("escreva um valor inteiro");
     scanf(" %i", &valor);
     isImpar(valor) ? puts("O valor é impar") : puts("O valor é par");


     int min, value, max;
     puts("Escreva no seguinte formato:\"min valor max\"");
     scanf(" %i %i %i", &min, &value, &max);
     isBetween(min, value, max) ? puts("O valor pertence ao intervalo.") : puts("O valor não pertence ao intervalo.");

    char random[] = {'a','1','3','c','\a','\n','0','\r'};

    for (int i = 0; i < (int)sizeof(random); i++)
    {
        printf("O caracter %c com valor %i ,", random[i], (int)random[i]);
        isDigit(random[i]) ? puts("é um digito.") : puts("não é digito.");
    }
*/

    int n;
    puts("Insira um numero.");
    scanf("%i", &n);
    Triangulo(n);


  return 0;
}
