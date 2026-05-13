# Funções
Uma função deve estar localizada antes de ser usada.

Caso seja necessário, colocar a função em outro lugar é necessário fazer uma declaração no inicio(depois das bibliotecas ).
A isto chama-se de prototipagem ou protótipo.
 ```c
 #include <biblioteca>

//protótipo
 void função(datatype var1,datatype var2,...);
 //ou até
 void função(datatype.datatype,...);

 int main(){
    função(var1,...);
 }

 void função(args var1....){

 }
 ```

Funções : retornam algo;

Procedimentos : não retornam nada(void)

## sintax de uma função

```c
datatype nome(datatype var1,datatype var2,...){
    Corpo da função;
    return expressão;
}
```

## sintax de um procedimento

```c
void nome(datatype arg1,datatype arg2,...){
    Corpo da função;
    return;// não obrigatório
    // ou
    return void;
}
```

## Variaveis locais

Esta variaveis são só conhecidas dentro do bloco `{}` em que se encontram.

## Funções que retornam um valor lógico

ora em vez de fazer isto:
```c
int is_equal(int x,int y){
    if (x==y) return 1;
    else return 0;
}
```
fazemos algo mais simples, lembrando que os coperadores de condições como o `==` quando executádos já retornam um valor lógico. Fazemos então:
```c
void is_equal(int x,int y){
    return (x==y);
}
```

## Sair de uma função
para sair de uma função usa-se a instrução `return`. Esta instrução deve ter uma expressão referente ao datatype da função.

nos void , basta um return, ou return void.

nos ints e inteiros, basta returnar inteiros como return 0, return -122, return (expressão).

### return 0;

Na main , ou em outra função, quando a afunção returna 0 é proque tudo correu bem, quando returna 1 ou outro int, é proque algo de mal aconteceu.
no linux se algo correr mal e no codigo que retornou tiver um numero, ao mandar depois do programa o caracter $ no terminal claro, é returnado esse valor.
    
>Lembrando que o programa só termina se houver return no main.

prompt
```sh
$ program123
textotexto
Erro:algo correu mal em x lugar

$ echo $?
1

$ program234
inicio do programa
fim do programa

$ echo $?
0
```





