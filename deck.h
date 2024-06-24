#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>

// Declaração da classe Deck
class Deck {
public:
    // Construtor que inicializa o baralho
    Deck();

    // Método que embaralha as cartas
    void shuffle();

    // Método que distribui uma carta do topo do baralho
    Card dealCard();

    // Método que verifica se o baralho está vazio
    bool isEmpty() const;

    // Método que reseta o baralho para o estado inicial
    void reset();

private:
    // Vetor que armazena as cartas do baralho
    std::vector<Card> cards;

    // Índice da carta atual a ser distribuída
    size_t currentCardIndex;
};

#endif // DECK_H
