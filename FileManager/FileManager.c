/* FileManager.c
Ficheiro com as funções responsáveis por os streams.
Para mexer com ficheiros externos é necessário chamar funções genéricas aqui.

O id de um jogador tem o valor minimo de 1.

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

    // Se o tamanho for 0, o ficheiro está vazio
    if (size == 0)
    {
        return 2; // ficheiro vazio
    }

    return 0; // ficheiro existe e tem conteúdo
}

int savePlayerInDataBase(Player player, char PATH[])
{
    // Abre ficheiro em modo append binário
    FILE *f = fopen(PATH, "ab");

    if (f == NULL)
    {
        LOG_ERROR("Não foi possível abrir o ficheiro \"%s\"", PATH);
        return 1;
    }

    // Escreve o jogador no final do ficheiro
    size_t escritos = fwrite(&player, sizeof(Player), 1, f);

    fclose(f);

    // Confirma escrita
    return (escritos == 1) ? 0 : 1;
}

int listPlayersInDataBase(bool withIndex, char PATH[])
{
    FILE *f = fopen(PATH, "rb");

    if (f == NULL)
    {
        LOG_DEBUG("Ficheiro não existe.");
        return 1;
    }

    int estado = checkDataBase(f);

    if (estado)
    {
        LOG_DEBUG("Sem jogadores para listar.");
        fclose(f);
        return 0;
    }

    // voltar ao início para leitura
    rewind(f);

    Player player;

    while (fread(&player, sizeof(Player), 1, f) == 1)
    {
        if (withIndex)
        {
            printf("\n[%u]", player.id);
        }

        showPlayerInfo(player);
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

    if (estado == 2)
    {
        // ficheiro vazio
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

    LOG_DEBUG("Último ID: %hu → próximo: %hu", player.id, *nextId);

    return 0;
}