/* FileManager.c
Ficheiro com as funções responsáveis por os streams.
Para mexer com ficheiros externos é necessário chamar funções genéricas aqui.

O id de um jogador tem o valor minimo de 1.
pois um id = 0  é util como NO PLAYER SELECTED

*/
#include <stdio.h>
#include <stdbool.h>

#include "jogador.h"
#include "aux_func.h"
#include "FileManager.h"

int checkDataBase(FILE *file)
{
    // Verifica se o ponteiro do ficheiro é válido
    if (file == NULL)
    {
        return 1; // erro: ficheiro não existe / não foi aberto
    }

    // Vai para o fim do ficheiro para medir o tamanho
    fseek(file, 0, SEEK_END);

    // ftell devolve o tamanho atual do ficheiro em bytes
    long size = ftell(file);

    rewind(file);
    // Se o tamanho for 0, o ficheiro está vazio
    if (size == 0)
    {
        return 2; // ficheiro vazio
    }

    return 0; // ficheiro existe e tem conteúdo
}

int savePlayerInDataBase(Player player, char PATH[])
{
    FILE *original = fopen(PATH, "rb");
    FILE *temp = fopen(TEMP_FILE_PATH, "wb");

    if (temp == NULL)
    {
        LOG_ERROR("Não foi possível criar ficheiro temporário");
        return 1;
    }

    bool found = false;

    // Se a base de dados existir
    if (original != NULL)
    {
        Player current;

        while (fread(&current, sizeof(Player), 1, original) == 1)
        {
            // Encontrou o mesmo ID -> substitui
            if (current.id == player.id)
            {
                fwrite(&player, sizeof(Player), 1, temp);
                found = true;
            }
            else
            {
                fwrite(&current, sizeof(Player), 1, temp);
            }
        }

        fclose(original);
    }

    // Se não encontrou o jogador, adiciona no fim
    if (!found)
    {
        fwrite(&player, sizeof(Player), 1, temp);
    }

    fclose(temp);

    // Remove original
    if (remove(PATH))
    {
        LOG_ERROR("Não foi possivel remover o ficheiro.");
        return 1;
    }

    // Renomeia temporário
    if (rename(TEMP_FILE_PATH, PATH))
    {
        LOG_ERROR("Não foi possível substituir a base de dados");
        return 1;
    }

    return 0;
}

int listPlayersInDataBase(bool withIndex, char PATH[])
{
    FILE *f = fopen(PATH, "rb");

    if (f == NULL)
    {
        LOG_ERROR("Ficheiro não existe.");
        return 1;
    }
    int estado = checkDataBase(f);

    if (estado)
    {
        LOG_INFO("Sem jogadores para listar.");
        fclose(f);
        return -1;
    }

    Player player;

    while (fread(&player, sizeof(Player), 1, f) == 1)
    {
        if (withIndex)
        {
            printf("\n" COLOR_BRIGHT_CYAN "[%u]" COLOR_RESET, player.id);
        }
        showPlayerInfo(player, 1);
    }

    fclose(f);

    return 0;
}

int getNextPlayerId(unsigned short int *nextId, char PATH[])
{
    FILE *f = fopen(PATH, "rb");

    // Se ficheiro não existe → primeiro ID
    if (f == NULL)
    {
        *nextId = 1;
        LOG_INFO("Primeiro jogador a registar-se!");
        return 0;
    }

    int estado = checkDataBase(f);
    // ficheiro vazio
    if (estado == 2)
    {
        *nextId = 1;
        fclose(f);
        return 0;
    }

    Player player;

    // Vai ao último registo
    if (fseek(f, -(long)sizeof(Player), SEEK_END) != 0 || fread(&player, sizeof(Player), 1, f) != 1)
    {
        fclose(f);
        return 1;
    }

    fclose(f);

    *nextId = player.id + 1;

    // LOG_DEBUG("Último ID: %hu → próximo: %hu", player.id, *nextId);

    return 0;
}

int removePlayerFromDB(const unsigned short int id, char PATH[])
{
    // abre o ficheiro em modo leitura binario
    FILE *file = fopen(PATH, "rb");

    // verifica  o estado do ficheiro
    int estado = checkDataBase(file);

    if (estado == 1)
    {
        return 1;
    }
    else if (estado == 2)
    {
        LOG_INFO("Não há jogadores para remover na base de dados.");
        return 0;
    }

    // cria ficheiro temporário
    FILE *tempFile = fopen(TEMP_FILE_PATH, "wb");

    if (tempFile == NULL)
    {
        fclose(file);
        LOG_ERROR("Não foi possível criar o ficheiro temporário.");
        return 1;
    }

    Player player;

    bool found = false;

    // lê jogador a jogador
    while (fread(&player, sizeof(Player), 1, file) == 1)
    {
        // LOG_DEBUG("Id encontrado: %hu", player.id);

        //  ignora jogador a remover
        if (player.id == id)
        {
            found = true;
            continue;
        }

        // copia jogador para ficheiro temporário
        fwrite(&player, sizeof(Player), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    // jogador não encontrado
    if (!found)
    {
        remove(TEMP_FILE_PATH);
        return -1;
    }

    // Remove original
    if (remove(PATH))
    {
        LOG_ERROR("Não foi possivel remover o ficheiro.");
        return 1;
    }

    // Renomeia temporário
    if (rename(TEMP_FILE_PATH, PATH))
    {
        LOG_ERROR("Não foi possível substituir a base de dados");
        return 1;
    }

    return 0;
}

int findAndGetPlayerInDB(const unsigned short int id, Player *player, char PATH[])
{
    // abre base de dados
    FILE *file = fopen(PATH, "rb");

    // verifica estado do ficheiro
    int estado = checkDataBase(file);

    // verifica se existe o ficheiro
    if (estado == 1)
    {
        return 1;
    }

    Player playerTmp;

    // lê jogador a jogador, usando o endereço passado como arg
    while (fread(&playerTmp, sizeof(Player), 1, file) == 1)
    {
        // encontrou jogador
        if (playerTmp.id == id)
        {
            *player = playerTmp;
            return 0;
        }
    }

    fclose(file);

    return -1;
}