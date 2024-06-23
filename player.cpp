#include "player.h"
#include <iostream>

Player::Player(const std::string& name) : name(name) {}

void Player::receiveCard(const Card& card) {
    hand.push_back(card);
}

void Player::showHand() const {
    std::cout << name << "'s hand:" << std::endl;
    for (const auto& card : hand) {
        std::cout << card.toString() << std::endl;
    }
}

void Player::clearHand() {
    hand.clear();
}
