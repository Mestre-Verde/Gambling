
# 1. 🧠 Guia de Comandos Git e GitHub (Terminal - Avançado)

Este ficheiro serve como referência rápida dos comandos mais usados no Git, com explicações simples e exemplos práticos.



# 2. 🔧 Configuração Inicial

```bash
git config --global user.name "O Teu Nome"
git config --global user.email "teuemail@example.com"
```

Define identidade dos commits.




# 3. Repositórios

## 3.1. 📌 O que é um repositório?

Um repositório Git é uma pasta onde o Git guarda:

* histórico de versões
* commits
* branches
* alterações dos ficheiros

Existem dois tipos:

* 🟢 local → no teu PC
* 🔵 remoto → no GitHub

## 3.2. Criar repositório local

```bash
git init
```

### 3.2.1. 💡 O que acontece aqui?

Quando fazes `git init`:

* cria a pasta escondida `.git/`
* começa a rastrear ficheiros
* ainda NÃO existe GitHub envolvido



### 3.2.2.  Exemplo 

```bash
mkdir projeto
cd projeto
git init
```

Agora essa pasta já é um repositório Git.



###  3.2.3. ⚠️ Importante

Depois de `git init`:

* nada é enviado automaticamente
* tens de fazer `git add` + `commit`



# 4. Clonar repositório

```bash
git clone <url>
```

## 4.1.  O que isto faz?

* copia um repositório remoto
* traz todo o histórico
* cria uma pasta local


## 4.2. Exemplo

```bash
git clone https://github.com/user/projeto.git
```

Vai criar:

```
projeto/
├── .git/
├── ficheiros do projeto
```



## 4.3. 🔥 Importante

Clonar ≠ descarregar ZIP

| Clonar            | ZIP         |
| ----------------- | ----------- |
| tem histórico Git | não tem Git |
| permite commits   | não permite |
| permite push      | não permite |



# 5.  Clonar branch específica

```bash
git clone -b <branch> <url>
```

## 5.1. 💡 O que isto faz?

* clona o repositório
* mas já abre numa branch específica



## 5.2. 📦 Exemplo

```bash
git clone -b dev https://github.com/user/projeto.git
```

👉 abre diretamente na branch `dev`



## 5.3. ⚠️ Nota importante

Mesmo assim:

* todas as branches são descarregadas
* só a branch ativa muda



## 5.4.  Conceito importante (muito importante mesmo)

Quando clonas:

👉 estás a criar um repositório local ligado a um remoto

Ou seja:

```
PC (local repo) ↔ GitHub (remote repo)
```


Depois de clonar:

```bash
git clone <url>
cd projeto
git add .
git commit -m "alteração"
git push
```



Depois de clonar, verifica sempre:

```bash
git remote -v
```

Isso mostra:

* onde estás ligado
* para onde vais fazer push/pull




# 6. 📌 3. Estado e histórico

```bash
git status
git log
```

Histórico gráfico:

```bash
git log --oneline --graph --decorate --all
```


# 7. ➕  Adicionar ficheiros (Staging Area)

O que isto significa? O Git não grava diretamente as alterações no histórico. Ele tem 3 zonas:

```text
Working Directory → Staging Area → Repository
```



## 7.1. 📦 O que faz o `git add`

👉 Move ficheiros para a **Staging Area**

Ou seja:

* ainda NÃO está guardado no histórico
* só está “preparado para commit”


### 7.1.1. Adicionar ficheiro específico

```bash
git add main.c
```

👉 só esse ficheiro vai para o commit



### 7.1.2. Adicionar tudo

```bash
git add .
```

👉 adiciona:

* ficheiros novos
* ficheiros alterados
* ficheiros removidos



# 8. 💾 Commit (Guardar versão)

## 8.1. 📌 Comando

```bash
git commit -m "mensagem"
```


com este comando o Git cria uma **versão permanente** no histórico.


Um commit guarda:

* estado dos ficheiros
* autor
* data/hora
* mensagem
* hash único (ID)



## 8.2. Exemplo 

```bash
git commit -m "corrigido bug no inventário"
```



## 8.3.  O que acontece por trás

```text
Staging Area → Snapshot → Git History
```



## 8.4. ⚠️ Regra importante

Se não fizeres `git add`, isto não funciona, vai dizer:

> nothing to commit



## 8.5.  Fluxo  (isto tens de memorizar)

```bash
git add .
git commit -m "mensagem"
git push
```



## 8.6. 💡 Dica profissional

Mensagens de commit boas:

✔️ “adiciona sistema de login”
✔️ “corrige erro de memória”
❌ “fix”
❌ “update”



## 8.7. 🚀 Resumo mental

* `git add` → escolher o que vai entrar na versão
* `git commit` → criar a versão
* Git guarda “fotografias” do projeto





# 9. 🔄 6. GitHub (Sincronização)

Aqui começa a ligação entre o teu PC e o repositório remoto no GitHub.

O Git passa a ter 2 mundos:

```text id="v8c8kx"
VS Code (local)  ↔  GitHub (remoto)
```

---

## 9.1. 📌 6.1 Ligar repositório remoto

```bash id="q3p9fs"
git remote add origin <url>
```

### 9.1.1. 💡 O que isto faz?

