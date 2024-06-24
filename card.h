#ifndef CARD_H
#define CARD_H

#include <string>

// Enumeração para os naipes de um baralho
enum class Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

// Enumeração para os valores das cartas
enum class Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

// Declaração da classe Card
class Card {
public:
    // Construtor que inicializa o naipe e o valor da carta
    Card(Suit suit, Rank rank);

    // Método que retorna o naipe da carta
    Suit getSuit() const;

    // Método que retorna o valor da carta
    Rank getRank() const;

    // Método que retorna uma string representando a carta (ex: "2 of Hearts")
    std::string toString() const;

private:
    // Atributo que armazena o naipe da carta
    Suit suit;

    // Atributo que armazena o valor da carta
    Rank rank;
};

#endif // CARD_H
