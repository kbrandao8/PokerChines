#include "pokerhand.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <map>
#include <set>

// Implementações das classes derivadas de PokerHand

bool RoyalFlush::matches(const std::vector<Card>& hand) const {
    // Implementação específica para verificar se a mão é um Royal Flush
    // Exemplo simplificado: Verifica se todas as cartas são do mesmo naipe e estão em sequência de 10 a As
    if (hand.size() != 5) return false;

    // Verifica se todas as cartas são do mesmo naipe
    Suit refSuit = hand[0].getSuit();
    for (size_t i = 1; i < hand.size(); ++i) {
        if (hand[i].getSuit() != refSuit) {
            return false;
        }
    }

    // Verifica se as cartas estão em sequência de 10 a As
    std::vector<Rank> requiredRanks = { Rank::TEN, Rank::JACK, Rank::QUEEN, Rank::KING, Rank::ACE };
    std::vector<Rank> actualRanks;
    for (const auto& card : hand) {
        actualRanks.push_back(card.getRank());
    }

    std::sort(actualRanks.begin(), actualRanks.end());

    return actualRanks == requiredRanks;
}

std::string RoyalFlush::getName() const {
    return "Royal Flush";
}

int RoyalFlush::getRank() const {
    return 10;
}

bool StraightFlush::matches(const std::vector<Card>& hand) const {
    // Implementação específica para verificar se a mão é um Straight Flush
    // Exemplo simplificado: Verifica se todas as cartas são do mesmo naipe e estão em sequência
    if (hand.size() != 5) return false;

    // Verifica se todas as cartas são do mesmo naipe
    Suit refSuit = hand[0].getSuit();
    for (size_t i = 1; i < hand.size(); ++i) {
        if (hand[i].getSuit() != refSuit) {
            return false;
        }
    }

    // Verifica se as cartas estão em sequência
    std::vector<Rank> actualRanks;
    for (const auto& card : hand) {
        actualRanks.push_back(card.getRank());
    }

    std::sort(actualRanks.begin(), actualRanks.end());

    for (size_t i = 1; i < actualRanks.size(); ++i) {
        if (static_cast<int>(actualRanks[i]) != static_cast<int>(actualRanks[i-1]) + 1) {
            return false;
        }
    }

    return true;
}

std::string StraightFlush::getName() const {
    return "Straight Flush";
}

int StraightFlush::getRank() const {
    return 9;
}

bool FourOfAKind::matches(const std::vector<Card>& hand) const {
    // Implementação específica para verificar se a mão é uma Quadra
    // Exemplo simplificado: Verifica se há quatro cartas com o mesmo valor
    if (hand.size() != 5) return false;

    std::map<Rank, int> rankCount;
    for (const auto& card : hand) {
        rankCount[card.getRank()]++;
    }

    for (const auto& pair : rankCount) {
        if (pair.second == 4) {
            return true;
        }
    }

    return false;
}

std::string FourOfAKind::getName() const {
    return "Four of a Kind";
}

int FourOfAKind::getRank() const {
    return 8;
}

bool FullHouse::matches(const std::vector<Card>& hand) const {
    // Implementação específica para verificar se a mão é um Full House
    // Exemplo simplificado: Verifica se há três cartas com o mesmo valor e duas cartas com outro valor
    if (hand.size() != 5) return false;

    std::map<Rank, int> rankCount;
    for (const auto& card : hand) {
        rankCount[card.getRank()]++;
    }

    bool hasThree = false;
    bool hasTwo = false;
    for (const auto& pair : rankCount) {
        if (pair.second == 3) {
            hasThree = true;
        } else if (pair.second == 2) {
            hasTwo = true;
        }
    }

    return hasThree && hasTwo;
}

std::string FullHouse::getName() const {
    return "Full House";
}

int FullHouse::getRank() const {
    return 7;
}

bool Flush::matches(const std::vector<Card>& hand) const {
    // Implementação específica para verificar se a mão é um Flush
    // Exemplo simplificado: Verifica se todas as cartas são do mesmo naipe
    if (hand.size() != 5) return false;

    Suit refSuit = hand[0].getSuit();
    for (size_t i = 1; i < hand.size(); ++i) {
        if (hand[i].getSuit() != refSuit) {
            return false;
        }
    }

    return true;
}

std::string Flush::getName() const {
    return "Flush";
}

int Flush::getRank() const {
    return 6;
}

bool Straight::matches(const std::vector<Card>& hand) const {
    // Implementação específica para verificar se a mão é uma Sequência
    // Exemplo simplificado: Verifica se as cartas estão em sequência
    if (hand.size() != 5) return false;

    std::vector<Rank> actualRanks;
    for (const auto& card : hand) {
        actualRanks.push_back(card.getRank());
    }

    std::sort(actualRanks.begin(), actualRanks.end());

    for (size_t i = 1; i < actualRanks.size(); ++i) {
        if (static_cast<int>(actualRanks[i]) != static_cast<int>(actualRanks[i-1]) + 1) {
            return false;
        }
    }

    return true;
}

std::string Straight::getName() const {
    return "Straight";
}

int Straight::getRank() const {
    return 5;
}

bool ThreeOfAKind::matches(const std::vector<Card>& hand) const {
    // Implementação específica para verificar se a mão é uma Trinca
    // Exemplo simplificado: Verifica se há três cartas com o mesmo valor
    if (hand.size() != 5) return false;

    std::map<Rank, int> rankCount;
    for (const auto& card : hand) {
        rankCount[card.getRank()]++;
    }

    for (const auto& pair : rankCount) {
        if (pair.second == 3) {
            return true;
        }
    }

    return false;
}

std::string ThreeOfAKind::getName() const {
    return "Three of a Kind";
}

int ThreeOfAKind::getRank() const {
    return 4;
}

bool TwoPair::matches(const std::vector<Card>& hand) const {
    // Implementação específica para verificar se a mão são Dois Pares
    // Exemplo simplificado: Verifica se há dois pares de cartas com o mesmo valor
    if (hand.size() != 5) return false;

    std::map<Rank, int> rankCount;
    for (const auto& card : hand) {
        rankCount[card.getRank()]++;
    }

    int pairCount = 0;
    for (const auto& pair : rankCount) {
        if (pair.second == 2) {
            pairCount++;
        }
    }

    return pairCount == 2;
}

std::string TwoPair::getName() const {
    return "Two Pair";
}

int TwoPair::getRank() const {
    return 3;
}

bool OnePair::matches(const std::vector<Card>& hand) const {
    // Implementação específica para verificar se a mão é Um Par
    // Exemplo simplificado: Verifica se há um par de cartas com o mesmo valor
    if (hand.size() != 5) return false;

    std::map<Rank, int> rankCount;
    for (const auto& card : hand) {
        rankCount[card.getRank()]++;
    }

    for (const auto& pair : rankCount) {
        if (pair.second == 2) {
            return true;
        }
    }

    return false;
}

std::string OnePair::getName() const {
    return "One Pair";
}

int OnePair::getRank() const {
    return 2;
}

bool HighCard::matches(const std::vector<Card>& hand) const {
    // Implementação específica para verificar se a mão é uma Carta Alta
    // Exemplo simplificado: Retorna true porque toda mão pode ser considerada uma Carta Alta
    return true;
}

std::string HighCard::getName() const {
    return "High Card";
}

int HighCard::getRank() const {
    return 1;
}
