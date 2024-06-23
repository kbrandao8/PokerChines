#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <algorithm>
#include <random>

class Deck {
public:
    Deck();
    void shuffle();
    Card dealCard();
    bool isEmpty() const;
    void reset();

private:
    std::vector<Card> cards;
    int currentCardIndex;
    void initializeDeck();
};

#endif // DECK_H
