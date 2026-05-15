# Parametros de compilação
COMPILER = gcc
CFLAGS = -Wall
INCLUDE = -Iinclude

# pastas do projeto
BIN_PATH = bin/

# ficheiros fonte do projeto
SRC = \
	src/main.c \
	utils/aux_func.c \
	menu/main_menu.c \
	games/guess_game/guess_game.c \
	games/jogo_do_galo/jogo_do_galo.c

# nome do executável
EXEC = gamblingApp

all: build run

# executar
run: 
	./$(BIN_PATH)$(EXEC)

# compilar
build:
	mkdir -p $(BIN_PATH)
	$(COMPILER) $(CFLAGS) $(INCLUDE) $(SRC) -o $(BIN_PATH)$(EXEC)

# limpar
clear:
	rm -f $(BIN_PATH)$(EXEC)