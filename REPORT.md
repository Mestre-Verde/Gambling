# **Relatório de Funcionamento**

# O começo do programa:

- O programa inica no ficheiro ([src/main.c](src/main.c)), mais especificamente na função `main()`.

Em praticamente todas as grandes funções elas retornam um tipo de valor. 

Convencionalmente em Linguagem C, 0 = sucesso, 1 = algo correu mal;

No menu principal há 2 submenus:
-   O menu de jogos, que só pode ser acedido que estiver selecionado um jogador.
-   O menu de jogador, onde se cria, elimina e escolhe o jogador.



## **Fluxo de execução**:
- **Entrada**: `src/main.c` inicia a aplicação e chama `mainMenu()` .
- **Menu Principal**: `menu/main_menu.c` apresenta opções e invoca `gamesMenu()` ou `playerMenu()` ([menu/main_menu.c](menu/main_menu.c)).
- **Menu de Jogos**: `menu/games_menu.c` lista jogos e chama `engineStartGame()` do motor ([menu/games_menu.c](menu/games_menu.c)).
- **Motor (Engine)**: `games/Engine.c` gere a escolha de dificuldade e lança o processo específico do jogo (Jogo do Galo, Guess, Blackjack, Memory) ([games/Engine.c](games/Engine.c)).
- **Persistência do jogador**: a estrutura `Player` e a variável global `currentPlayer` estão em `include/jogador.h` e `menu/main_menu.c` — os pontos atualizados são guardados com as funções em `FileManager` em `include/FileManager.h` (base em `base_de_dados/playerdb.bin`).

**Módulos principais e responsabilidades**:
- **`src/main.c`**: inicialização (semente aleatória) e entrada para `mainMenu()`.
- **`menu/main_menu.c`**: loop do menu principal e gestão da variável global `currentPlayer`.
- **`menu/games_menu.c`**: menu que permite escolher um jogo; delega para o `Engine`.
- **`games/Engine.c`**: lógica de preparação (dificuldade), invocação dos processos de jogo e acumulação de pontos.
- **`games/*`**: implementações dos jogos:
  - `games/jogo_do_galo/jogo_do_galo.c`
  - `games/guess_game/guess_game.c`
  - `games/Blackjack_game/blackjack_game.c`
  - `games/memory_game/memory_game.c`
- **`FileManager/FileManager.c`** e `include/FileManager.h`: operações de leitura/escrita na base de dados binária de jogadores.
- **`include/`**: cabeçalhos (APIs) e utilitários.



**Observações de funcionamento**:
- Os menus usam leitura de dígitos do utilizador (`readDigitUserInput`) e retornos de estado (0 = sucesso, >0 = erro/códigos específicos).
- Antes de iniciar um jogo que usa dificuldade, o `Engine` pede ao utilizador para escolher a dificuldade (Fácil/Média/Difícil).
- Após cada jogo, se forem obtidos pontos, estes são incrementados no `currentPlayer` e tentam ser salvos em `base_de_dados/playerdb.bin` via `savePlayerInDataBase()`.
- A variável global `currentPlayer` é usada para manter o jogador ativo durante a execução.

**Sugestões rápidas**:
- Validar e tratar melhor os retornos de erro da I/O binária para evitar perda de dados.
- Separar a definição de `currentPlayer` numa unidade dedicada (ex.: `src/player.c`) e expor apenas getters/setters, para reduzir dependências globais.
- Adicionar documentação nas funções públicas em `FileManager` para clarificar formatos e compatibilidade da base de dados.

**Referências rápidas (ficheiros chave)**:
- [src/main.c](src/main.c)
- [menu/main_menu.c](menu/main_menu.c)
- [menu/games_menu.c](menu/games_menu.c)
- [games/Engine.c](games/Engine.c)
- [include/jogador.h](include/jogador.h)
- [include/FileManager.h](include/FileManager.h)
- [Makefile](Makefile)

---
Relatório gerado automaticamente.
