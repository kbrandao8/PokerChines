#include "deck.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <stdexcept> // out_of_range

Deck::Deck() : currentCardIndex(0) {
    for (int suit = HEARTS; suit <= SPADES; ++suit) {
        for (int rank = TWO; rank <= ACE; ++rank) {
            cards.emplace_back(static_cast<Rank>(rank), static_cast<Suit>(suit));
        }
    }
    shuffle();
}

void Deck::shuffle() {
    std::srand(static_cast<unsigned int>(std::time(0)));
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
