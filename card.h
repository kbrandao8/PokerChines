#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <string>
#include <iostream> // Para std::cout
#include <iomanip>  // Para std::setw

/**
 * @file card.h
 * Declaração da classe Card e seus métodos.
 */

class Card {
private:
    std::string suit;   // naipe
    int value;          // valor numérico da carta
    std::string name;   // nome da carta
    char number;        // símbolo numérico (A, 2, 3, ..., Q, K)
    char symbol;        // símbolo do naipe (p, e, o, c)

public:
    Card(int v, int s); // Construtor
    std::string getSuit();
    int getValue();
    std::string getName();
    std::string getFullName();
    void print();
    bool operator>(const Card& c) const;
    bool operator==(const Card& c) const;
    char getNumber();
    char getSymbol();
};

#endif // CARD_H_INCLUDED
