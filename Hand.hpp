#ifndef HAND_HPP
#define HAND_HPP

#include <vector>
#include "Card.hpp"

class Hand {

    private:

        std::vector<Card> cards;
        // the player's cards, count of cards is cards.size()

    public:

        Hand();
        // Precondition: none
        // Postcondition: empty hand is created


        void addCard(const Card& card);
        // Precondition: card is valid
        // Postcondition: card is added to the hand, hand has 1 more card

        Card removeCard(int index);
        // Precondition: index is between 0 and size() - 1
        // Postcondition: card at index is removed from the hand and returned, hand has 1 less card
        // (UI shows a 1-based list, so Game converts the player's choice to index)

        Card getCard(int index) const;
        // Precondition: index is between 0 and size() - 1
        // Postcondition: returns the card at index without removing it

        const std::vector<Card>& getCards() const;
        // Precondition: none
        // Postcondition: returns read-only access to the cards so UI can display them as a numbered list

        int size() const;
        // Precondition: none
        // Postcondition: returns the number of cards in the hand


        bool isEmpty() const;
        // Precondition: none
        // Postcondition: returns true if the hand has no cards (the player has won)

        std::vector<int> getPlayableIndices(const Card& topCard, int currentSuit) const;
        // Precondition: topCard is the top card of the DiscardPile and currentSuit is the active suit tracked by DiscardPile
        // Postcondition: returns the indices (0-based, in hand order) of every card that can be played
        // (uses Card::canPlayOn), empty vector if none


        bool hasPlayable(const Card& topCard, int currentSuit) const;
        // Precondition: same as getPlayableIndices
        // Postcondition: returns true if at least one card in the hand can be played

        bool canPlayIndex(int index, const Card& topCard, int currentSuit) const;
        // Precondition: none
        // Postcondition: returns true if index is in range and that card can be played on topCard/currentSuit,
        // false otherwise (lets Game reject bad choices without crashing)

        void clear();
        // Precondition: none
        // Postcondition: all cards are removed from the hand, used when starting a new game

};

#endif
