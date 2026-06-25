/*
 * guess_game.c
 * Implementação do jogo da adivinha (Guess Game).
 * Responsabilidades:
 * - Gerar o número secreto (inteiro ou decimal dependendo da dificuldade)
 * - Ler palpites do utilizador e validar formatos
 * - Calcular pontos com base em tentativas (calculateGuessPoints)
 * Funções principais: `guess_main_process`, `calculateGuessPoints`, `parseHardGuess`.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include "guess_game.h"
#include "jogador.h"
#include "aux_func.h"
#include "colors.h"

/**
 * @brief função para calcular os pontos com base em tentativas
 * @param difficulty dificuldade do jogo
 * @param attemptsUsed nº de tentativas.
 * @param finalPoints ponteiro para a variavel que armazena os pontos locais.
 * @return 0 se sucesso, 1 se ocorreu um problema.
 */
int calculateGuessPoints(Difficulty difficulty, int attemptsUsed, unsigned long int *finalPoints)
{
    int basePoints;      // pontos base
    int penalPerAttempt; // penalização por tentativa

    switch (difficulty) // define os pontos base e a penalização por tentativa com base na dificuldade
    {
    case EASY:
        basePoints = 100;
        penalPerAttempt = 10;
        break;

    case MEDIUM:
        basePoints = 150;
        penalPerAttempt = 15;
        break;

    case HARD:
        basePoints = 250;
        penalPerAttempt = 25;
        break;

    default:
        LOG_WARN("Recebida uma dificuldade não listada. Valor:%i", difficulty); // Se chegar aqui, significa que a dificuldade não é válida.
        return 1;
    }

    // CaLcula os pontos finais
    // A tenttativa em que o jogador acerta não é penalizada, por isso usamos (attemptsUsed - 1) na fórmula.
    int totalPoints = basePoints - ((attemptsUsed - 1) * penalPerAttempt);

    // LOG_DEBUG("Pontos totais: %i - (%i - 1) x %i = %i", basePoints, attemptsUsed, penalPerAttempt, totalPoints);
    if (totalPoints < 0)
    {
        totalPoints = 0;
    }

    *finalPoints = (unsigned long int)totalPoints; // Guarda os pontos calculados na variavel original(finalPoints) recebida por um ponteiro.
    return 0;
}

/**
 * @brief Converte uma string em um numero decimal para a dificuldade dificil. exemlo: "12.34" -> 1234, ou seja a string é convertida para um inteiro multiplicado por 100.
 * @details A função valida se a string está no formato correto, com no máximo 2 casas decimais.
 * @param buffer string a converter.
 * @param guessValue ponteiro para a variavel a substituir.
 * @return 0 se sucesso, 1 se o formato não é o correto.
 */
int parseHardGuess(const char buffer[], int *guessValue)
{
    int i = 0;             // índice para percorrer a string
    int integerPart = 0;   // parte inteira do número
    int decimalPart = 0;   // parte decimal do número
    int decimalDigits = 0; // conta quantos dígitos decimais foram lidos

    if (!isDigit(buffer[i])) // O primeiro caractere tem de ser um digito, se não for dá erro.
    {
        return 1;
    }

    while (isDigit(buffer[i])) // lê a parte inteira do número;  exemplo: "12.34" -> lê o "12"
    {
        integerPart = integerPart * 10 + (buffer[i] - '0');
        i++;
    }

    if (buffer[i] == '.' || buffer[i] == ',') // verifica se há um ponto ou vírgula indicando a parte decimal
    {
        i++; // salta o ponto ou vírgula

        while (isDigit(buffer[i])) // lê a parte decimal do número; exemplo: "12.34" -> lê o "34"
        {
            if (decimalDigits >= 2) // se houver mais de 2 dígitos decimais, retorna erro, porque o formato não é válido.
            {
                return 1; // exemplo: "12.345" -> inválido
            }

            decimalPart = decimalPart * 10 + (buffer[i] - '0'); // acumula os dígitos decimais; EX: "12.34" -> decimalPart = 3*10 + 4 = 34
            decimalDigits++;                                    // incrementa o contador de dígitos decimais
            i++;                                                // avança para o próximo caractere
        }

        if (decimalDigits == 1) // se houver apenas 1 dígito decimal, multiplica por 10 para manter o formato de 2 dígitos; exemplo: "12.3" -> decimalPart = 3*10 = 30
        {
            decimalPart *= 10; // ajusta para ter 2 dígitos decimais EX
        }
    }

    *guessValue = integerPart * 100 + decimalPart; // converte para um inteiro multiplicado por 100; exemplo: "12.34" -> 12*100 + 34 = 1234
    return 0;
}

