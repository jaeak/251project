#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Hand.hpp"

class Player {

    private:

        std::string name;   // player's name
        Hand hand;          // player's own cards

    public:

        Player(std::string name);
        // Precondition: name is not empty
        // Postcondition: player is created with name and an empty hand

        std::string getName() const;
        // Precondition: none
        // Postcondition: returns the player's name

        Hand& getHand();
        // Precondition: none
        // Postcondition: returns the player's actual hand (not a copy) so Game can add/remove cards

        const Hand& getHand() const;
        // Precondition: none
        // Postcondition: returns read-only access to the hand so UI can display it

};

#endif
