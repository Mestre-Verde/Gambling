# Parametros de compilação
COMPILER = gcc
CFLAGS = -Wall
INCLUDE = -Iinclude

# pastas do projeto
BIN_PATH = bin/
BUILD_PATH = build/

# ficheiros fonte do projeto
SRC = \
	src/main.c \
	utils/aux_func.c \
	menu/main_menu.c \
	games/guess_game/guess_game.c \
	games/jogo_do_galo/jogo_do_galo.c

# transforma .c em .o dentro da pasta build/
OBJ = $(patsubst %.c,$(BUILD_PATH)%.o,$(SRC))

# nome do executável
EXEC = gamblingApp

.PHONY: build run clean

# executa o programa
run: 
	./$(BIN_PATH)$(EXEC)

# compila tudo e gera o executável
build: $(OBJ)
	mkdir -p $(BIN_PATH)
	$(COMPILER) $(OBJ) -o $(BIN_PATH)$(EXEC)

# regra genérica: cada .c vira um .o em build/
$(BUILD_PATH)%.o: %.c
	mkdir -p $(dir $@)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -c $< -o $@

# limpa ficheiros gerados
clean:
	rm -rf $(BIN_PATH) $(BUILD_PATH)