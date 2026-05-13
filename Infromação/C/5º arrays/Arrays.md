# Matrizes
## Sintax dos arrays:
```c
tipo nome_variavel [numero de elementos];
```
- O priemiro elemnto de um array está na posição 0.
para aceder : `int valor = array[0];`

## Inicialização automatica

```c
tipo var[n] = {valor1,valor2,valor...} // em que o [n] é opcional se preeencher auto.
```

- se inicializar com um numero menor de valores que [n] o resto será inicializacom com ovalor 0;

nunca inicialize um array desta forma:
```c
int array_asneira[];
```

- Assim como as outras variaveis, é possivel passar para funções arrays como parametros.
- Estas funções devem ter pré defenido o tipo e o tamanho do array, ou seja, para um array de 10 elementos e um de 20 não serve uma unica função.
- Para manda para uma função basta colcoar o nome sem [].
- Dentro de uma função não é possivel saber o nº de elementos de um array

exemplo:

```c
#define MAX 10
void function10(int arr[MAX])

void function20(int arr[20])

int main(){
    int array1[10];
    int array2[20];

    function10(array1);
    function20(array2);
}
```
**OU**
```c
void functionX(int tamanho, int arr[])

int main(){
    int array1[10];
    int array2[20];

    functionX(10,array1);
    functionX(20,array2);
}
```
>Primeiro coloque o tamanho e depois o array.

# Arrays multidimencionais

## Array de 1D:

`int array[i];`

## Array de 2D

`int array[i][j]`

Para inicialiar:
```c
int array [4][5] =  {{x1,x2,x3,x4,x5}
                    ,{y1,y2         }
                    ,{z1,z2,z3      }
                    ,                }
```
## Array de xD

`int array[i][j]...[x]`

## Passagem para funções

- Pode passar assim:
```c
void function1(char arr[][valor]) == void function1(char(*arr)) == void function1(char *arr)
// ou
void function2(char arr[valori][valorj])
// nunca
void function3(char arr[][]) == void function3(int (*arr)[valorj]) == void function3(int *arr[valorj])
```

# Constantes

## `const` - qualificador de tipo.
- Existe na memória.

### sintax 

`const tipo simbolo = constante;`

## `#define` - constante simbólica

é uma diretiva de pré-processamento. É uma macro de substituição.
o simbol é subttuido pelo valor no pré-processamento.
 
### Sintax
`#define simbolo valor`


