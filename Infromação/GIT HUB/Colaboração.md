# Colaboração em Git

## `git fetch`

### O que faz

O comando Git `git fetch` descarrega alterações do repositório remoto sem alterar os teus ficheiros locais.

Ele:

* atualiza informação das branches remotas
* descarrega commits novos
* NÃO faz merge automático



## Sintaxe

```bash id="nh5mko"
git fetch
```



## Exemplo

```bash id="3h9d40"
git fetch origin
```



## O que acontece

O Git:

* contacta o servidor remoto
* descarrega novos commits
* atualiza referências remotas

Mas:

* os teus ficheiros não mudam
* a tua branch atual continua igual



## Quando usar

Muito útil para:

* verificar alterações antes de integrar
* evitar merges inesperados
* analisar diferenças com segurança



## Ver diferenças após fetch

```bash id="4cq9s5"
git status
git log HEAD..origin/main
```



# `git pull`

## O que faz

O `git pull`:

1. executa `fetch`
2. integra as alterações

Normalmente usando merge.



## Sintaxe

```bash id="e8xvzn"
git pull
```



## O que acontece internamente

```text id="3lf63u"
git fetch
+
git merge
```



# Exemplo simples

```bash id="g09lnn"
git pull origin main
```



# Situação sem conflitos

Se ninguém alterou as mesmas linhas:

```text id="m1m34y"
Updating a1b2c3..d4e5f6
Fast-forward
```

O Git integra tudo automaticamente.



# Conflitos

Os conflitos acontecem quando:

* duas pessoas alteram a mesma zona do ficheiro
* Git não consegue decidir qual versão manter



# Exemplo de conflito

Tu alteraste:

```c id="3n5nmf"
printf("Olá");
```

Outra pessoa alterou:

```c id="vd8p5j"
printf("Hello");
```

Ao fazer:

```bash id="ngshtr"
git pull
```

O Git pode mostrar:

```text id="uw5a0e"
CONFLICT (content): Merge conflict in main.c
Automatic merge failed
```



# Como o ficheiro fica

```text id="xg7glf"
<<<<<<< HEAD
printf("Olá");
=======
printf("Hello");
>>>>>>> origin/main
```



# Significado

| Parte                 | Significado   |
|  | - |
| `<<<<<<< HEAD`        | tua versão    |
| `=======`             | separador     |
| `>>>>>>> origin/main` | versão remota |



# Resolver conflito

## 1. Editar manualmente

Escolher:

* uma versão
* ou combinar ambas

Exemplo:

```c id="4cf9tx"
printf("Olá / Hello");
```



## 2. Remover marcadores

Remover:

```text id="6r71ul"
<<<<<<<
=======
>>>>>>>
```



## 3. Adicionar novamente

```bash id="0j9ks8"
git add main.c
```



## 4. Finalizar merge

```bash id="hvjlwm"
git commit
```



# Cancelar merge

Se tudo correr mal:

```bash id="w8u90n"
git merge --abort
```

Isto tenta voltar ao estado anterior.



# `git push`

## O que faz

Envia commits locais para o repositório remoto.



## Sintaxe

```bash id="v1m81f"
git push
```



## Exemplo

```bash id="u6x5a0"
git push origin main
```



# O que acontece

O Git:

* envia commits
* envia objetos associados
* atualiza a branch remota



# Problema comum ao fazer push

Se alguém atualizou o remoto antes de ti:

```text id="ajk99j"
rejected
non-fast-forward
```



# Significado

O teu histórico:

* está desatualizado
* falta integrar commits remotos



# Solução correta

## 1. Buscar alterações

```bash id="0kcw1f"
git pull
```



## 2. Resolver conflitos se existirem



## 3. Enviar novamente

```bash id="nceep4"
git push
```



# Fluxo típico de colaboração

```text id="nlj4ow"
git pull
editar
git add
git commit
git push
```



# Diferença entre os comandos

| Comando     | Função                  |
| -- | -- |
| `git fetch` | Descarrega sem integrar |
| `git pull`  | Descarrega e integra    |
| `git push`  | Envia alterações locais |



# Resumo importante

## `fetch`

Seguro para inspecionar alterações.

## `pull`

Atualiza o projeto local.

## `push`

Publica os teus commits.

## Conflitos

Acontecem quando duas alterações afetam a mesma região do código.
