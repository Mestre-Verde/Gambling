# compilador
COMPILER := gcc
CFLAGS := -Wall
INCLUDE := -Iinclude

# nome do executável
EXEC := gamblingApp

# ficheiros fonte
SRC_MAIN := src/main.c src/jogador.c

AUX_SRC := utils/aux_func.c utils/aux_string.c

MENU_SRC :=	\
	menu/main_menu.c \
	menu/player_menu.c \
	menu/games_menu.c

GAME_SRC := \
	games/guess_game/guess_game.c \
	games/jogo_do_galo/jogo_do_galo.c\
	games/Blackjack_game/blackjack_game.c \
	games/memory_game/memory_game.c \
    games/Engine.c 

FILE_MANAGER := FileManager/FileManager.c

	 
SRC = $(SRC_MAIN) $(AUX_SRC) $(MENU_SRC) $(GAME_SRC) $(FILE_MANAGER)

# pasta de build
BUILD_PATH := build

# deteção do sistema operativo
ifeq ($(OS),Windows_NT)
# make no windows é mingw32-make 

# chcp 65001  
# [Console]::OutputEncoding = [System.Text.Encoding]::UTF8
# $OutputEncoding = [System.Text.Encoding]::UTF8

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

.PHONY: all build run clean

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

backup:
	zip -r ~/Transferências/projeto_backup.zip .
