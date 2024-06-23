#include "pokerchines.h"
#include <iostream>

pokerChines::pokerChines(const std::vector<std::string>& playerNames) {
    for (const auto& name : playerNames) {
        players.emplace_back(name);
    }
    pokerHands.push_back(new RoyalFlush());
    // Adicione outras mãos de pôquer aqui
}

void pokerChines::playRound() {
    deck.shuffle();
    dealCards();
    showHands();
    determineWinner();
    for (auto& player : players) {
        player.clearHand();
    }
}

void pokerChines::dealCards() {
    for (int i = 0; i < 5; ++i) {
        for (auto& player : players) {
            player.addCard(deck.dealCard());
        }
    }
}

void pokerChines::showHands() const {
    for (const auto& player : players) {
        std::cout << player.getName() << "'s hand: ";
        for (const auto& card : player.getHand()) {
            std::cout << card.toString() << " ";
        }
        std::cout << std::endl;
    }
}

PokerHand* pokerChines::determineHand(const std::vector<Card>& hand) const {
    for (const auto& pokerHand : pokerHands) {
        if (pokerHand->matches(hand)) {
            return pokerHand;
        }
    }
    return nullptr;
}

void pokerChines::determineWinner() {
    Player* winner = nullptr;
    PokerHand* bestHand = nullptr;

    for (auto& player : players) {
        PokerHand* currentHand = determineHand(player.getHand());
        if (!bestHand || (currentHand && currentHand->getRank() > bestHand->getRank())) {
            bestHand = currentHand;
            winner = &player;
        }
    }

    if (winner && bestHand) {
        std::cout << "Winner is " << winner->getName() << " with a " << bestHand->getName() << std::endl;
    } else {
        std::cout << "No winner this round." << std::endl;
    }
}
