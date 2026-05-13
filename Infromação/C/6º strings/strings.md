# Strings (array de chars)

No final de uma string é obrigatório haver um caracter terminador o `\0`;
 - Claro que isto implica aumentar o array com 1 byte;

Strings são representadas com aspas `""`;

A passagem de strings para funções fas-se da mesma forma que arrays.
# Inicialização automática

```c
char nome1[20] = "Nome123";
char nome2[] = "Nome321";
char nome3[] = {'N','O','M','E'}
char nome4[20] = {'N','O','M','E'}
char *string = "aeiou";
```

# Concatenar uma string
Isto refere-se a adicionar caracteres a uma string sem limpar o contiudo original.



# Em C não existem funções que devolvem arrays

Em C, não é possível devolver um array diretamente numa função.

👉 Para “retornar” um array tens de usar **ponteiros**.



## 🟢 Formas corretas

### 1. Passar o array por parâmetro (mais usado)

```c
void init_str(char s[]) {
    s[0] = '\0';
}
```

✔ a função modifica o array original
✔ não precisa de `return`

---

### 2. Devolver um ponteiro (com `malloc`)

```c
#include <stdlib.h>

char* create_str() {
    char *s = malloc(100);
    s[0] = '\0';
    return s;
}
```

⚠️ precisa de `free()` depois

---

### 3. Usar `static` (casos específicos)

```c
char* f() {
    static char s[100];
    s[0] = '\0';
    return s;
}
```

⚠️ não é reentrante



