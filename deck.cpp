#include "deck.h"
#include <algorithm>
#include <random>
#include <ctime>

// Implementação do construtor
Deck::Deck() {
    // Inicializa o baralho com todas as cartas
    for (int suit = static_cast<int>(Suit::HEARTS); suit <= static_cast<int>(Suit::SPADES); ++suit) {
        for (int rank = static_cast<int>(Rank::TWO); rank <= static_cast<int>(Rank::ACE); ++rank) {
            cards.emplace_back(static_cast<Suit>(suit), static_cast<Rank>(rank));
        }
    }
    // Embaralha o baralho ao inicializar
    shuffle();
}

// Implementação do método shuffle
void Deck::shuffle() {
    // Gera um gerador de números aleatórios baseado no tempo atual
    auto rng = std::default_random_engine(std::time(nullptr));
    // Embaralha o vetor de cartas
    std::shuffle(cards.begin(), cards.end(), rng);
}

// Implementação do método dealCard
Card Deck::dealCard() {
    // Remove e retorna a carta do topo do baralho
    Card dealtCard = cards.back();
    cards.pop_back();
    return dealtCard;
}

// Implementação do método isEmpty
bool Deck::isEmpty() const {
    // Retorna true se o baralho estiver vazio, false caso contrário
    return cards.empty();
}

// Implementação do método reset
void Deck::reset() {
    // Limpa o vetor de cartas
    cards.clear();
    // Re-inicializa o baralho com todas as cartas
    for (int suit = static_cast<int>(Suit::HEARTS); suit <= static_cast<int>(Suit::SPADES); ++suit) {
        for (int rank = static_cast<int>(Rank::TWO); rank <= static_cast<int>(Rank::ACE); ++rank) {
            cards.emplace_back(static_cast<Suit>(suit), static_cast<Rank>(rank));
        }
    }
    // Embaralha o baralho novamente
    shuffle();
}
