# Funções de stdlib.h

## `exit(int __status)`

- Serve para terminar o programa em uma função diferente da main();
- O seu parametro serve para returnar um erro code para assim se rposisvel perceber-se qual o motivo que causou o fim do programa.
- Normalmente usa-se as seguintes macros : `EXIT_SUCCESS` & `EXIT_FAILURE`;

```c
void exitWithState(int anyProblem)
{
    anyProblem ? exit(EXIT_FAILURE) : exit(EXIT_SUCCESS); // pode usar qualquer inteiro como parametro.
}
```
Logo depois do programa terminar execute no terminal:`echo $?`.

## `abs(int __x)`

Returna o argumento em módulo |x|.



## `atoi()`

Converte uma **string para inteiro (`int`)**.

* Ignora espaços iniciais
* Para na primeira coisa que não for número
* ❌ Não deteta erros (perigoso)

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "1234";

    int num = atoi(str);

    printf("Número: %d\n", num);
}
```

Exemplos:

* `"123"` → `123`
* `"  42abc"` → `42`
* `"abc"` → `0` (⚠️ ambíguo)



## `atof()` 

Converte uma **string para `double`**.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    char str[] = "3.14";

    double num = atof(str);

    printf("Número: %f\n", num);
}
```