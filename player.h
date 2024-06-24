#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>
#include <string>

class Player {
public:
    Player(const std::string& name);
    void addCard(const Card& card);
    void showHand() const;
    bool hasCard(const Card& card) const;
    const std::string& getName() const;

private:
    std::string name;
    std::vector<Card> hand;
};

#endif // PLAYER_H