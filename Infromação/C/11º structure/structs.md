# Structures (`struct`) em C
As `structs` em C permitem agrupar várias variáveis diferentes dentro de um único tipo.

## Sintax


### Criar Variáveis da Struct

```c
struct Pessoa {
    char nome[50];
    int idade;
};

int main() {

    struct Pessoa p1;

    return 0;
}
```



### Aceder aos Campos

Usa-se o operador `.`

```c
#include <stdio.h>
#include <string.h>

struct Pessoa {
    char nome[50];
    int idade;
};

int main() {

    struct Pessoa p1;

    strcpy(p1.nome, "Carlos");
    p1.idade = 22;

    printf("%s\n", p1.nome);
    printf("%d\n", p1.idade);

    return 0;
}
```



### Inicialização Direta

```c
struct Pessoa {
    char nome[50];
    int idade;
};

int main() {

    struct Pessoa p1 = {
        "Ana",
        30
    };

    return 0;
}
```



### Inicialização Nomeada

Muito útil.

```c
struct Pessoa p1 = {
    .idade = 25,
    .nome = "Joao"
};
```

Isto evita erros quando a struct cresce.



### `typedef`

Evita escrever `struct` constantemente.

```c
typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int main() {

    Pessoa p1;

    return 0;
}
```

Agora `Pessoa` torna-se um tipo diretamente.



## Struct Dentro de Struct

```c
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[50];
    Data nascimento;
} Pessoa;
```

Uso:

```c
Pessoa p;

p.nascimento.dia = 10;
p.nascimento.mes = 5;
p.nascimento.ano = 2000;
```



# Arrays Dentro de Structs

```c
typedef struct {
    char nome[50];
    int notas[5];
} Aluno;
```



# Array de Structs

```c
Aluno turma[30];
```

Uso:

```c
turma[0].notas[2] = 18;
```



# Structs e Funções

## Passar Struct por Valor

```c
#include <stdio.h>

typedef struct {
    int x;
    int y;
} Ponto;

void mostrar(Ponto p) {

    printf("%d %d\n", p.x, p.y);
}

int main() {

    Ponto p = {10, 20};

    mostrar(p);

    return 0;
}
```



# Problema de Passar por Valor

A struct é COPIADA.

Em structs grandes isto custa memória e CPU.



# Passar por Ponteiro

Muito mais comum.

```c
#include <stdio.h>

typedef struct {
    int x;
    int y;
} Ponto;

void mostrar(Ponto *p) {

    printf("%d %d\n", p->x, p->y);
}

int main() {

    Ponto p = {10, 20};

    mostrar(&p);

    return 0;
}
```



# Operador `->`

Isto:

```c
p->x
```

é equivalente a:

```c
(*p).x
```



# Alterar Struct Dentro da Função

```c
#include <stdio.h>

typedef struct {
    int vida;
} Jogador;

void dano(Jogador *j) {

    j->vida -= 10;
}

int main() {

    Jogador j = {100};

    dano(&j);

    printf("%d\n", j.vida);

    return 0;
}
```



# Structs e Memória

Cada campo ocupa memória.

```c
typedef struct {
    char a;
    int b;
} Exemplo;
```

Nem sempre o tamanho é:

```text
1 + 4 = 5 bytes
```

Pode ser:

```text
8 bytes
```

por causa de:



# Padding

O compilador adiciona espaços para alinhar memória.

```c
#include <stdio.h>

typedef struct {
    char a;
    int b;
} Exemplo;

int main() {

    printf("%zu\n", sizeof(Exemplo));

    return 0;
}
```



# Melhorar Alinhamento

```c
typedef struct {
    int b;
    char a;
} Exemplo;
```

Às vezes reduz padding.



# Struct Packing

⚠️ Usar com cuidado.

```c
#pragma pack(push, 1)

typedef struct {
    char a;
    int b;
} Exemplo;

#pragma pack(pop)
```

Agora não há padding.

Útil para:

* protocolos
* ficheiros binários
* hardware
* registradores

Mas pode reduzir performance.



# Structs e Ponteiros

```c
typedef struct {
    int x;
} Teste;

int main() {

    Teste t = {10};

    Teste *ptr = &t;

    printf("%d\n", ptr->x);

    return 0;
}
```



# Struct Dinâmica (`malloc`)

```c
#include <stdlib.h>

typedef struct {
    int idade;
} Pessoa;

int main() {

    Pessoa *p = malloc(sizeof(Pessoa));

    p->idade = 50;

    free(p);

    return 0;
}
```



# Structs Auto-Referenciadas

