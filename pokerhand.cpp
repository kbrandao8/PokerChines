#ifndef POKERHAND_HPP
#define POKERHAND_HPP

#include "card.h"
#include <vector>
#include <string>

class PokerHand {
public:
    virtual ~PokerHand() = default;
    virtual bool matches(const std::vector<Card>& hand) const = 0;
    virtual std::string getName() const = 0;
    virtual int getRank() const = 0;
};

class RoyalFlush : public PokerHand {
public:
    bool matches(const std::vector<Card>& hand) const override;
    std::string getName() const override;
    int getRank() const override;
};

class StraightFlush : public PokerHand {
public:
    bool matches(const std::vector<Card>& hand) const override;
    std::string getName() const override;
    int getRank() const override;
};

class FourOfAKind : public PokerHand {
public:
    bool matches(const std::vector<Card>& hand) const override;
    std::string getName() const override;
    int getRank() const override;
};

class FullHouse : public PokerHand {
public:
    bool matches(const std::vector<Card>& hand) const override;
    std::string getName() const override;
    int getRank() const override;
};

class Flush : public PokerHand {
public:
    bool matches(const std::vector<Card>& hand) const override;
    std::string getName() const override;
    int getRank() const override;
};

class Straight : public PokerHand {
public:
    bool matches(const std::vector<Card>& hand) const override;
    std::string getName() const override;
    int getRank() const override;
};

class ThreeOfAKind : public PokerHand {
public:
    bool matches(const std::vector<Card>& hand) const override;
    std::string getName() const override;
    int getRank() const override;
};

class TwoPair : public PokerHand {
public:
    bool matches(const std::vector<Card>& hand) const override;
    std::string getName() const override;
    int getRank() const override;
};

class OnePair : public PokerHand {
public:
    bool matches(const std::vector<Card>& hand) const override;
    std::string getName() const override;
    int getRank() const override;
};

class HighCard : public PokerHand {
public:
    bool matches(const std::vector<Card>& hand) const override;
    std::string getName() const override;
    int getRank() const override;
};

#endif // POKERHAND_HPP

