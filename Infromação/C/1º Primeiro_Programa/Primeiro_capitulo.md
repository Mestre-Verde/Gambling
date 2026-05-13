
# 1. Linguagem C

- Esta linguagem é _case sensitive_, ou seja, `main` é diferente de `Main`.
- O número `0` corresponde a "tudo bem", e o número `1` corresponde a "algo correu mal".
- No final de cada linha de código é necessário colocar o caracter ";".
- O caracter \" não pode ser substiotuido por os outros ( \' , \` , ´).



## 1.1. Compilação e execução na shell

### 1.1.1. Compilar apenas (opção `-c`) o ficheiro `myprogram.c` gerando o ficheiro objeto `myprogram.o`:
```bash
cc -c myprogram.c
```

### 1.1.2. Criar executável final (opção `-o`) `myprogram` a partir do ficheiro objeto `myprogram.o`:

```bash
cc myprogram.o -o myprogram
```

### 1.1.3. Compilar e "linkar" o ficheiro `myprogram.c` diretamente, gerando o executável final (opção `-o`) `myprogram`:

```bash
cc myprogram.c -o myprogram
```

ou usando `make`:

```bash
make myprogram
```

### 1.1.4. Executar o programa:

```bash
./myprogram
#ou, se estiver no PATH:
myprogram
```

###  1.1.5. Para ver o resultado do trabalho do pré processador,pode usar a (opção `-E`) do compilador:
```bash
cc -E myprogram.c
```

# 2. Caracter especial "/"
Alguns caracteres podem representar funções outros precisam do caracter especial para aparecerem ou para não gerar um erro de compilação.

| Caractere    | Significado / Uso               | Exemplo em printf                  |
| ------------ | ------------------------------- | ---------------------------------- |
| `\n`         | Nova linha (newline)            | `printf("Olá\nMundo");`            |
| `\t`         | Tabulação horizontal (tab)      | `printf("Coluna1\tColuna2");`      |
| `\\`         | imprime \                       | `printf("C:\\Users");`             |
| `\"`         | Imprime "                       | `printf("Ele disse: \"Oi\"");`     |
| `\'`         | Imprime '                       | `printf("Letra: \'A\'");`          |
| `\r`         | carriage return                 | `printf("123\rABC");`              |
| `\b`         | Backspace                       | `printf("AB\bC");`                 |
| `\f`         | Form feed (nova página)         | `printf("Página1\fPágina2");`      |
| `\v`         | Tabulação vertical              | `printf("Linha1\vLinha2");`        |
| `\a` ou `\7` | Alerta / beep sonoro            | `printf("\a");` ou `printf("\7");` |
| `\0`         | Caractere nulo (fim de string)  | `char s[] = "Oi\0Mundo";`          |
| `\?`         | imprime ?                       | `printf("Valor\?");`               |
| `\ooo`       | Valor octal (0 a 377)           | `printf("\101");` → imprime `A`    |
| `\xhh`       | Valor hexadecimal (0x00 a 0xFF) | `printf("\x41");` → imprime `A`    |
| `%%`         | Percent literal em `printf`     | `printf("50%% concluído");`        |

# 3. Comentários
Os cometários são ignorados pelo compilador.
Em C existem 2 tipos de comentários
```c
// Comentário de linha

/*
Comentário
multilinha
*/
```
- Não é possivel escrever comentários dentro de comentários.
- é possivele screver comentários dentrode uma instrução desde que se use /**/ e não seja dentro de uma string.