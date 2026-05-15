# compilador
COMPILER = gcc
CFLAGS = -Wall
INCLUDE = -Iinclude

# nome do executável
EXEC = gamblingApp

# ficheiros fonte
SRC = \
	src/main.c \
	utils/aux_func.c \
	menu/main_menu.c \
	games/guess_game/guess_game.c \
	games/jogo_do_galo/jogo_do_galo.c

# deteção do sistema operativo
ifeq ($(OS),Windows_NT)

	BIN_PATH = bin\\
	TARGET = $(BIN_PATH)$(EXEC).exe

	MKDIR = if not exist bin mkdir bin
	REMOVE = del /Q

	RUN = $(TARGET)

else

	BIN_PATH = bin/
	TARGET = $(BIN_PATH)$(EXEC)

	MKDIR = mkdir -p bin
	REMOVE = rm -f

	RUN = ./$(TARGET)

endif

all: build run

# compilar
build:
	$(MKDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) $(SRC) -o $(TARGET)

# executar
run:
	$(RUN)

# limpar
clear:
	$(REMOVE) $(TARGET)

