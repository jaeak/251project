#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include "Card.hpp"
#include "Deck.hpp"
#include "DiscardPile.hpp"
#include "Player.hpp"
#include "UI.hpp"

const int MIN_PLAYERS = 2;
const int MAX_PLAYERS = 5;
const int MAX_DRAWS = 5;      // max cards drawn in one turn
const int TOTAL_CARDS = 52;

class Game {

    private:

        std::vector<Player> players;   // all players, in turn order
        Deck deck;                     // draw pile
        DiscardPile pile;              // face-up pile
        UI ui;                         // handles all input/output
        int currentPlayer;             // index of whose turn it is

    public:

        Game();
        // Precondition: none
        // Postcondition: empty game is created, currentPlayer is 0

        void run();
        // Precondition: none
        // Postcondition: game is played until a player wins, then repeats if players choose to play again

    private:

        void setup();
        // Precondition: none
        // Postcondition: players (2 to 5) are created through UI, deck is built and shuffled,
        // 7 cards are dealt each for 2 players or 5 each for 3-5 players, random first player is chosen

        void flipStartingCard();
        // Precondition: deck is not empty
        // Postcondition: top deck card is placed on the pile; if it is an 8, it goes back in the deck,
        // deck is reshuffled and another card is flipped

        void playTurn();
        // Precondition: setup() has been called
        // Postcondition: current player plays one valid card, or draws until they can play or have drawn MAX_DRAWS

        void playCard(Player& player, int index);
        // Precondition: index is between 0 and hand size - 1, and that card can be played
        // Postcondition: card is removed from the hand and added to the pile in one step;
        // if it is an 8, the player declares a new suit through UI

        bool drawCard(Player& player);
        // Precondition: none
        // Postcondition: if the deck is empty it is refilled from the pile first; one card moves to the player's hand
        // and true is returned, or false if no cards are left anywhere

        void nextPlayer();
        // Precondition: none
        // Postcondition: currentPlayer moves to the next player, wrapping back to 0 after the last player

        bool hasWinner() const;
        // Precondition: none
        // Postcondition: returns true if the current player's hand is empty

        void resetGame();
        // Precondition: none
        // Postcondition: players, deck and pile are cleared so a new game can start

        bool checkCardCount() const;
        // Precondition: none
        // Postcondition: returns true if deck + pile + all hands equal TOTAL_CARDS (debug check)

};

#endif
