#ifndef POKERCHINES_H
#define POKERCHINES_H

#include "player.h"
#include "deck.h"
#include "pokerhand.h"
#include <vector>

class pokerChines {
public:
    pokerChines(const std::vector<std::string>& playerNames);
    void playRound();
    void showHands() const;
    void determineWinner();

private:
    std::vector<Player> players;
    Deck deck;
    std::vector<PokerHand*> pokerHands;

    void dealCards();
    PokerHand* determineHand(const std::vector<Card>& hand) const;
};

#endif // POKERCHINES_H
