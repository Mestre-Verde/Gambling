# 1. 🔹 `int main(...)`

* `main` é o **ponto de entrada** do programa (onde começa a execução).
* `int` significa que a função devolve um **inteiro** (normalmente `0` = sucesso).

---

## 2. 🔹 `argc`

* Vem de **argument count** (número de argumentos).
* Indica quantos argumentos foram passados ao programa pela linha de comandos.

Exemplo:

```bash
./programa ola mundo
```

Aqui:

* `argc = 3`

  * `./programa`
  * `ola`
  * `mundo`

---

## 3. 🔹 `argv`

* Vem de **argument vector** (vetor de argumentos).
* É um **array de strings** (`char const *argv[]`) com os argumentos.

Exemplo:

```c
argv[0] -> "./programa"
argv[1] -> "ola"
argv[2] -> "mundo"
```

---

## 4. 🔹 `const char *argv[]`

* Cada argumento é uma **string** (`char *`)
* O `const` significa que **não deves alterar o conteúdo dessas strings**.

---

### 5. 💡 Exemplo completo

```c
#include <stdio.h>

int main(int argc, char const *argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("Argumento %d: %s\n", i, argv[i]);
    }
    return 0;
}
```

---

### 6. ⚠️ Nota importante

* `argv[0]` é **sempre o nome do programa**
* `argc` é **sempre ≥ 1**

---

