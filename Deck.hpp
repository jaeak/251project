#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include "Card.hpp"

class Deck {

    private:

        std::vector<Card> cards;
        // draw pile, top card is back of the vector

    public:

        Deck();
        // Precondition: none
        // Postcondition: 52 card deck is built (unshuffled)

        void build();
        // Precondition: none
        // Postcondition: any old cards are removed and deck holds 52 cards in order, used when starting a new game

        void shuffle();
        // Precondition: none
        // Postcondition: cards are put in random order

        Card draw();
        // Precondition: isEmpty() is false
        // Postcondition: top card is removed from the deck and returned, deck has 1 less card

        bool isEmpty() const;
        // Precondition: none
        // Postcondition: returns true if deck has no cards left
        
        int size() const;
        // Precondition: none
        // Postcondition: returns the number of cards left in the deck 

        void addCard(const Card& card);
        // Precondition: card is valid
        // Postcondition: card is added to the deck, deck has 1 more card

        void refill(const std::vector<Card>& discardCards);
        // Precondition: discardCards holds every card from DiscardPile except the top card
        // Postcondition: all of discardCards are added to the deck and deck is shuffled

};

#endif