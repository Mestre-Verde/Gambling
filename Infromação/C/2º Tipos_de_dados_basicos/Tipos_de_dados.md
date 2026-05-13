# 1. Variáveis

Antes de usar uma variavél é necessário declará-la da seguinte forma(sintax):
```txt
tipo var1[,var2,var3,varn];
```

## 1.1. Nomiar Variáveis
para dar nomes a variáveis é necessário sefuir algumas regras:
- O nome de uma variavel pode ser constituida por:
  - Caracteres minusculos e maiusculos(a-z & A-Z);
  - Digitos(0-9);
  - _Underscore_ ( _ );
- O primeiro caracter não pode ser um digito, mas pode ser o resto.(nãos e aconcelha o uso do _ no inicio).
- As variaveis não podem ter espaços no meio nem caracteres especiais.
- O nome não pode ser uma palavra reservada,nem se aconcelha a usar nomes de funções.
- é normal ter um nome com 31 caracteres ou masi depende do compilador.

## 1.2. Nomes de variáveis 
Existem algumas formas de nomear:
- NumberOfWords -> _Pascal Case_
- numberOfWords -> _Camel Case_
- number_of_words -> _Snake Case_

Variáveis com tudo maiúsculo são usadas para __constantes__.

# 2. Atribuição
para tribuir um valor a uma variável usa-se o operador `=`.
```txt
variável = expressão
```
a variável que vai receber o valor fica sempre no lado esquerdo do operador.

é possivel atribuir valores a variaveis sem as inicializar primeiro( inicialização automática):
```c
int num =-17;

int val = 1, val1 =2;

int num1, num2. num3 = 3, num4;

```
atribuir o  mesmo valor a várias variáveis:
```c
a = 1;
b = 1;
c = 1;

// ou

a = b = c = 1;
/*  <------- atribuição de valor
no final a,b,c ficam com o valor 1 guardado
*/
```


# 3. Modificadores de tipo
Estes modificadores podem ser usado em combinação com os datatypes para exigir um nº de bytes fixos entre arquiteturas.

|   nome    | nº de bytes | sinal |
| :-------: | :---------: | :---: |
|   short   |      2      |  --   |
|   long    |   4 ou 8    |  --   |
| long long |      8      |  --   |
|  signed   |     --      |   ±   |
| unsigned  |     --      |   +   |

A maioria as variaveis por defeito são `signed`, ou seja, tem valores positivos e negativos.

As `unsigned` só tem o lado positivo, mas o lado que era para ser negativo é extendido para o lado positivo, ou seja, praticamente é extendia a parte positiva dessa variavel já que não pode ter valores negativos.

# 4. Notação cientifica

É posisvel usar notação sientifica em datatypes reais(R):
```c
float Kilo = 10e3;
double Tera = 10E12;
float micro = 10E-6;
```

Em operações ariteméticas, quando estamos a usar numeros reais com inteiros, os inteiros tranforma-se em reais para o calculo.

> nunca usar o módulo `%` em operações com numeors reais.

