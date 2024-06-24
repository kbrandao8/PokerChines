#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"

// Declaração da classe Player
class Player {
public:
    // Construtor que inicializa o jogador com um nome
    Player(const std::string& name);

    // Método que retorna o nome do jogador
    std::string getName() const;

    // Método que define o nome do jogador
    void setName(const std::string& playerName);

    // Método que retorna a mão de cartas do jogador
    std::vector<Card> getHand() const;

    // Método que define a mão de cartas do jogador
    void setHand(const std::vector<Card>& cards);

    // Método que adiciona uma carta à mão do jogador
    void addToHand(const Card& card);

    // Método que remove uma carta da mão do jogador
    void removeFromHand(const Card& card);

    // Método que limpa a mão do jogador
    void clearHand();

    // Método que faz o jogador jogar as cartas da mão
    std::vector<Card> playCards();

    // Método que verifica se o jogador ainda tem cartas na mão
    bool hasCards() const;

private:
    // Nome do jogador
    std::string name;

    // Vetor que armazena a mão de cartas do jogador
    std::vector<Card> hand;
};

#endif // PLAYER_H