const char *getGuessDifficultyName(Difficulty difficulty) // ENUM para string, retorna o nome da dificuldade em português.
{
    switch (difficulty)
    {
    case EASY:
        return "Fácil";

    case MEDIUM:
        return "Mádia";

    case HARD:
        return "Difícil";

    default:
        return "Desconhecida";
    }
}

void printGuessHeader(Difficulty difficulty, int minValue, int maxNumber, bool isHard) // imprime o cabeçalho do jogo da adivinha com informações sobre a dificuldade e o intervalo de números
{
    printf(TEXT_BOLD COLOR_BRIGHT_CYAN "\n========================================\n" COLOR_RESET);
    printf(TEXT_BOLD COLOR_BRIGHT_CYAN "             JOGO DA ADIVINHA\n" COLOR_RESET);
    printf(TEXT_BOLD COLOR_BRIGHT_CYAN "========================================\n" COLOR_RESET);

    printf(COLOR_YELLOW "Dificuldade: %s\n" COLOR_RESET, getGuessDifficultyName(difficulty));

    if (isHard)
    {
        printf(COLOR_BRIGHT_WHITE "Tenta adivinhar um numero decimal entre " COLOR_BRIGHT_GREEN "%d.00" COLOR_RESET COLOR_BRIGHT_WHITE " e " COLOR_BRIGHT_GREEN "%d.00\n" COLOR_RESET,
               minValue, maxNumber);
    }
    else
    {
        printf(COLOR_BRIGHT_WHITE "Tenta adivinhar um numero inteiro entre " COLOR_BRIGHT_GREEN "%d" COLOR_RESET COLOR_BRIGHT_WHITE " e " COLOR_BRIGHT_GREEN "%d\n" COLOR_RESET,
               minValue, maxNumber);
    }

    printf(TEXT_BOLD COLOR_BRIGHT_CYAN "========================================\n" COLOR_RESET);
}

