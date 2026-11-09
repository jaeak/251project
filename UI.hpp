#ifndef UI_HPP
#define UI_HPP

#include <string>
#include <vector>
#include "Card.hpp"
#include "Hand.hpp"
#include "Player.hpp"

// UI handles everything the players see and type.
// It shows menus, the hot-seat handoff, the current player's hand, the top card,
// the current suit, opponents' card counts, error messages and the winner.
// It reads all input and asks again until the input is valid, so Game never gets bad input.
// UI does not store any game state and does not enforce game rules (Game does that).

class UI {

    private:

        // UI stores no data members, it holds no game state.
        // The private helpers below are shared by the public input functions.

        std::string readLine() const;
        // Precondition: none
        // Postcondition: one full line is read from std::cin and returned with leading/trailing spaces removed

        bool parseInt(const std::string& text, int& result) const;
        // Precondition: none
        // Postcondition: returns true and stores the value in result if the whole text is a valid integer,
        // returns false for input like "abc", "3x" or an empty line

        int readIntInRange(const std::string& prompt, int low, int high) const;
        // Precondition: low <= high
        // Postcondition: prompt is shown and input is read until the user enters an integer
        // from low to high (inclusive), an error is shown for each bad input, the valid number is returned

        bool parseSuit(const std::string& text, int& suit) const;
        // Precondition: none
        // Postcondition: returns true and stores HEARTS, DIAMONDS, CLUBS or SPADES in suit if text is a suit name
        // or its first letter (any case, ex. "hearts", "H"), returns false otherwise

    public:

        UI();
        // Precondition: none
        // Postcondition: UI is created, nothing to initialize since UI stores no data

        ~UI();
        // Precondition: none
        // Postcondition: UI is destroyed, no dynamic memory is owned

        // ---------- menus ----------

        void showWelcome() const;
        // Precondition: none
        // Postcondition: title screen and a short summary of the rules are printed

        int askNumberOfPlayers(int minPlayers, int maxPlayers) const;
        // Precondition: minPlayers <= maxPlayers (Game passes MIN_PLAYERS and MAX_PLAYERS)
        // Postcondition: returns a number of players from minPlayers to maxPlayers, asks again on bad input

        std::string askPlayerName(int playerNumber) const;
        // Precondition: playerNumber >= 1
        // Postcondition: returns a name that is not empty, asks again if the user enters nothing

        bool askPlayAgain() const;
        // Precondition: a game has just ended
        // Postcondition: returns true for y/yes, false for n/no (any case), asks again on anything else

        // ---------- hot-seat privacy ----------

        void clearScreen() const;
        // Precondition: none
        // Postcondition: terminal is cleared so the previous player's hand is hidden

        void showHandoff(const std::string& playerName) const;
        // Precondition: none
        // Postcondition: screen is cleared, "Pass the computer to [name], press Enter when ready" is shown,
        // and UI waits for Enter before the next hand is displayed

        void waitForEnter() const;
        // Precondition: none
        // Postcondition: UI waits until the player presses Enter (used at the end of a turn)

        // ---------- game display ----------

        void showTurnScreen(const std::vector<Player>& players, int currentPlayer,
                            const Card& topCard, int currentSuit) const;
        // Precondition: currentPlayer is between 0 and players.size() - 1, currentSuit is between HEARTS and SPADES
        // Postcondition: top card, current suit, each opponent's card count and the current player's
        // hand (as a numbered list) are printed

        void showHand(const Hand& hand) const;
        // Precondition: none
        // Postcondition: hand is printed as a numbered list starting at 1 (ex. "1) Ace of Hearts")

        void showTopCard(const Card& topCard, int currentSuit) const;
        // Precondition: currentSuit is between HEARTS and SPADES
        // Postcondition: top card and current suit are printed (suit can differ from the top card after an 8)

        void showOpponentCounts(const std::vector<Player>& players, int currentPlayer) const;
        // Precondition: currentPlayer is between 0 and players.size() - 1
        // Postcondition: every other player's name and number of cards is printed

        // ---------- player input ----------

        int askCardChoice(int handSize) const;
        // Precondition: handSize >= 1
        // Postcondition: returns the card position the player typed, from 1 to handSize
        // (rejects non-numbers, 0, negatives and numbers above handSize). Game converts it to a 0-based index

        int askSuit() const;
        // Precondition: an 8 was just played
        // Postcondition: returns the declared suit (HEARTS, DIAMONDS, CLUBS or SPADES), asks again until it is valid

        // ---------- messages ----------

        void showDrawnCard(const Card& card) const;
        // Precondition: none
        // Postcondition: the drawn card is printed (ex. "You drew: 7 of Clubs")

        void showMustDraw() const;
        // Precondition: none
        // Postcondition: player is told they have no playable card and must draw

        void showTurnPassed(const std::string& playerName) const;
        // Precondition: none
        // Postcondition: player is told their turn passes (MAX_DRAWS reached or no cards left to draw)

        void showDeckReshuffled() const;
        // Precondition: none
        // Postcondition: players are told the deck was refilled from the discard pile and shuffled

        void showError(const std::string& message) const;
        // Precondition: none
        // Postcondition: message is printed as an error so the player knows why they must try again

        void showWinner(const std::string& winnerName) const;
        // Precondition: none
        // Postcondition: the winning message is printed for winnerName

        void showGoodbye() const;
        // Precondition: none
        // Postcondition: goodbye message is printed when the players choose to exit

};

#endif