Quando corres isto no terminal do VS Code:

* estás a dizer ao Git:

  > “este projeto local tem um destino no GitHub”

---

### 9.1.2.  Na prática

Depois disto:

* o VS Code já sabe para onde fazer push/pull
* é criada uma ligação chamada `origin`

---

### 9.1.3. ⚠️ Nota importante

* `origin` = nome padrão do remoto
* não é obrigatório, mas é convenção

---

## 9.2. 🚀 6.2 Enviar alterações (push)

```bash id="p3x0qk"
git push
```

### 9.2.1. 💡 O que acontece no VS Code?

Quando fazes push:

1. VS Code envia os teus commits locais
2. Git empacota tudo
3. envia para o GitHub
4. o repositório remoto é atualizado

---

### 9.2.2. 📦 Resultado

👉 O que tens no PC aparece no GitHub

---

### 9.2.3. ⚠️ Importante

Só funciona se:

* já tiveres commits feitos
* remoto estiver configurado

---

## 9.3. 🆕 6.3 Primeira vez (push inicial)

```bash id="6z8c3p"
git push -u origin main
```

### 9.3.1. 💡 O que isto faz?

* envia a branch `main` para o GitHub
* diz ao Git:

  > “da próxima vez já sabes para onde enviar automaticamente”

---

### 9.3.2. 📌 Depois disto

Podes só fazer:

```bash id="m8d2xh"
git push
```

sem escrever `origin main`

---

## 9.4. 📥 6.4 Receber alterações (pull)

```bash id="zq9l2a"
git pull
```

### 9.4.1. 💡 O que acontece no VS Code?

Quando fazes pull:

1. Git vai ao GitHub
2. vê se há alterações novas
3. descarrega e junta ao teu código local

---

### 9.4.2. 📦 Na prática

👉 Atualiza o teu projeto local com código remoto

---

### 9.4.3. ⚠️ Situação comum

Se outra pessoa mexeu no repo:

* o VS Code vai mostrar conflitos
* tens de escolher qual versão fica

---

## 9.5. 🔁 6.5 Rebase (histórico limpo)

```bash id="t1n4qk"
git pull --rebase
```

### 9.5.1. 💡 O que muda?

Em vez de misturar históricos:

* o Git primeiro traz mudanças do GitHub
* depois “encaixa” os teus commits por cima

---

### 9.5.2. 🧠 Resultado

Histórico fica:

```text id="g7k1xv"
linear (limpo)
```

em vez de:

```text id="c9p2ld"
ramificado (confuso)
```

---

## 9.6. ⚠️ 6.6 Forçar push (perigoso)

```bash id="w0q8mz"
git push --force
```

### 9.6.1. 💥 O que isto faz mesmo?

👉 Sobrescreve o GitHub com o teu código local

---

### 9.6.2. 🚨 Na prática

No VS Code:

* apaga mudanças remotas
* substitui tudo pelo teu histórico

---

### 9.6.3. ❗ Quando isto é usado?

* reescrever commits
* corrigir histórico errado
* limpar branch

---

### 9.6.4. ⚠️ PERIGO REAL

Se trabalhas com outras pessoas:

* podes apagar trabalho delas

---

## 9.7. 🧠 Resumo mental (muito importante)

| Comando      | O que acontece no VS Code             |
| ------------ | ------------------------------------- |
| `remote add` | liga projeto ao GitHub                |
| `push`       | envia código                          |
| `push -u`    | primeira ligação completa             |
| `pull`       | traz código do GitHub                 |
| `rebase`     | traz código sem confusão no histórico |
| `force`      | substitui tudo no GitHub              |


# 10. 🌿 7. Branches

```bash
git branch
git branch nome
git checkout nome
git checkout -b nome
```

Eliminar branch remota:

```bash
git push origin --delete nome
```



# 11. 🔀 8. Merge

```bash
git merge branch
git merge --squash branch
```



# 12. ❌ 9. Undo / Reset

```bash
git reset ficheiro
git checkout -- ficheiro
git reset --soft HEAD~1
git reset --hard HEAD~1
git revert <commit>
git reflog
```



# 13. 🔧 11. Diferenças

```bash
git diff
git diff commit1 commit2
```



# 14. 🎯 12. Remotos

```bash
git remote -v
git remote set-url origin <url>
```



# 15. 🏷️ 13. Tags

```bash
git tag v1.0
git push --tags
```



# 16. 📦 14. Stash

```bash
git stash
git stash list
git stash pop
```



# 17. 🧹 15. Limpeza

```bash
git branch --merged
git branch -d nome
git clean -n
git clean -f
git remote prune origin
```



# 18. 🚀 16. Rebase Interativo

```bash
git rebase -i HEAD~N
```

Opções:

* pick → manter
* reword → editar mensagem
* squash → juntar commits
* fixup → juntar sem mensagem



# 19. 🔗 17. Submodules

```bash
git submodule add <url> <path>
git submodule update --init --recursive
```



# 20. 🏷️ 18. Staging avançado

```bash
git add -p
git commit --amend
git reset --mixed HEAD~1
```



# 21. 🔎 19. Pesquisa

```bash
git grep "texto"
git blame ficheiro
```



# 22. ℹ️ 20. Ajuda

```bash
git help
git help commit
```


