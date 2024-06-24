#ifndef POKERCHINES_H
#define POKERCHINES_H

#include "player.h"
#include "deck.h"
//#include "pokerhand.h"
#include <vector>
#include <string>

class pokerChines {
public:
    pokerChines(const std::vector<std::string>& playerNames);
    void playRound();
    void playGame();

private:
    void setupPlayers(const std::vector<std::string>& playerNames);
    void dealCards();
    void determineRoundStarter();
    void determineHandOfRound();
    bool isValidMove(const std::vector<Card>& cards);
    void displayScores();
    bool promptEndGame();

    Deck deck;
    std::vector<Player> players;
    int currentRoundStarter;
    std::string handOfRound;
    std::vector<int> scores;
};

#endif // POKERCHINES_H
