#include "pokerhand.h"
#include <algorithm>
#include <map>
#include <set>

// Helper functions
bool isStraight(const std::vector<Card>& hand) {
    if (hand.size() != 5) return false;
    std::vector<int> ranks;
    for (const auto& card : hand) {
        ranks.push_back(card.getRank());
    }
    std::sort(ranks.begin(), ranks.end());
    for (size_t i = 1; i < ranks.size(); ++i) {
        if (ranks[i] != ranks[i - 1] + 1) {
            return false;
        }
    }
    return true;
}

bool isFlush(const std::vector<Card>& hand) {
    if (hand.size() != 5) return false;
    Suit suit = hand[0].getSuit();
    for (const auto& card : hand) {
        if (card.getSuit() != suit) {
            return false;
        }
    }
    return true;
}

std::map<int, int> getCounts(const std::vector<Card>& hand) {
    std::map<int, int> counts;
    for (const auto& card : hand) {
        counts[card.getRank()]++;
    }
    return counts;
}

// RoyalFlush implementation
bool RoyalFlush::matches(const std::vector<Card>& hand) const {
    if (!isFlush(hand)) return false;
    std::set<int> royalRanks = {10, 11, 12, 13, 14};
    for (const auto& card : hand) {
        if (royalRanks.find(card.getRank()) == royalRanks.end()) {
            return false;
        }
    }
    return true;
}

std::string RoyalFlush::getName() const {
    return "Royal Flush";
}

int RoyalFlush::getRank() const {
    return 10;
}

// StraightFlush implementation
bool StraightFlush::matches(const std::vector<Card>& hand) const {
    return isFlush(hand) && isStraight(hand);
}

std::string StraightFlush::getName() const {
    return "Straight Flush";
}

int StraightFlush::getRank() const {
    return 9;
}

// FourOfAKind implementation
bool FourOfAKind::matches(const std::vector<Card>& hand) const {
    auto counts = getCounts(hand);
    return std::any_of(counts.begin(), counts.end(), [](const auto& pair) {
        return pair.second == 4;
    });
}

std::string FourOfAKind::getName() const {
    return "Four of a Kind";
}

int FourOfAKind::getRank() const {
    return 8;
}

// FullHouse implementation
bool FullHouse::matches(const std::vector<Card>& hand) const {
    auto counts = getCounts(hand);
    bool hasThree = false;
    bool hasTwo = false;
    for (const auto& pair : counts) {
        if (pair.second == 3) hasThree = true;
        if (pair.second == 2) hasTwo = true;
    }
    return hasThree && hasTwo;
}

std::string FullHouse::getName() const {
    return "Full House";
}

int FullHouse::getRank() const {
    return 7;
}

// Flush implementation
bool Flush::matches(const std::vector<Card>& hand) const {
    return isFlush(hand);
}

std::string Flush::getName() const {
    return "Flush";
}

int Flush::getRank() const {
    return 6;
}

// Straight implementation
bool Straight::matches(const std::vector<Card>& hand) const {
    return isStraight(hand);
}

std::string Straight::getName() const {
    return "Straight";
}

int Straight::getRank() const {
    return 5;
}

// ThreeOfAKind implementation
bool ThreeOfAKind::matches(const std::vector<Card>& hand) const {
    auto counts = getCounts(hand);
    return std::any_of(counts.begin(), counts.end(), [](const auto& pair) {
        return pair.second == 3;
    });
}

std::string ThreeOfAKind::getName() const {
    return "Three of a Kind";
}

int ThreeOfAKind::getRank() const {
    return 4;
}

// TwoPair implementation
bool TwoPair::matches(const std::vector<Card>& hand) const {
    auto counts = getCounts(hand);
    int pairCount = 0;
    for (const auto& pair : counts) {
        if (pair.second == 2) pairCount++;
    }
    return pairCount == 2;
}

std::string TwoPair::getName() const {
    return "Two Pair";
}

int TwoPair::getRank() const {
    return 3;
}

// OnePair implementation
bool OnePair::matches(const std::vector<Card>& hand) const {
    auto counts = getCounts(hand);
    return std::any_of(counts.begin(), counts.end(), [](const auto& pair) {
        return pair.second == 2;
    });
}

std::string OnePair::getName() const {
    return "One Pair";
}

int OnePair::getRank() const {
    return 2;
}

// HighCard implementation
bool HighCard::matches(const std::vector<Card>& hand) const {
    return true; // Every hand has a high card
}

std::string HighCard::getName() const {
    return "High Card";
}

int HighCard::getRank() const {
    return 1;
}
