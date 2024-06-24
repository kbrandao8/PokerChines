#include "player.h"
#include <iostream>

Player::Player(const std::string& name) : name(name), skipping(false) {}
const std::string& Player::getName() const {
    return name;
}
void Player::addCard(const Card& card) {
    hand.push_back(card);
    }
bool Player::hasCard(const Card& card) const {
    for (const auto& c : hand) {
        if (c.getSuit() == card.getSuit() && c.getRank() == card.getRank()) {
            return true;
        }
    }
    return false;
}
void Player::showHand() const {
    for (const auto& card : hand) {
        std::cout << card.toString() << " ";
        }
    std::cout << "\n";
}
const std::vector<Card>& Player::getHand() const {
    return hand;
}
void Player::clearHand() {
    hand.clear();
}

bool Player::isSkipping() const {
    return skipping;
}

void Player::setSkipping(bool skip) {
    skipping = skip;
}