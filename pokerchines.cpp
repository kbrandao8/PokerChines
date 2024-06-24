#include "pokerchines.h"
#include <iostream>
#include <algorithm>
#include <ctime>

pokerChines::pokerChines() : currentRoundStarter(0), handOfRound("") {}

void pokerChines::start() {
    setupPlayers();
    dealCards();
    determineRoundStarter();
    playRound();
}

void pokerChines::setupPlayers() {
    int numPlayers = 4;
    for (int i = 0; i < numPlayers; ++i) {
        std::string name;
        std::cout << "Enter name for player " << i + 1 << ": ";
        std::cin >> name;
        players.emplace_back(name);
    }
}

void pokerChines::dealCards() {
    deck.shuffle();
    for (int i = 0; i < 13; ++i) {
        for (auto& player : players) {
            player.addCard(deck.dealCard());
        }
    }
    displayHands();
}

void pokerChines::playRound() {
    // Placeholder for playing a round logic
    std::cout << "Playing round...\n";
}

void pokerChines::displayHands() {
    for (const auto& player : players) {
        std::cout << player.getName() << "'s hand:\n";
        player.showHand();
    }
}

void pokerChines::determineRoundStarter() {
    for (size_t i = 0; i < players.size(); ++i) {
        if (players[i].hasCard(Card(Suit::DIAMONDS, Rank::THREE))) {
            currentRoundStarter = i;
            break;
        }
    }
    std::cout << "The player to start the round is: " << players[currentRoundStarter].getName() << "\n";
}

void pokerChines::determineHandOfRound() {
    // Placeholder for determining the hand of the round
    std::cout << "Determining hand of the round...\n";
}
