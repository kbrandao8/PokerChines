#ifndef POKERHAND_H
#define POKERHAND_H

#include "card.h"
#include <vector>
#include <string>

// Declaração da classe base PokerHand
class PokerHand {
public:
    virtual ~PokerHand() = default;
    virtual bool matches(const std::vector<Card>& hand) const = 0;  // Verifica se a mão corresponde a este tipo de jogada
    virtual std::string getName() const = 0;  // Retorna o nome da jogada
    virtual int getRank() const = 0;  // Retorna o rank da jogada
};

// Declarações das classes derivadas para cada tipo de jogada
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

#endif // POKERHAND_H
