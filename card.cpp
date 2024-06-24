#include "card.h"
#include <string>

Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

std::string Card::toString() const {
     static const std::string RANKS[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    static const std::string SUITS[] = {"H", "D", "C", "S"};

    return RANKS[rank] + SUITS[suit];
}

Rank Card::getRank() const {
    return rank;
}
Suit Card::getSuit() const {
    return suit;
}
bool Card::operator ==(const Card& other) const {

    return suit == other.suit && rank == other.rank;
}