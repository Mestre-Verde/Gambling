COMPILER = gcc
CFLAGS = -Wall
INCLUDE = -Iinclude
BIN_PATH = bin/

SRC = \
	src/main.c \
	utils/aux_func.c \
	Menu/menu.c

GAMES_SRC = \
	games/guess_game/guess_game.c \
	games/jogo_do_galo/jogo_do_galo.c

ALL_SRC = $(SRC) $(GAMES_SRC)

EXEC = gamblingApp

.PHONY: build run clean

build:
	mkdir -p $(BIN_PATH)
	$(COMPILER) $(CFLAGS) $(ALL_SRC) $(INCLUDE) -o $(BIN_PATH)$(EXEC)

run: build
	./$(BIN_PATH)$(EXEC)

clean:
	rm -f $(BIN_PATH)$(EXEC)