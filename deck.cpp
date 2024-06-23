#include "deck.h"
#include <ctime>
#include <cstdlib>

Deck::Deck() {
    initializeDeck();
    shuffle();
}

void Deck::initializeDeck() {
    cards.clear();
    for (int suit = HEARTS; suit <= SPADES; ++suit) {
        for (int rank = TWO; rank <= ACE; ++rank) {
            cards.push_back(Card(static_cast<Suit>(suit), static_cast<Rank>(rank)));
        }
    }
    currentCardIndex = 0;
}

void Deck::shuffle() {
    std::srand(std::time(0));
    std::random_shuffle(cards.begin(), cards.end());
    currentCardIndex = 0;
}

Card Deck::dealCard() {
    if (!isEmpty()) {
        return cards[currentCardIndex++];
    }
    throw std::out_of_range("No more cards in the deck");
}

bool Deck::isEmpty() const {
    return currentCardIndex >= cards.size();
}

void Deck::reset() {
    initializeDeck();
    shuffle();
}
