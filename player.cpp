#include "player.h"
#include <algorithm>

// Implementação do construtor
Player::Player(const std::string& playerName)
    : name(playerName) {}

// Implementação do método getName
std::string Player::getName() const {
    return name;
}

// Implementação do método setName
void Player::setName(const std::string& playerName) {
    name = playerName;
}

// Implementação do método getHand
std::vector<Card> Player::getHand() const {
    return hand;
}

// Implementação do método setHand
void Player::setHand(const std::vector<Card>& cards) {
    hand = cards;
}

// Implementação do método addToHand
void Player::addToHand(const Card& card) {
    hand.push_back(card);
}

// Implementação do método removeFromHand
void Player::removeFromHand(const Card& card) {
    auto it = std::find(hand.begin(), hand.end(), card);
    if (it != hand.end()) {
        hand.erase(it);
    }
}

// Implementação do método clearHand
void Player::clearHand() {
    hand.clear();
}

// Implementação do método playCards
std::vector<Card> Player::playCards() {
    // Implementação de exemplo: o jogador joga todas as cartas da mão
    std::vector<Card> cardsPlayed = hand;
    clearHand();
    return cardsPlayed;
}

// Implementação do método hasCards
bool Player::hasCards() const {
    return !hand.empty();
}