int guess_main_process(const Difficulty difficulty, const unsigned long int currentPoints, unsigned long int *points)
{
    // define o numero máximo que pode gerar
    const bool isHard = difficulty == HARD;        // verifica se a dificuldade é difícil, para definir o intervalo de números e o formato de entrada (decimal ou inteiro)
    int maxNumber = isHard ? 200                   // para dificuldade difícil, o número máximo é 200. O número secreto será gerado entre 1.00 e 200.00 (multiplicado por 100 para facilitar a manipulação como inteiro) ex: "200.00" -> 20000
                           : (int)difficulty * 50; // ou seja, para dificuldade fácil, o número máximo é 50, e para dificuldade média, o número máximo é 100. O número secreto será gerado entre 1 e maxNumber. ex: dificuldade fácil -> maxNumber = 50, dificuldade média -> maxNumber = 100

    const int MIN_VALUE = 1; // valor minimo

    // Variavel com o valor a adivinhar
    int secretNumber = isHard ? rand() % ((maxNumber - 1) * 100 + MIN_VALUE) + 100 // exemplo se for dificulade dificil; gera um número aleatório entre 100 e 20000, que representa o intervalo de 1.00 a 200.00 (multiplicado por 100 para facilitar a manipulação como inteiro). A fórmula rand() % ((maxNumber - 1) * 100 + MIN_VALUE) + 100 garante que o número gerado esteja dentro desse intervalo.
                              : rand() % maxNumber + 1;                            // se não for decimal, gera um número aleatório entre 1 e maxNumber (ex: dificuldade fácil -> 1 a 50, dificuldade média -> 1 a 100)

    bool guessed = false; // variavel que guarda o valor se o jogador advinhou
    int attemptsUsed = 0; // contador de tentativas

    // imprime as introduções ao jogo
    printGuessHeader(difficulty, MIN_VALUE, maxNumber, isHard);
    while (!guessed) // enquanto o jogador não adivinhar o número secreto, continua a pedir palpites
    {
        // LOG_DEBUG("secret number: %d | maxNumber:%i |attemptsUsed:%i | isHard: %d", secretNumber, maxNumber, attemptsUsed, isHard);

        // var para guardar a entrada do user.
        int guess = 0;

        printf(TEXT_BOLD COLOR_BRIGHT_CYAN "\n---------- TENTATIVA %d ----------\n" COLOR_RESET, attemptsUsed + 1);

        if (isHard) // se a dificuldade for difícil, espera-se um número decimal, então chama a função parseHardGuess para validar o formato da entrada.
        {
            const int MAX_BUFFER_LEN = (10 + 1);
            char buffer[MAX_BUFFER_LEN];
            if (readStrUserInput("Insira o seu palpite (S para sair)", MAX_BUFFER_LEN, buffer, 0, "") == 1)
            {
                return 1;
            }
            //  verifica se é para sair do jogo
            if (toLower(buffer[0]) == 's')
            {
                // é considerado desistencia, pontos = 0
                return 0;
            }
            if (parseHardGuess(buffer, &guess)) // converte a string para um número decimal multiplicado por 100, e valida se o formato está correto. Se não estiver, retorna erro.
            {
                LOG_INFO("Número decimal inválido. Formato: 00.00");
                continue;
            }

            if (!isBetween(guess, 100, maxNumber * 100)) // verifica se o número está dentro do intervalo aceitável (1.00 a maxNumber.00), multiplicado por 100 para facilitar a manipulação como inteiro.
            {
                LOG_INFO("O número deve estar entre 1.00 e %d.00.\n", maxNumber);
                continue;
            }
        }
        else // se a dificuldade não for difícil, espera-se um número inteiro, então chama a função readDigitUserInput para ler e validar a entrada do usuário.
        {
            int inputStatus = readDigitUserInput("Insira o seu palpite (-1 para sair): ", &guess); // guarda o palpite do usuário na variável guess, e retorna o status da leitura (0 se sucesso, -1 se inválido, 1 se erro)
            switch (inputStatus)
            {
            case -1:
                puts("Entrada inválida."); // se a entrada for inválida (ex: apenas enter), informa o usuário e continua o loop para pedir outro palpite.
                continue;

            case 0:
                if (guess == -1) // verifica se é para sair.
                {
                    // é considerado desistencia, pontos = 0
                    return 0;
                }
                // verifica se a entrada está dentro do intervalo aceitável.
                if (!isBetween(guess, MIN_VALUE, maxNumber))
                {
                    LOG_INFO("O número deve estar entre 1 e %d.\n", maxNumber);
                    continue;
                }
                break;

            case 1:       //
                return 1; // erro na leitura do input, retorna 1 para indicar falha.

            default:
                LOG_WARN("Valor desconhecido de readDigitInput. Valor:%i", inputStatus);
                return 1;
            }
        }

        attemptsUsed++; // incrementa o contador de tentativas usadas

        if (guess < secretNumber)
        {
            puts(COLOR_BLUE "Muito baixo! Tenta outra vez." COLOR_RESET);
        }

        else if (guess > secretNumber)
        {
            puts(COLOR_RED "Muito alto! Tenta outra vez." COLOR_RESET);
        }
        else
        {
            if (calculateGuessPoints(difficulty, attemptsUsed, points))
            {
                return 1;
            }

            printf(TEXT_BOLD COLOR_BRIGHT_GREEN "\n========================================\n" COLOR_RESET);
            printf(TEXT_BOLD COLOR_BRIGHT_YELLOW "              ACERTASTE!\n" COLOR_RESET);
            printf(TEXT_BOLD COLOR_BRIGHT_GREEN "========================================\n" COLOR_RESET);

            if (isHard)
            {
                printf(COLOR_BRIGHT_WHITE "Numero secreto: " COLOR_GOLD "%d.%02d\n" COLOR_RESET,
                       secretNumber / 100, secretNumber % 100);
            }
            else
            {
                printf(COLOR_BRIGHT_WHITE "Numero secreto: " COLOR_GOLD "%d\n" COLOR_RESET, secretNumber);
            }

            printf(COLOR_BRIGHT_WHITE "Tentativas usadas: " COLOR_GOLD "%d\n" COLOR_RESET, attemptsUsed);
            printf(COLOR_BRIGHT_WHITE "Pontos ganhos: " COLOR_BRIGHT_GREEN "%lu\n" COLOR_RESET, *points);
            printf(COLOR_BRIGHT_WHITE "Total do jogador no Guess Game: " COLOR_BRIGHT_CYAN "%lu\n" COLOR_RESET, currentPoints + *points);

            printf(TEXT_BOLD COLOR_BRIGHT_GREEN "========================================\n" COLOR_RESET);

            guessed = true;
        }
    }
    return 0;
}