Muito importante.

```c
typedef struct Node {
    int valor;
    struct Node *next;
} Node;
```

Usado em:

* linked lists
* árvores
* grafos



# Exemplo de Linked List

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int valor;
    struct Node *next;
} Node;

int main() {

    Node *n1 = malloc(sizeof(Node));
    Node *n2 = malloc(sizeof(Node));

    n1->valor = 10;
    n1->next = n2;

    n2->valor = 20;
    n2->next = NULL;

    printf("%d\n", n1->next->valor);

    free(n1);
    free(n2);

    return 0;
}
```






# Diferença Entre `struct` e `union`

## Struct

Cada campo tem memória própria.

```c
struct Teste {
    int a;
    float b;
};
```



## Union

Todos os campos partilham a MESMA memória.

```c
union Teste {
    int a;
    float b;
};
```



# Exemplo de `union`

```c
#include <stdio.h>

union Valor {

    int inteiro;
    float decimal;
};

int main() {

    union Valor v;

    v.inteiro = 10;

    printf("%d\n", v.inteiro);

    v.decimal = 5.5;

    printf("%f\n", v.decimal);

    return 0;
}
```

Ao escrever em `decimal`, destróis `inteiro`.



# Bit Fields

Muito usado em embedded.

```c
typedef struct {

    unsigned ligado : 1;
    unsigned erro   : 1;
    unsigned modo   : 2;

} Flags;
```

Isto compacta bits.



# Exemplo Embedded

```c
typedef struct {

    uint8_t enable;
    uint16_t speed;
    uint32_t status;

} Motor;
```



# Mapear Hardware

Extremamente comum.

```c
typedef struct {

    volatile uint32_t CTRL;
    volatile uint32_t STATUS;
    volatile uint32_t DATA;

} UART_Registers;
```

Uso:

```c
#define UART0 ((UART_Registers *)0x40000000)

UART0->CTRL = 1;
```



# `volatile`

Importante em hardware.

Impede o compilador de otimizar acessos.



# Comparar Structs

❌ ERRADO:

```c
if (a == b)
```

C não permite comparação direta de structs.



# Comparação Correta

```c
#include <string.h>

memcmp(&a, &b, sizeof(a));
```

⚠️ Cuidado com padding.



# Copiar Structs

```c
Pessoa b = a;
```

Copia tudo automaticamente.



# Structs Constantes

```c
void mostrar(const Pessoa *p)
```

Isto impede alterações acidentais.



# Structs e Ficheiros Binários

```c
fwrite(&p, sizeof(Pessoa), 1, file);
```



# Ler Struct

```c
fread(&p, sizeof(Pessoa), 1, file);
```



# Cuidado com Binários

Problemas possíveis:

* padding
* endianess
* versões diferentes
* compiladores diferentes



# Forward Declaration

```c
typedef struct Node Node;

struct Node {
    int valor;
    Node *next;
};
```

Muito usado em headers.



# Structs OOP Style

Muito usado em C avançado.

```c
typedef struct {

    int valor;

    void (*mostrar)(void *);

} Objeto;
```



# Exemplo

```c
#include <stdio.h>

typedef struct {

    int valor;

    void (*mostrar)(void *);

} Objeto;

void mostrarObjeto(void *obj) {

    Objeto *o = obj;

    printf("%d\n", o->valor);
}

int main() {

    Objeto o;

    o.valor = 99;
    o.mostrar = mostrarObjeto;

    o.mostrar(&o);

    return 0;
}
```



# Convenções Comuns

Muitos projetos usam:

```c
typedef struct Pessoa Pessoa;
```

no `.h`

e:

```c
struct Pessoa {
    ...
};
```

no `.c`

para esconder implementação.



# Boas Práticas

## Usa `typedef`

Facilita leitura.



## Passa structs grandes por ponteiro

Evita cópias.



## Usa `const`

Evita bugs.



## Atenção ao padding

Especialmente:

* embedded
* rede
* binários



## Inicializa sempre

```c
Pessoa p = {0};
```

Muito importante.



# Exemplo Realista

```c
#include <stdio.h>
#include <string.h>

typedef struct {

    char nome[50];
    int idade;
    float nota;

} Aluno;

void mostrarAluno(const Aluno *a) {

    printf("Nome: %s\n", a->nome);
    printf("Idade: %d\n", a->idade);
    printf("Nota: %.2f\n", a->nota);
}

int main() {

    Aluno a = {
        .nome = "Carlos",
        .idade = 22,
        .nota = 17.5f
    };

    mostrarAluno(&a);

    return 0;
}
```