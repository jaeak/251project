#ifndef DISCARDPILE_HPP
#define DISCARDPILE_HPP

#include <vector>
#include "Card.hpp"

class DiscardPile {

    private:

        std::vector<Card> cards;
        // face-up pile, top card is back of the vector

        int currentSuit;
        // active suit tracked separately from the physical top card,
        // so a declared suit after an 8 survives screen clears

    public:

        DiscardPile();
        // Precondition: none
        // Postcondition: empty discard pile is created, currentSuit is set to HEARTS (placeholder until first card is added)

        void addCard(const Card& card);
        // Precondition: card is valid
        // Postcondition: card is placed on top of the pile, currentSuit is set to the card's suit
        // (if the card is an 8, Game should follow up with setSuit() once the player declares)

        void setSuit(int suit);
        // Precondition: suit is between HEARTS and SPADES
        // Postcondition: currentSuit is updated to suit (used after an 8 is played)

        Card getTopCard() const;
        // Precondition: isEmpty() is false
        // Postcondition: returns the top card without removing it

        int getCurrentSuit() const;
        // Precondition: none
        // Postcondition: returns the active suit (0 to 3) that the next player must follow

        bool isEmpty() const;
        // Precondition: none
        // Postcondition: returns true if the pile has no cards

        int size() const;
        // Precondition: none
        // Postcondition: returns the number of cards in the pile

        std::vector<Card> takeAllButTop();
        // Precondition: none
        // Postcondition: every card except the top one is removed and returned (for Deck::refill),
        // the top card and currentSuit stay unchanged. If the pile has 0 or 1 cards,
        // returns an empty vector and the pile is unchanged

        void clear();
        // Precondition: none
        // Postcondition: pile is empty, used when starting a new game

};

#endif
