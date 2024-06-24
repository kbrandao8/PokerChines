#ifndef POKERCHINES_H
#define POKERCHINES_H

#include <vector>
#include <string>
#include "player.h"
#include "deck.h"
#include "gameround.h"

// Declaração da classe pokerChines
class pokerChines {
public:
    // Construtor que inicializa o jogo com os nomes dos jogadores
    pokerChines(const std::vector<std::string>& playerNames);

    // Método que inicia o jogo
    void playGame();

    // Método que distribui as cartas para os jogadores
    void dealCards();

    // Método que determina quem começa a rodada
    void determineRoundStarter();

    // Método que determina a "mão da rodada"
    void determineHandOfRound();

    // Método que joga uma rodada
    void playRound();

    // Método que verifica se uma jogada é válida
    bool isValidMove(const std::vector<Card>& cards);

    // Método que pergunta se o jogo deve terminar
    bool promptEndGame();

    // Método que exibe as pontuações dos jogadores
    void displayScores();

private:
    // Vetor que armazena os jogadores
    std::vector<Player> players;

    // Baralho de cartas
    Deck deck;

    // Rodada atual do jogo
    GameRound currentGameRound;

    // Índice do jogador que começa a rodada
    int currentRoundStarter;

    // Índice do jogador vencedor da rodada
    int winnerIndex;

    // Número da rodada atual
    int currentRound;

    // Vetor que armazena as pontuações dos jogadores
    std::vector<int> scores;

    // Método que distribui as cartas (duplicado, deve ser removido)
    // void dealCards();
};

#endif // POKERCHINES_H
