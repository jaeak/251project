#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

// suits
const int HEARTS = 0;
const int DIAMONDS = 1;
const int CLUBS = 2;
const int SPADES = 3;

// rank limits
const int MIN_RANK = 1;  // ace
const int MAX_RANK = 13;    // king
const int WILD_RANK = 8;    // wild card 8

class Card {

    private:

        int rank;   // card rank
        int suit;  // card suit

    public:

        Card ();
        // Precondition: none
        // Postcondition: creates placeholder card so Card can be stored in vectors

        Card(int rank, int suit);
        // Precondition: rank is between MIN_RANK & MAX_RANK, suit is between HEARTS and SPADES
        // Postcondition: card is created with rank and suit

        int getRank() const;  
        // Precondition: none
        // Postcondition: returns a number from 1 (Ace) to 13 (king)

        int getSuit() const;
        // Precondition: none
        // Postcondition: returns hearts, diamonds, clubs, or spades (0 to 3)

        std::string getRankName() const;
        // Precondition: none
        // Postcondition: returns actual names for each card's rank

        std::string getSuitName() const;
        //Precondition: none
        // Postcondition: returns actual names for each card's suit

        void print(std::ostream& out = std::cout) const;
        // Precondition: out is an open output stream
        // Postcondition: card's full name (ex. 8 of Clubs) is written out

        bool isValid() const;
        // Precondition: none
        // Postcondition: returns true if rank is between MIN_RANK and MAX_RANK and suit is between HEARTS and SPADES

        bool isEight() const;
        // Precondition: none
        // Postcondition: returns true if rank is WILD_RANK

        bool canPlayOn(const Card& topCard, int currentSuit) const;
        // Precondition: topCard is the top card of the DiscardPile and currentSuit is the active suit tracked by DiscardPile
        // Postcondition: returns true if: card is an 8, card's suit matches currentSuit, or card's rank matches topCard's rank

        bool operator==(const Card& other) const;
        // Precondition: none
        // Postcondition: returns true if both cards have same rank and suit

        friend std::ostream& operator<<(std::ostream& out, const Card& card);
        // Precondition: out is an open output stream
        // Postcondition: card's full name is written out, returns so outputs can be chained

};

// turns suit number into name without needing a Card so UI can show suit declared after an 8
std::string suitToString(int suit);
// Precondition: suit is between HEARTS and SPADES
// Postcondition: returns the suit, and unkown if suit is out of range

#endif