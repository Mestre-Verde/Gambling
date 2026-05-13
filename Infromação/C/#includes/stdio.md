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

* Lê string com limite de tamanho (segura)
* Lê até `n-1` caracteres ou `\n`

```c
char string[50];
fgets(string, 50, stdin);
puts(string);
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

