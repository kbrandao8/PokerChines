#include "card.h"
#include <iostream>

// Implementação do construtor
Card::Card(Suit suit, Rank rank) : suit(suit), rank(rank) {}

// Implementação do método getSuit
Suit Card::getSuit() const {
    return suit;
}

// Implementação do método getRank
Rank Card::getRank() const {
    return rank;
}

// Implementação do método toString
std::string Card::toString() const {
    // Vetores de strings para representar os naipes e os valores das cartas
    static const std::string suits[] = { "Copas", "Ouros", "Paus", "Espadas" };
    static const std::string ranks[] = { "", "", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Valete", "Rainha", "Rei", "Ás" };
    // Retorna uma string no formato "Valor de Naipe"
    return ranks[static_cast<int>(rank)] + " de " + suits[static_cast<int>(suit)];
}
