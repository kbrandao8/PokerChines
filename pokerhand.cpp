#include "pokerchines.h"
#include <algorithm>
#include <iostream>
#include <ctime>
//#include <map>
//#include <set>

pokerChines::pokerChines(const std::vector<std::string>& playerNames) 
    : currentRoundStarter(0), handOfRound(""), scores(playerNames.size(), 0) {
    setupPlayers(playerNames);
}

void pokerChines::setupPlayers(const std::vector<std::string>& playerNames) {
    for (const auto& name : playerNames) {
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
    std::cout << "Determining hand of the round...\n";
    // Placeholder for determining the hand of the round
}

bool pokerChines::isValidMove(const std::vector<Card>& cards) {
    // Implement logic to validate the move according to the hand of the round
    return true; // Placeholder return
}

void pokerChines::displayScores() {
    std::cout << "Current Scores:\n";
    for (size_t i = 0; i < players.size(); ++i) {
        std::cout << players[i].getName() << ": " << scores[i] << "\n";
    }
}

bool pokerChines::promptEndGame() {
    std::cout << "Do you want to end the game? (yes/no): ";
    std::string input;
    std::cin >> input;
    return input == "yes";
}

void pokerChines::playRound() {
    std::cout << "Playing round...\n";
    // Placeholder for playing a round logic
}

void pokerChines::playGame() {
    bool endGame = false;
    while (!endGame) {
        dealCards();
        determineRoundStarter();
        playRound();
        for (auto& player : players) {
            // Update scores based on remaining cards
            scores[&player - &players[0]] += player.getHand().size();
            player.clearHand();
        }
        displayScores();
        endGame = promptEndGame();
        if (!endGame) {
            for (const auto& score : scores) {
                if (score >= 25) {
                    endGame = true;
                    break;
                }
            }
        }
    }

    std::cout << "Final Scores:\n";
    displayScores();

    int minScore = *std::min_element(scores.begin(), scores.end());
    std::vector<std::string> winners;
    for (size_t i = 0; i < players.size(); ++i) {
        if (scores[i] == minScore) {
            winners.push_back(players[i].getName());
        }
    }

    if (winners.size() == 1) {
        std::cout << "The winner is: " << winners[0] << "\n";
    } else {
        std::cout << "The winners are: ";
        for (const auto& winner : winners) {
            std::cout << winner << " ";
        }
        std::cout << "\n";
    }
}
