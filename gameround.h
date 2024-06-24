#ifndef GAMEROUND_H
#define GAMEROUND_H

#include <vector>
#include "player.h"
#include "card.h"

// Declaração da classe GameRound
class GameRound {
public:
    // Construtor que inicializa a rodada de jogo
    GameRound();

    // Método que define a carta da "mão da rodada"
    void setHandOfRound(const Card& card);

    // Método que retorna a carta da "mão da rodada"
    Card getHandOfRound() const;

    // Método que verifica se um movimento é válido com base na "mão da rodada"
    bool isValidMove(const std::vector<Card>& cards) const;

private:
    // Atributo que armazena a carta da "mão da rodada"
    Card handOfRound;
};

#endif // GAMEROUND_H
