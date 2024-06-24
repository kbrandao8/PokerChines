#ifndef POKERCHINES_H
#define POKERCHINES_H

#include "player.h"
#include "deck.h"
//#include "pokerhand.h"
#include <vector>
#include <string>

class pokerChines {
public:
    pokerChines();
    void start();

private:
    void setupPlayers();
    void dealCards();
    void playRound();
    void displayHands();
    void determineRoundStarter();
    void determineHandOfRound();

    Deck deck;
    std::vector<Player> players;
    int currentRoundStarter;
    std::string handOfRound;
};

#endif // POKERCHINES_H
