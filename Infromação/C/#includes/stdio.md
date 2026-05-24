# 1. Funções de `stdio.h`

## 1.1. `printf()` (print+formate)

* Mostra uma string no terminal.
* **Não adiciona `\n` automaticamente**.
* Permite formatar variáveis com *placeholders* (`%d`, `%f`, `%c`, etc).

```c
#include <stdio.h>
int main(void){
    int num = 123;
    printf("O valor de num é %d, o valor seguinte é %d\n", num, num+1);
    return 0;
}
```



## 1.2. `scanf()` (scan + read + format)

* Lê valores do teclado.
* ⚠️ É obrigatório usar `&` (endereço da variável).
* Pode falhar com input inválido → cuidado!
- Introduzir letras ou numeros maiores que o valor máximo de datatype pode produzir valores inesperados.(instruções infinitas).
- As strings não precisam do operador `&`. 
```c
#include <stdio.h>
int main(void){
    int inteiro;

    printf("Introduza um Nº: ");
    scanf("%d", &inteiro);

    printf("O Nº introduzido foi: %d\n", inteiro);
    return 0;
}
```



### 1.2.1.  Vários valores:

```c
scanf(" %d %d %d", &var1, &var2, &var3);
```

**Nota importante sobre espaços:**

* `" %c"` ignora whitespace anterior
* útil quando há `\n` pendente no buffer

### 1.2.2. Ler linha inteira (string com espaços)

```c id="a1b2c3"
char str[100];
scanf(" %[^\n]%*c", str);
```

* Lê tudo até ao `\n`
* Permite espaços dentro da string
* Útil para frases completas
* ` %*c` consome o `\n` que fica no buffer (evita problemas em `scanf` seguintes)

## 1.6. `sscanf()` (string scan + format)

* Lê dados a partir de uma string
* Funciona como `scanf()`, mas em vez do teclado usa uma string

```c id="m3v7ka"
#include <stdio.h>

int main(void){
    char texto[] = "123 45.7 A";

    int num;
    float decimal;
    char letra;

    sscanf(texto, "%d %f %c", &num, &decimal, &letra);

    printf("Inteiro: %d\n", num);
    printf("Float: %.1f\n", decimal);
    printf("Char: %c\n", letra);

    return 0;
}
```

---

### 1.6.1. Return da função

`sscanf()` retorna: __int__

#### Em sucesso:

Retorna: _Número de valores lidos corretamente_

#### Em erro:

Retorna: `0`

quando não consegue converter nada.


#### Em EOF/fim da string:

Pode retornar:

```c id="rjz2fi"
EOF
```

### 1.6.2. Porque usamos `==`

```c id="s6y4ci"
if(sscanf(texto, "%d %f", &a, &b) == 2)
```

Porque:

* `sscanf()` retorna quantidade de valores convertidos
* queremos verificar se todos foram lidos corretamente

## 1.3. `puts()` (put string)

* Mostra uma string
*  adiciona automaticamente `\n`

```c
puts("Olá mundo");
```

## 1.4. `getchar()`

* Lê **um único caracter**
* Retorna `int` (para suportar `EOF`)
* Quando se executa esta função ela fica em modo espera.
```c
#include <stdio.h>

int main(void){
    char ch = getchar();
    printf("Caracter obtido: %c\n", ch);
    return 0;
}
```

## 1.5. `putchar()`

* Imprime **um único caracter**

```c
#include <stdio.h>

int main(void){
    char ch = 'A';
    putchar(ch);
    return 0;
}
```
## 1.6. `gets()` (GET STRING)

* Lê uma string até `\n`
* ❌ **insegura (deprecated/removed em C11)** pode subscrever na memória.

```c
char string[50];
printf("Introduza uma string:");
gets(string);
puts(string);
```


## 1.7. `fgets()` (FILE GET STRING)

* Lê uma linha/string de forma segura
* Lê até:

  * `n-1` caracteres
  * `\n`
  * `EOF`
* Mantém o `\n` na string caso exista espaço
* Evita buffer overflow (mais segura que `gets()`)

```c
#include <stdio.h>

int main(void){
    char string[50];

    printf("Introduza texto: ");

    if(fgets(string, 50, stdin) != NULL){
        puts(string);
    }

    return 0;
}
```

### 1.7.1. Return da função

#### 1.7.1.1. Em sucesso:

Retorna:

```c
string
```
no final coloca um '\0'
(ponteiro válido para a própria string)


#### 1.7.1.2. Em erro ou EOF:

Retorna:

```c
NULL
```



# 2. 🔥 Agora vou adicionar mais funções úteis no mesmo estilo

---

## 2.1. `fopen()` (file open)

* Abre um ficheiro
* Retorna um ponteiro (`FILE *`)

```c
FILE *f = fopen("file.txt", "w");
```

💡 Modos:

* `"r"` → ler
* `"w"` → escrever (apaga conteúdo)
* `"a"` → adicionar

---

## 2.2. `fclose()`

* Fecha o ficheiro

```c
fclose(f);
```

---

## 2.3. `fprintf()` (file printf)

* Igual ao `printf` mas escreve em ficheiro

```c
fprintf(f, "Valor: %d\n", 10);
```

---

## 2.4. `fscanf()`

* Igual ao `scanf` mas lê de ficheiro

```c
fscanf(f, "%d", &num);
```



## 2.5. `remove()`

* Apaga um ficheiro

```c
remove("file.txt");
```

---

## 2.6. `tmpfile()`

* Cria ficheiro temporário automático
* É apagado ao fechar

```c
FILE *f = tmpfile();
```

---

