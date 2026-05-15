# Macros de Compilador em C

## Introdução

O compilador C possui várias macros internas que fornecem informação automática sobre o código durante a compilação.

Estas macros são muito usadas em:
- debugging
- sistemas de logging
- mensagens de erro
- frameworks
- software embedded
- motores de jogo
- kernels

As macros mais comuns são:

```c
__FILE__
__LINE__
__func__
__VA_ARGS__
```

---

# `__FILE__`

A macro `__FILE__` representa o nome do ficheiro atual.

Exemplo:

```c
#include <stdio.h>

int main()
{
    printf("%s\n", __FILE__);

    return 0;
}
```

Resultado:

```txt
main.c
```

Uso comum:

```c
printf("Erro no ficheiro: %s\n", __FILE__);
```

---

# `__LINE__`

A macro `__LINE__` representa a linha atual do código.

Exemplo:

```c
#include <stdio.h>

int main()
{
    printf("%d\n", __LINE__);

    return 0;
}
```

Resultado:

```txt
6
```

Uso comum:

```c
printf("Erro na linha: %d\n", __LINE__);
```

---

# `__func__`

A macro `__func__` representa o nome da função atual.

Exemplo:

```c
#include <stdio.h>

void test()
{
    printf("%s\n", __func__);
}

int main()
{
    test();

    return 0;
}
```

Resultado:

```txt
test
```

Uso comum:

```c
printf("Erro na função: %s\n", __func__);
```

---

# Argumentos Variáveis

Em C, macros podem receber uma quantidade variável de argumentos utilizando `...`.

Exemplo:

```c
#define PRINT(msg, ...) \
    printf(msg, __VA_ARGS__)
```

Uso:

```c
PRINT("Valor = %d\n", 10);
```

---

# `__VA_ARGS__`

A macro `__VA_ARGS__` contém todos os argumentos variáveis passados para a macro.

Exemplo:

```c
#define LOG(msg, ...) \
    printf(msg, __VA_ARGS__)
```

Uso:

```c
LOG("Idade = %d\n", idade);
```

Expansão:

```c
printf("Idade = %d\n", idade);
```

---

# `##__VA_ARGS__`

O operador `##` remove automaticamente a vírgula extra caso não existam argumentos variáveis.

Sem `##`:

```c
#define LOG(msg, ...) \
    printf(msg, __VA_ARGS__)
```

Uso:

```c
LOG("Olá");
```

Expansão inválida:

```c
printf("Olá", );
```

Com `##__VA_ARGS__`:

```c
#define LOG(msg, ...) \
    printf(msg, ##__VA_ARGS__)
```

A expansão correta fica:

```c
printf("Olá");
```

---

# Exemplo de Logging

```c
#include <stdio.h>

/* INFO */
#define LOG_INFO(msg, ...) \
    printf("[INFO] " msg "\n", ##__VA_ARGS__)

/* DEBUG */
#define LOG_DEBUG(msg, ...)               \
    printf("[DEBUG] [%s():%d] " msg "\n", \
           __func__, __LINE__, ##__VA_ARGS__)

/* WARNING */
#define LOG_WARN(msg, ...)               \
    printf("[WARN] [%s | %s] " msg "\n", \
           __FILE__, __func__, ##__VA_ARGS__)

/* ERROR */
#define LOG_ERROR(msg, ...)                    \
    printf("[ERROR] [%s:%d | %s()] " msg "\n", \
           __FILE__, __LINE__, __func__, ##__VA_ARGS__)

void test()
{
    int value = 10;

    LOG_INFO("Sistema iniciado");

    LOG_DEBUG("value = %d", value);

    LOG_WARN("Valor elevado");

    LOG_ERROR("Falha crítica");
}

int main()
{
    test();

    return 0;
}
```

---

# Saída Esperada

```txt
[INFO] Sistema iniciado

[DEBUG] [test():28] value = 10

[WARN] [main.c | test] Valor elevado

[ERROR] [main.c:32 | test()] Falha crítica
```

---

# Resumo

| Macro | Descrição |
|---|---|
| `__FILE__` | Nome do ficheiro atual |
| `__LINE__` | Linha atual |
| `__func__` | Nome da função atual |
| `...` | Permite argumentos variáveis |
| `__VA_ARGS__` | Contém os argumentos variáveis |
| `##__VA_ARGS__` | Remove vírgulas extra automaticamente |