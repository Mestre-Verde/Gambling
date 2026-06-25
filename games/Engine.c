/**
 * Engine.c
 *
 * Este ficheiro funciona como o "launcher" dos jogos.
 *
 * O objetivo é centralizar aqui a ligação entre:
 * - menu de jogos;
 * - jogador atual;
 * - dificuldade;
 * - execução dos jogos;
 * - atualização dos pontos;
 * - gravação na base de dados.
 *
 * Assim, os ficheiros dos jogos não mexem diretamente no jogador.
 * Eles apenas devolvem os pontos ganhos através do ponteiro "points".
 * O Engine é o ficheiro que faz a ligação entre o menu, os jogos e o jogador atual.
 * Ele recebe o jogo escolhido, pergunta a dificuldade quando necessário, chama a função principal do jogo e recebe os pontos ganhos através de um ponteiro.
 * Depois soma esses pontos ao jogador atual e guarda os dados na base de dados.
 * Desta forma, os jogos não precisam de alterar diretamente o jogador.
 */

#include <stdio.h>

#include "aux_func.h"

#include "Engine.h"
#include "FileManager.h"
#include "jogador.h"

#include "guess_game.h"
#include "jogo_do_galo.h"
#include "pedra_papel_tesoura.h"
#include "memory_game.h"

Difficulty chooseDifficulty(void) // função da dificuldade
{
    const char MenuText[] =
        "\nEscolha a dificuldade desta partida:\n" BG_GREEN COLOR_BLACK " 1 - Fácil" COLOR_RESET "\n" BG_YELLOW COLOR_BLACK " 2 - Média" COLOR_RESET "\n" BG_RED COLOR_WHITE " 3 - Difícil" COLOR_RESET "\n" COLOR_WHITE " 0 - Voltar ao menu\n" COLOR_RESET;

    printf("%s", MenuText);

    int choice = DIFFICULTY_UNKNOWN; // começa com DIFFICULTY_UNKNOWN, para que se o utilizador introduzir algo invalido, este valor manter-se
    if (readDigitUserInput("Insira a sua escolha: ", &choice))
    {
        return DIFFICULTY_UNKNOWN; // se houver algum erro na leitura devolve DIFFICULTY_UNKNOWN
    }

    switch (choice) // Verifica se a escolha corresponde a uma dificuldade válida e converte o inteiro para um enum Dificulty
    {
    case DIFFICULTY_EXIT:
    case EASY:
    case MEDIUM:
    case HARD:
        return (Difficulty)choice;

    default:
        return DIFFICULTY_UNKNOWN;
    }
}

int engineStartGame(GamesMenuOptions game)
{
    unsigned long int points = 0;               // variavel onde ficam guradados os pontos ganhos durante o jogo atual
    Difficulty difficulty = DIFFICULTY_UNKNOWN; // variavel para armazenar a dificuldade. começa como desconhecida até que o utizador escolher uma opção válida

    // obtem a dificuldade do jogador
    if (game == GUESS_GAME || game == MEMORY_GAME) // só estes jogos pedem dificuilade
    {
        do
        {
            // obtem a dificuldade que o user escolher
            difficulty = chooseDifficulty();

            if (difficulty == DIFFICULTY_UNKNOWN)
            {
                puts(COLOR_GOLD "Entrada inválida." COLOR_RESET);
            }

        } while (difficulty == DIFFICULTY_UNKNOWN); // ciclo: mostra erro enquanto que o utilizador não escolher um dificuldade válida

        if (difficulty == DIFFICULTY_EXIT)
        {
            return 0; // volta ao menu sem iniciar jogo nenhum
        }
    }

    // inicia o processo principal do menu principal
    /*
     * Aqui o Engine verifica qual foi o jogo escolhido e chama a função principal desse jogo.
     *
     * Cada jogo devolve:
     * 0 -> terminou bem
     * diferente de 0 -> houve erro
     */
    switch (game)
    {
    case JOGO_DO_GALO:
        if (galoMainProcess())
        {
            LOG_ERROR("Houve um problema com o jogo do galo!"); // este jogo não usa dificuldade
            return 1;
        }
        LOG_INFO("Processo do jogo do galo terminado com sucesso.");
        break;

    case GUESS_GAME:
        if (guess_main_process(difficulty, currentPlayer.pontos_guess, &points))
        {
            return 2;
        }
        LOG_INFO("Processo do jogo da adivinha terminado com sucesso.");
        break;

    case PEDRA_PAPEL_TESOURA:
        if (main_process_pedra_papel_tesoura(currentPlayer.pedra_papel_tesouraPoints, &points)) // este jogo não usa dificulade
        {
            return 3;
        }
        LOG_INFO("Processo do jogo Pedra,Papel,Tesoura terminado com sucesso.");
        break;

    case MEMORY_GAME:
        if (memory_game_main_process(difficulty, currentPlayer.memoryPoints, &points))
        {
            return 4;
        }
        LOG_INFO("Processo do Memory Game terminado com sucesso.");
        break;

    case GAMES_MENU_EXIT:
    case GAMES_MENU_UNKNOWN:
        LOG_WARN("EXIT ou UNKNOWN do menu anterior entrou no engine!!");
        return 5;

    default:
        LOG_WARN("Jogo desconhecido entrou no engine.Valor:%i", game);
        return 5;
    }

    // se tiver pontos incrementa-os na secção respetiva
    /*
     * Se o jogo devolveu pontos maiores que 0,
     * significa que o jogador ganhou pontos.
     *
     * Agora o Engine tem de somar esses pontos
     * ao campo correto dentro do currentPlayer.
     */
    if (points > 0) // se o jogo devolver pontos maior que 0
    {
        // LOG_DEBUG("Há pontos, a guardar no jogador.Nº de pontos:%lu", points);

        switch (game)
        {
        case GUESS_GAME:
            currentPlayer.pontos_guess += points; // soma os pontos ao total do guess game
            break;

        case PEDRA_PAPEL_TESOURA:
            currentPlayer.pedra_papel_tesouraPoints += points; // soma os pontos ao total do pedra_papel_tesoura
            break;

        case MEMORY_GAME:
            currentPlayer.memoryPoints += points; // soma os pontos ao total do memory game
            break;
        default: // os erros já são tratados no switch do processo de jogos
            break;
        }
        if (savePlayerInDataBase(currentPlayer, PLAYERDB_DIR)) // depois de atualizar os pontos, guarda os pontos na base de dados
        {
            LOG_ERROR("Não foi possivel salvar o jogador na base de dados.");
        }
    }
    else if (points < 0) // como points é unsigned long int, (unsigned significa sem negativos) logo (points < 0) numca vai acontecer
    {
        LOG_WARN("Detetados Pontos negativos! Jogo: %i |pontos: %lu.", game, points);
        return 6;
    }

    return 0;
}

