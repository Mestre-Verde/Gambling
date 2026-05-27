# compilador
COMPILER := gcc
CFLAGS := -Wall
INCLUDE := -Iinclude

# nome do executável
EXEC := gamblingApp

# ficheiros fonte
SRC_MAIN := \
	src/main.c \
	src/setup.c \
	src/jogador.c \
	utils/aux_func.c

MENU_SRC := \
	menu/main_menu.c \
	menu/player_menu.c

GAME_SRC := \
	games/guess_game/guess_game.c \
	games/jogo_do_galo/jogo_do_galo.c
# games/Engine.c 

FILE_MANAGER := \
	FileManager/FileManager.c

	 
SRC = $(SRC_MAIN) $(MENU_SRC) $(GAME_SRC) $(FILE_MANAGER)

# pasta de build
BUILD_PATH := build

# deteção do sistema operativo
ifeq ($(OS),Windows_NT)
	TARGET := $(BUILD_PATH)/$(EXEC).exe

	MKDIR := if not exist $(BUILD_PATH) mkdir $(BUILD_PATH)
	REMOVE := del /Q

	RUN := $(TARGET)
else
	TARGET := $(BUILD_PATH)/$(EXEC)

	MKDIR := mkdir -p $(BUILD_PATH)
	REMOVE := rm -f

	RUN := ./$(TARGET)
endif

.PHONY: all build run clean clear

all: build run

# compilar
build:
	$(MKDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) $(SRC) -o $(TARGET)

# executar
run:
	$(RUN)

# limpar
clean:
	$(REMOVE) $(TARGET)

clear: clean