#include "pokerchines.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

// Implementação do construtor
pokerChines::pokerChines(const std::vector<std::string>& playerNames)
    : players(playerNames.size()), deck(), currentRoundStarter(0), winnerIndex(-1), currentRound(1), scores(playerNames.size(), 0) {
    for (size_t i = 0; i < playerNames.size(); ++i) {
        players[i].setName(playerNames[i]);
    }
}

// Implementação do método playGame
void pokerChines::playGame() {
    while (!promptEndGame()) {
        dealCards();
        determineRoundStarter();
        determineHandOfRound();
        playRound();
        displayScores();
        currentRound++;
        for (Player& player : players) {
            player.clearHand();
        }
    }
}

// Implementação do método dealCards
void pokerChines::dealCards() {
    deck.shuffle();
    for (int i = 0; i < 13; ++i) {
        for (Player& player : players) {
            player.addToHand(deck.dealCard());
        }
    }
}

// Implementação do método determineRoundStarter
void pokerChines::determineRoundStarter() {
    if (currentRound == 1) {
        // Primeira rodada da partida: jogador com a carta 3 de ouros inicia
        for (size_t i = 0; i < players.size(); ++i) {
            if (players[i].getHand().end() != std::find(players[i].getHand().begin(), players[i].getHand().end(), Card(Suit::DIAMONDS, Rank::THREE))) {
                currentRoundStarter = i;
                std::cout << "Iniciando primeira rodada com jogador: " << players[currentRoundStarter].getName() << std::endl;
                return;
            }
        }
        // Se nenhum jogador tiver a carta 3 de ouros, não é possível iniciar a rodada
        std::cerr << "Erro: Nenhum jogador possui a carta 3 de ouros para iniciar a primeira rodada." << std::endl;
    } else {
        // Demais rodadas: o vencedor da última rodada inicia
        currentRoundStarter = winnerIndex;
        std::cout << "Iniciando rodada com jogador: " << players[currentRoundStarter].getName() << std::endl;
    }
}

// Implementação do método determineHandOfRound
void pokerChines::determineHandOfRound() {
    // Implementação lógica para determinar a "mão da rodada"
    // Exemplo básico: sempre será a "mão" da maior carta presente no início
    currentGameRound.setHandOfRound(Card(Suit::HEARTS, Rank::ACE)); // Exemplo
}

// Implementação do método playRound
void pokerChines::playRound() {
    // Implementação lógica para a rodada de jogo
    // Exemplo básico: apenas exibindo quem inicia e termina a rodada
    std::cout << "Rodada em andamento..." << std::endl;
    std::cout << "Jogador inicial: " << players[currentRoundStarter].getName() << std::endl;
    // Lógica de jogo...
    // Definir o vencedor da rodada
    winnerIndex = currentRoundStarter;
}

// Implementação do método isValidMove
bool pokerChines::isValidMove(const std::vector<Card>& cards) {
    // Implementação da validação da jogada conforme as regras da "mão da rodada"
    // Aqui será necessário comparar as cartas jogadas com a "mão da rodada"
    return true; // Implementação de exemplo
}

// Implementação do método promptEndGame
bool pokerChines::promptEndGame() {
    // Implementação lógica para perguntar se o jogo deve terminar
    // Aqui pode ser implementada uma verificação de critério de aceitação da User Story 10
    return false; // Implementação de exemplo
}

// Implementação do método displayScores
void pokerChines::displayScores() {
    // Implementação para exibir os pontos acumulados pelos jogadores
    std::cout << "Pontuações:" << std::endl;
    for (size_t i = 0; i < players.size(); ++i) {
        std::cout << players[i].getName() << ": " << scores[i] << " pontos" << std::endl;
    }
}
