# 1. `git status`

## 1.1. O que faz

O comando Git `git status` mostra o estado atual do repositório.

Permite ver:

* ficheiros modificados
* ficheiros preparados (*staged*)
* ficheiros não rastreados (*untracked*)
* branch atual



## 1.2. Sintaxe

```bash
git status
```



## 1.3. Exemplo — repositório limpo

```bash
git status
```

Saída:

```text
On branch main
nothing to commit, working tree clean
```

Significa:

* não existem alterações
* tudo está sincronizado



## 1.4. Exemplo — ficheiro modificado

```bash
git status
```

Saída:

```text
Changes not staged for commit:
  modified: main.c
```

Significa:

* o ficheiro foi alterado
* ainda não foi preparado para commit



## 1.5. Exemplo — ficheiro staged

Após:

```bash
git add main.c
```

```bash
git status
```

Saída:

```text
Changes to be committed:
  modified: main.c
```

Significa:

* o ficheiro está pronto para commit



## 1.6. Exemplo — ficheiro não rastreado

```bash
git status
```

Saída:

```text
Untracked files:
  novo.txt
```

Significa:

* o Git ainda não controla esse ficheiro



## 1.7. Versão curta

```bash
git status --short
```

Exemplo:

```text
M main.c
?? novo.txt
```

Significados:

* `M` → modified
* `??` → untracked



# 2. `git add`

### 2.0.1. O que faz

Adiciona alterações à staging area.



### 2.0.2. Sintaxe

```bash
git add ficheiro.txt
```



### 2.0.3. Exemplo

```bash
git add main.c
```



# 3. `git restore`

## 3.1. O que faz

Restaura alterações de ficheiros.



## 3.2. Sintaxe

```bash
git restore ficheiro.txt
```



## 3.3. Exemplo

```bash
git restore main.c
```

Descarta alterações não staged.



# 4. `git rm`

## 4.1. O que faz

Remove ficheiros do Git e do disco.



## 4.2. Sintaxe

```bash
git rm ficheiro.txt
```



## 4.3. Exemplo

```bash
git rm teste.txt
```



# 5. `git mv`

## 5.1. O que faz

Move ou renomeia ficheiros.



## 5.2. Sintaxe

```bash
git mv antigo.txt novo.txt
```



## 5.3. Exemplo

```bash
git mv app.c main.c
```

Renomeia:

* `app.c`
* para `main.c`
