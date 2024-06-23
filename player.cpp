#include "player.h"
#include <iostream>

Player::Player(const std::string& name) : name(name) {}

void Player::addCard(const Card& card) {
    hand.push_back(card);
    }
void Player::clearHand() {
    hand.clear();
    }
std::vector<Card> Player::getHand() const {
    return hand;
    }

std::string Player::getName() const {
    return name;
    }