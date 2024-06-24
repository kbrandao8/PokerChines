#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>
#include <string>

class Player {
public:
    Player(const std::string& name);
    const std::string& getName() const;
    void addCard(const Card& card);
    bool hasCard(const Card& card) const;
    void showHand() const;
    const std::vector<Card>& getHand() const;
    void clearHand();
    bool isSkipping() const;
    void setSkipping(bool skip);

private:
    std::string name;
    std::vector<Card> hand;
    bool skipping;
};

#endif // PLAYER_H