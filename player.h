#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>

class Player {
public:
    Player(const std::string & name);
    void receiveCard(const Card & card);
    void showHand() const;
    void clearHand();

private:
    std::string name;
    std::vector<Card> hand;
};

#endif // PLAYER_H