# 1. Funções de `string.h`


## `strlen()`

Serve para **contar o tamanho da string** (sem o `\0`).

```c
#include <stdio.h>
#include <string.h>

int main() {
    char nome[] = "Carlos";
    printf("%d\n", strlen(nome)); // 6
}
```

👉 "Carlos" tem 6 letras.

---

## `strcpy()`

Serve para **copiar uma string para outra**.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char origem[] = "Olá";
    char destino[10];

    strcpy(destino, origem);

    printf("%s\n", destino); // Olá
}
```

⚠️ O destino tem de ter espaço suficiente!

---

## `strcat()`

Serve para **juntar (concatenar) strings**.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char texto[20] = "Olá ";
    char nome[] = "Carlos";

    strcat(texto, nome);

    printf("%s\n", texto); // Olá Carlos
}
```

⚠️ Também precisa de espaço livre no array.

---

## `strcmp()`

Serve para **comparar duas strings**.
- Compara caractere a caractere
- Usa valores ASCII
- Para na primeira diferença
- Não usa tamanho diretamente
```c
#include <stdio.h>
#include <string.h>

int main() {
    char a[] = "abc";
    char b[] = "abc";

    if (strcmp(a, b) == 0) {
        printf("Iguais\n");
    } else {
        printf("Diferentes\n");
    }
}
```
retorna:

* `0` → iguais
* `< 0` → a < b
* `> 0` → a > b

Aqui tens no mesmo estilo 👇

---

## `strchr()`

Procura um carácter numa string e devolve um pointer para onde ele está.

* Procura da esquerda para a direita
* Para na primeira ocorrência
* Retorna um **ponteiro para o caractere encontrado**
* Se não encontrar → retorna `NULL`

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "programacao";

    char *p = strchr(str, 'g');

    if (p != NULL) {
        printf("Encontrado: %c\n", *p);
        printf("Posição: %ld\n", p - str);
    } else {
        printf("Não encontrado\n");
    }
}
```
__*Explicação de uso:*__

Imagina isto na memória:

```txt
1000 → a
1001 → b
1002 → c
```

```c
char str[] = "abc";
char *p = strchr(str, 'b');
```

Aqui acontece isto:

* `str` aponta para `1000` (onde está `'a'`)
* `p` aponta para `1001` (onde está `'b'`)
* `*p` não é o endereço → é o **valor no endereço**, ou seja `'b'`


Agora a parte importante:

```c
p - str
```


O que o C faz é:

```txt
1001 - 1000 = 1 (posição no array)
```

Mas atenção: isto é **diferença de posições dentro do mesmo array**, não números de memória “livres”.

---

