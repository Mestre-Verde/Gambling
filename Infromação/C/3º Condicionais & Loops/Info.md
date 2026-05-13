# Condicionais

## Sintaxe if
```c
if (condition)
{
    /* code */
}
else if (condition)  (opcional)
{
    /* code */
}
else   (opcional)
{
    /* code */
}
```

## sintaxe Switch

```c
switch (expression)
{
case constant expression:
    /* code */
    break;

default:  (opcional)
    /* code */
    break;
}
```

# Operador trenário
```txt
condição ? expressão(true) : expressão(false);
```
# Ciclos

## sintax While

```c
while (condition)
{
    /* code */
}
```

## sintax For

```c
for (inicializações,ini1,uini2; condição;pós-instrução)
{
    /* instrução */
}
```
Os 3 componenets do for são opcionais,sendo que pode ter: for(;;){}
 - na inicialização, só podem ser inicializadas variaveis do memso tipo.

## sintax do while

```c
do
{
    /* code */
} while (condition);
```
- Executa o do pelo menos uma vez.
- executa o que tem dentro de do enquanto o while for verdadeiro.
- Ótimo para menus.