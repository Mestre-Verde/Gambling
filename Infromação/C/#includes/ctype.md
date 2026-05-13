# Funções de `ctype.h`

## Visão geral

* `ctype.h` fornece funções/macros para **classificação de caracteres ASCII**.
* Baseia-se normalmente numa **tabela interna de 256 bytes (`_ctype[]`)**.
* Cada função verifica bits associados ao carácter (ex: letra, dígito, espaço).



## ⚙️ Importante

* Trabalha apenas com valores `unsigned char` (0–255)
* Não é Unicode-aware (apenas ASCII / extended ASCII)
* Muito eficiente: geralmente é um **lookup em array + operação bitwise**


## `int isalpha(int c)`

* Verifica se o carácter é uma **letra (A–Z ou a–z)**

## `int isdigit(int c)`

* Verifica se o carácter é um **dígito (0–9)**

## `int isalnum(int c)`

* Verifica se é **letra ou número**

## `int isspace(int c)`

* Verifica se é um **carácter de espaço em branco**  (espaço, tab, newline, etc.)

## `int ispunct(int c)`

* Verifica se é **pontuação** (`, . ! ?` etc.)

## `int isupper(int c)`

* Verifica se é **letra maiúscula**

## `int islower(int c)`

* Verifica se é **letra minúscula**

## `int isxdigit(int c)`

* Verifica se é um **dígito hexadecimal**
  (`0–9`, `a–f`, `A–F`)

## 🔁 Conversões

## `int toupper(int c)`

* Converte para maiúscula (se aplicável)

```c
char x = toupper('a'); // 'A'
```

## `int tolower(int c)`

* Converte para minúscula (se aplicável)

```c
char x = tolower('A'); // 'a'
```
