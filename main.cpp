#include <iostream>
#include <vector>
#include <string>
#include "pokerchines.h"

int main() {
    std::vector<std::string> playerNames;

    for (int i = 0; i < 4; ++i) {
        std::string name;
        std::cout << "Enter name for player " << i + 1 << ": ";
        std::cin >> name;
        playerNames.push_back(name);
    }

    pokerChines game(playerNames);
    game.playGame();

    return 0;
}





/*#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <map>


using namespace std;

// Enumerado para os naipes
enum class Suit { Hearts, Diamonds, Clubs, Spades };

// Enumerado para os valores das cartas
enum class Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

// Classe representando uma carta
class Card {
public:
    Card(Suit s, Rank r) : suit(s), rank(r) {}

    Suit getSuit() const { return suit; }
    Rank getRank() const { return rank; }

    // Função para imprimir a carta
    void printCard() const {
        string suits[]{"Hearts", "Diamonds", "Clubs", "Spades"};
        string ranks[]{"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

        cout << ranks[static_cast<int>(rank) - 2] << " of " << suits[static_cast<int>(suit)] << endl;
    }

private:
    Suit suit;
    Rank rank;
};

// Classe representando um baralho
class Deck {
public:
    Deck() {
        // Cria um baralho padrão de 52 cartas
        for (int s = 0; s < 4; ++s) {
            for (int r = 2; r <= 14; ++r) {
                cards.emplace_back(static_cast<Suit>(s), static_cast<Rank>(r));
            }
        }
    }

    // Embaralha o baralho
    void shuffle() {
        auto rng = std::default_random_engine(std::random_device{}());
        std::shuffle(cards.begin(), cards.end(), rng);
    }

    // Distribui uma carta
    Card deal() {
        Card card = cards.back();
        cards.pop_back();
        return card;
    }

private:
    vector<Card> cards;
};

// Classe representando um jogador
class Player {
public:
    Player(string n) : name(n), score(0) {}

    void receiveCard(const Card &card) {
        hand.push_back(card);
    }

    void showHand() const {
        cout << name << "'s hand:" << endl;
        for (const auto &card : hand) {
            card.printCard();
        }
    }

    void clearHand() {
        hand.clear();
    }

    // Função para obter o score atual do jogador
    int getScore() const {
        return score;
    }

    // Função para incrementar o score do jogador
    void addScore(int points) {
        score += points;
    }

    // Função para obter a mão do jogador (usada para comparação)
    const vector<Card>& getHand() const {
        return hand;
    }

private:
    string name;
    vector<Card> hand;
    int score;
};

// Classe representando o jogo de pôquer
class PokerGame {
public:
    PokerGame() {
        for (int i = 0; i < 4; ++i) {
            players.emplace_back("Player " + to_string(i + 1));
        }
    }

    void playRound() {
        deck.shuffle();
        dealCards();

        for (auto &player : players) {
            player.showHand();
        }

        // Aqui você pode implementar a lógica de comparação de mãos e atribuição de pontos
        // Por simplicidade, neste exemplo, vamos apenas dar 1 ponto para um jogador aleatório
        int winnerIndex = rand() % 4;
        players[winnerIndex].addScore(1);
        cout << players[winnerIndex].getScore() << " wins this round!" << endl;

        for (auto &player : players) {
            player.clearHand();
        }
    }

    void showScores() const {
        for (const auto &player : players) {
            cout << player.getScore() << " has " << player.getScore() << " points." << endl;
        }
    }

private:
    Deck deck;
    vector<Player> players;

    void dealCards() {
        // Cada jogador recebe 5 cartas
        for (int i = 0; i < 5; ++i) {
            for (auto &player : players) {
                player.receiveCard(deck.deal());
            }
        }
    }

    // Aqui você pode adicionar funções para comparar mãos de pôquer e determinar o vencedor da rodada
    // Por exemplo, funções para determinar se uma mão é um par, dois pares, trinca, straight, flush, full house, quadra, straight flush, royal flush
};

int main() {
    srand(static_cast<unsigned>(time(0)));  // Inicializa a semente do gerador de números aleatórios

    PokerGame game;

    char choice;
    do {
        game.playRound();
        game.showScores();

        cout << "Play another round? (y/n): ";
        cin >> choice;
    } while (choice == 'y');

    return 0;
}
*/