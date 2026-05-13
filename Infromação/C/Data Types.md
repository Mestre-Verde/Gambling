# 1. Data Types

| Tipo de variável | explicação                       | nº de bytes |
| ---------------- | -------------------------------- | ----------- |
| char             | um carácter                      | 1           |
| unsigned char    | carácter sem sinal (0 a 255)     | 1           |
| short            | inteiro curto (Z)                | 2           |
| unsigned short   | inteiro curto sem sinal          | 2           |
| int              | números inteiros (Z)             | 4           |
| unsigned int     | inteiros positivos               | 4           |
| long             | inteiro longo (Z)                | 8           |
| unsigned long    | inteiro longo sem sinal          | 8           |
| long long        | inteiro muito longo (Z)          | 8           |
| float            | números reais (R)                | 4           |
| double           | números reais (R)                | 8           |
| long double      | números reais com maior precisão | 16          |
| _Bool / bool     | valor lógico (0 ou 1)            | 1           |
| size_t           | tamanho de objetos (unsigned)    | 8           |
| void*            | ponteiro genérico                | 8           |




# 2. Formatos de leitura e escrita
|       Tipo        |   Formato    |                     Observações                     |
| :---------------: | :----------: | :-------------------------------------------------: |
|       char        |      %c      |  Para colocar um carácter diretamente usa-se `' '`  |
|        int        |      %d      |              Inteiros em base decimal               |
|        int        |      %i      |      Inteiro (equivalente a `%d` em `printf`)       |
|   unsigned int    |      %u      |              Apenas valores positivos               |
|        int        |      %o      |                Inteiro em base octal                |
|        int        |      %x      |     Inteiro em hexadecimal (letras minúsculas)      |
|        int        |      %X      |     Inteiro em hexadecimal (letras maiúsculas)      |
|       float       |      %f      |              Número em ponto flutuante              |
|       float       |    %.2f%     |             arredonda 2 casas decimais.             |
|  float / double   |      %e      |            Notação científica (`1.0e+3`)            |
|  float / double   |      %E      |            Notação científica (`1.0E+3`)            |
|  float / double   |      %g      | Usa `%f` ou `%e` automaticamente (forma mais curta) |
|  float / double   |      %G      |         Igual a `%g`, mas com `E` maiúsculo         |
|      double       |     %lf      |  Necessário para `scanf`, em `printf` usa-se `%f`   |
|       short       | %h, %hd, %hi |        Modificador combinado com o tipo base        |
|       long        | %l, %ld, %li |        Modificador combinado com o tipo base        |
|     long long     |     %lld     |              Inteiro longo de 64 bits               |
|      size_t       |     %zu      |           Usado tipicamente com `sizeof`            |
|     ponteiro      |      %p      |          Endereço de memória (hexadecimal)          |
| string (`char *`) |      %s      |       Cadeia de caracteres terminada em `\0`        |

# Uso dos fomatos %

Para ter um numero a ocupar x espaços usamos um numero antes da letra:

Em inteiros: `%2i` - ocupa 2 espaços em string para o numero.

Em flutuantes: `%2.1f` - mostra 2 para a frente e 1 para trás.

---

Para remover um caracter que tenha ficado no buffer: `%*d`.


# **char**

- Armazena 1 byte.
- Os valores que pode ter vêm do resultado da combinação 2^8.
- Para inicializar com um valor este datatype é necessário usar `''` e não aspas.
- É praticamente um inteiro de 1byte, pode ser lido tanto em decimal como hexadecimal sem ser como char.

# **int**

- O valor de bytes depende do compilador e da arquitetura.
- Armazena valores inteiros, sem pontos flotuantes.

# **float**

- Variavel com pontos flotuantes
- menos precisa em relação ao Data type double.

# **double**

- Normalemnte uma variavel com mais baytes, sendo assim maior precisão.
- É a junção do int com o float.

