/* FileManager.c
Ficheiro com as funções responsáveis por os streams.
Para mexer com ficheiros externos é necessário chamar funções genéricas aqui.

*/
#include <stdio.h>
#include <stdbool.h>
#include "jogador.h"
#include "aux_func.h"

#define PLAYERDB_DIR "base_de_dados/playerdb.bin"

int checkDataBase(FILE *file)
{
    // verifica se o enderesso existe
    if (file == NULL)
    {
        return 1;
    }

    // verifica se o ficheiro está vazio
    int caracter = fgetc(file);

    if (caracter == EOF)
    {
        fclose(file);
        return 2;
    }

    return 0;
}

int savePlayerInDataBase(Player player, char PATH[])
{
    // guarda o stream em um ponteiro do tipo struct FILE
    FILE *f = fopen(PATH, "ab");

    // verifica o ficheiro
    int estado = checkDataBase(f);

    switch (estado)
    {
    case 0: // O ficheiro tinha algo escrito.
        break;

    case 1:
        LOG_ERROR("O ficheiro no qual se tentou escrever não existe! \"%s\"", PATH);
        return 1;

    case 2:
        LOG_WARN("O ficheiro no qual se escreveu estava vazio. \"%s\"", PATH);
        break;
    }

    // Escreve a struct completa no ficheiro
    size_t escritos = fwrite(&player, sizeof(Player), 1, f);

    fclose(f);

    // Verifica se escreveu exatamente 1 registo
    return (escritos == 1) ? 0 : 1;
}

/**
 * @brief Lista todos os jogadores registados na base de dados
 * @return 0 em sucesso, 1 em erro
 */
int listPlayersInDataBase(bool withIndex)
{
    FILE *f = fopen(PLAYERDB_DIR, "rb");

    if (f == NULL)
    {
        return 1;
    }

    Player player;
    unsigned int index = 0;

    while (fread(&player, sizeof(Player), 1, f) == 1)
    {
        if (withIndex)
        {
            printf("\n[%u]", index);
        }

        showPlayerInfo(player);
        index++;
    }

    fclose(f);

    return 0;
}

int getNextPlayerId(unsigned short int *nextId)
{
    FILE *f = fopen(PLAYERDB_DIR, "rb");

    // Se o ficheiro não existe, primeiro ID
    if (f == NULL)
    {
        *nextId = 1;
        LOG_INFO("Parabéns é o primeiro jogador a registar-se!");
        return 0;
    }

    Player player;

    // Vai diretamente tentar ler o último registo
    if (fseek(f, -(long)sizeof(Player), SEEK_END) != 0 || fread(&player, sizeof(Player), 1, f) != 1)
    {
        fclose(f);
        return 1;
    }

    fclose(f);
    LOG_DEBUG("Ultimo Id Obtido: %hu, retornado %hu", player.id, player.id + 1);
    *nextId = player.id + 1;
    return 0;
}