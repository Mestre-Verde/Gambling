/* FileManager.c
Ficheiro com as funções responsáveis por os streams.
Para mexer com ficheiros externos é necessário chamar funções genéricas aqui.

*/
#include <stdio.h>
#include "jogador.h"
#include "aux_func.h"

#define PLAYERDB_DIR "base_de_dados/playerdb.bin"

int savePlayerInDataBase(Player player)
{
    FILE *f = fopen(PLAYERDB_DIR, "ab");

    // Ficheiro não existe
    if (f == NULL)
    {
        return 1;
    }

    // Escreve a struct completa no ficheiro
    size_t escritos = fwrite(&player, sizeof(Player), 1, f);

    fclose(f);

    // Verifica se escreveu exatamente 1 registo
    return (escritos == 1) ? 0 : 1;
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

    Player last;

    // Vai diretamente tentar ler o último registo
    if (fseek(f, -(long)sizeof(Player), SEEK_END) != 0 || fread(&last, sizeof(Player), 1, f) != 1)
    {
        fclose(f);
        return 1;
    }

    fclose(f);
    LOG_DEBUG("Ultimo Id Obtido: %hu, retornado %hu", last.id, last.id + 1);
    *nextId = last.id + 1;
    return 0;
}