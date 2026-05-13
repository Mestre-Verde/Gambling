COMPILER = Gcc
CFLAGS = -Wall

BIN_PATH = bin/
BUILD_PATH = build/

SRC = \
	src/main.c \
	utils/aux_func.c \
	Menu/menu.c

GAMES_SRC = \
	guess_game/guess_game.c \
	jogo_do_galo/main_logic.c

ALL_SRC = $(SRC) $(GAMES_SRC)

EXEC = gamblingApp

# criar pasta bin se não existir + compilar
build:
	mkdir -p $(BIN_PATH)
	$(COMPILER) $(CFLAGS) $(ALL_SRC) -o $(BIN_PATH)$(EXEC)

compile: 
	mkdir -p $(BUILD_PATH)
	cria objetos e guarda em build

run: build
	./$(BIN_PATH)$(EXEC)

clean:
	rm -f $(BIN_PATH)$(EXEC)