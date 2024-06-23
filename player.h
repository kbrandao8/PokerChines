#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>

class Player {
public:
    Player(const std::string& name);
    void addCard(const Card& card);
    void clearHand();
    std::vector<Card> getHand() const;
    std::string getName() const;

private:
    std::string name;
    std::vector<Card> hand;
};

#endif // PLAYER_H