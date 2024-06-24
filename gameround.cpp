#include "gameround.h"

// Implementação do construtor
GameRound::GameRound()
    : handOfRound(Card(Suit::HEARTS, Rank::TWO)) {} // Inicializando com uma carta padrão

// Implementação do método setHandOfRound
void GameRound::setHandOfRound(const Card& card) {
    handOfRound = card;
}

// Implementação do método getHandOfRound
Card GameRound::getHandOfRound() const {
    return handOfRound;
}

// Implementação do método isValidMove
bool GameRound::isValidMove(const std::vector<Card>& cards) const {
    // Implementação da validação da jogada conforme a "mão da rodada"
    // Aqui será necessário comparar as cartas jogadas com a "mão da rodada"
    return true; // Implementação de exemplo
}
