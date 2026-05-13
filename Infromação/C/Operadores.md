# 1. Operadores  ariteméticos

| operador |    explicação    |
| :------: | :--------------: |
|    +     |       soma       |
|    -     |    subtração     |
|    *     |  multipolicação  |
|    /     |     divisão      |
|    %     | resto da divisão |

# Atríbuição composta
| operador |    explicação    |
| :------: | :--------------: |
|    +=    |       soma       |
|    -=    |    subtração     |
|    *=    |  multipolicação  |
|    /=    |     divisão      |
|    %=    | resto da divisão |

em vez de escrever `i = i + 34` escreve-se `i += 34`.

## Sintax
`var op= expressão`  (=)  `var = var op expresão `



# Operador lógico

| operador | explicação |
| :------: | :--------: |
|    &&    |    AND     |
|   \|\|   |     OR     |
|    !x    |    NOT     |

# Nivel de prioridade

|   operador   |
| :----------: |
| <, =<, >, => |
|   == , !=    |
|      &&      |
|     ? :      |

# 2. Operadores 

| operador | sintax                                  | explicação                            |
| -------- | --------------------------------------- | ------------------------------------- |
| sizeof   | sizeof <expressão> ou sizeof (datatype) | Dá a dimenção de um datatype em bytes |
| return   | return <expressão>                      | returna algo e sai de uma função      |
| break    | break;                                  | Saí dum ciclo                         |
| continue | continue;                               | Salta para o próximo ciclo de um loop |
| typedef  |                                         |                                       |
| trenário | expressão ? se verdadeira  : se falso   | Uma sintax rapida para condição       |


# Operadorres unários

| operador | significado          | modo     |
| -------- | -------------------- | -------- |
| ++       | Incrementa 1 unidade | prefixo  |
| --       | Decrementa 1 unidade | postfixo |

substitui o codigo `i = i + 1`;

`y = ++x` (=) `x = x + 1; y = x` (=) `y = x ` (incrementa, depois usa)

`y = x++` (=) ` y = x; x = x + 1` (=) `y = x - 1`  (usa e depois incrementa)


# Operadores bit a bit



# 2. Caracter especial "/"
Alguns caracteres podem representar funções outros precisam do caracter especial para aparecerem ou para não gerar um erro de compilação.

| Caractere    | Significado / Uso               | Exemplo em printf                  | explicação melhor                                          |
| ------------ | ------------------------------- | ---------------------------------- | ---------------------------------------------------------- |
| `\n`         | Nova linha (newline)            | `printf("Olá\nMundo");`            | dá enter                                                   |
| `\t`         | Tabulação horizontal (tab)      | `printf("Coluna1\tColuna2");`      | dá um tab                                                  |
| `\\`         | imprime \                       | `printf("C:\\Users");`             |
| `\"`         | Imprime "                       | `printf("Ele disse: \"Oi\"");`     |
| `\'`         | Imprime '                       | `printf("Letra: \'A\'");`          |
| `\r`         | carriage return                 | `printf("123\rABC");`              |
| `\b`         | Backspace                       | `printf("AB\bC");`                 | apaga o caracter anterior                                  |
| `\f`         | Form feed (nova página)         | `printf("Página1\fPágina2");`      |
| `\v`         | Tabulação vertical              | `printf("Linha1\vLinha2");`        | continua a escrever na linha em baixo sem voltar ao inicio |
| `\a` ou `\7` | Alerta / beep sonoro            | `printf("\a");` ou `printf("\7");` |
| `\0`         | Caractere nulo (fim de string)  | `char s[] = "Oi\0Mundo";`          |
| `\?`         | imprime ?                       | `printf("Valor\?");`               |
| `\ooo`       | Valor octal (0 a 377)           | `printf("\101");` → imprime `A`    |
| `\xhh`       | Valor hexadecimal (0x00 a 0xFF) | `printf("\x41");` → imprime `A`    |
| `%%`         | Percent literal em `printf`     | `printf("50%% concluído");`        |