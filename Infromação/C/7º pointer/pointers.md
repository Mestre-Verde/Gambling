# Pointers

##  Definição

Um pointer é uma variável que guarda o **endereço de memória de outra variável** de um determinado tipo.

## Sintax
```c
type * name;
```


##  Resumo base

```txt
var   → variável (guarda um valor)
var = 1 → atribuição do valor 1 à variável var
&var  → endereço de memória onde var está guardada
```
## Regra mental simples

* `&` → “pega no endereço”
* `*` → “vai ao endereço e lê o valor”

##  Inicialização de um pointer

```c
int var = 0;
int *pointer;
pointer = &var;
//ou
int var = 0;
int *pointer = &var;
// abaixo é tudo igual
int* var;// induz em erro
int * var;
int *var;
```

 Explicação:

* `int var = 0;` → variável normal
* `int *pointer;` → pointer para um inteiro
* `pointer = &var;` → pointer recebe o endereço de `var`


##  Como ler isto corretamente

```txt
*pointer → valor guardado no endereço apontado (ou seja, var)
&var     → endereço de var
pointer  → contém o endereço de var
```


## Inicialização de um pointer (com NULL)

Um pointer pode ser inicializado com `NULL` quando ainda não aponta para um endereço válido. Isto evita o problema de usar pointers que contêm lixo de memória.

```c
int *pointer = NULL;
```

`NULL` significa que o pointer não aponta para nada.

Antes de usar um pointer, é comum verificar se ele é válido:

```c
if (pointer != NULL) {
    // seguro usar *pointer
}
```

## Nota sobre NULL

`NULL` é normalmente definido como uma constante pelo compilador, usada para representar um pointer vazio. Em C, é geralmente definido como:

```c
#define NULL ((void*)0)
```

ou simplesmente como:

```c
0
```

Ou seja, `NULL` não é um endereço real, é apenas uma forma de dizer que o pointer não aponta para nenhum local válido na memória.

É usado para inicializar pointers e evitar que contenham lixo antes de serem atribuídos a um endereço válido.

## Endereço dos ponteiros

O pointer guarda o endereço do **primeiro byte** de uma variável. O tipo do pointer não muda o endereço, mas diz ao compilador quantos bytes deve ler quando fazes `*pointer`.

Exemplo:

```c
int x = 10;   // ocupa 4 bytes
int *p = &x;
```

Se `x` estiver em memória a partir do endereço `100`, então `p` guarda `100` (primeiro byte). Ao fazer `*p`, o sistema lê os 4 bytes a partir desse endereço.

```txt
100 → byte 1
101 → byte 2
102 → byte 3
103 → byte 4
```

Para `char`, como ocupa 1 byte, o pointer também aponta apenas para esse único byte.


## Arrays e ponteiros
Em C, `arr` e `&arr[0]` dão praticamente o mesmo endereço, mas não são exatamente o mesmo tipo.

Se tiveres:

```c id="a1b2c3"
int arr[3] = {10, 20, 30};
```

Então:

* `arr` → “decai” para um pointer para o primeiro elemento
* `&arr[0]` → endereço do primeiro elemento

Ou seja, ambos apontam para o mesmo sítio:

```txt id="d4e5f6"
arr     → endereço de 10
&arr[0] → endereço de 10
```

Mas há uma diferença importante:

```c id="g7h8i9"
arr     → tipo: int*
&arr[0] → tipo: int*
```

Já isto:

```c id="j1k2l3"
&arr
```

é diferente:

* tipo: `int (*)[3]` (pointer para o array inteiro)
* mesmo endereço, mas significado diferente

Resumo curto:

* `arr == &arr[0]` em valor (mesmo endereço)
* mas `arr` não é exatamente o mesmo tipo que `&arr`


## ⚠️ Erro comum que deves evitar

```c
*var   ❌ (ERRADO se var não for pointer)
```





