#include "player.h"
#include <iostream>
#include <algorithm>

Player::Player(const std::string& name) : name(name) {}

void Player::addCard(const Card& card) {
    hand.push_back(card);
    }
void Player::showHand() const {
    for (const auto& card : hand) {
        std::cout << card.toString() << " ";
        }
    std::cout << "\n";
}
bool Player::hasCard(const Card& card) const {
    return std::find(hand.begin(), hand.end(), card) != hand.end();
}

const std::string& Player::getName() const {
     return name;
}