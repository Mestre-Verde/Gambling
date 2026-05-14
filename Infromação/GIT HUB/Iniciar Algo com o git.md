# Iniciar uma área de trabalho Git

## `git clone`

### O que faz

O comando Git `git clone` copia um repositório existente para uma nova pasta.



## Sintaxe

```bash
git clone URL
```



## Exemplo

```bash
git clone https://github.com/exemplo/projeto.git
```



## O que acontece

O Git:

* descarrega o repositório
* cria a pasta do projeto
* copia o histórico completo
* configura o repositório remoto



## Pasta criada

```text
projeto/
```

Dentro dela existe:

```text
.git/
```

A pasta `.git` contém:

* commits
* branches
* configuração
* histórico



# `git init`

## O que faz

Cria um novo repositório Git vazio.

Também pode reinicializar um já existente.



## Sintaxe

```bash
git init
```



## Exemplo

```bash
mkdir projeto
cd projeto
git init
```



## Exemplo de saída

```text
Initialized empty Git repository
```



## O que acontece

O Git cria:

```text
.git/
```

Essa pasta contém toda a estrutura interna do Git.



## Após o `git init`

O projeto ainda:

* não tem commits
* não tem ficheiros tracked

Normalmente o fluxo continua assim:

```bash
git add .
git commit -m "Primeiro commit"
```



# Diferença entre `clone` e `init`

| Comando     | Função                         |
| ----------- | ------------------------------ |
| `git clone` | Copia um repositório existente |
| `git init`  | Cria um repositório novo vazio |



# Fluxo comum

## Novo projeto

```bash
mkdir app
cd app
git init
```



## Projeto existente online

```bash
git clone URL
```
