#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include "Token.hpp"
#include "Color.hpp"

// Déclaration anticipée des classes
class Street;
class RailRoad;
class Utility;

class Player {
private:
    std::string name;                    // The player's name
    Token token;                         // The player's token (representing their playing piece)
    int position{0};                     // The player's current position on the board (0-39)
    int moneyWallet{1500};               // The player's starting balance (assuming a start amount like Monopoly)
    bool inJail{false};                  // Whether the player is in jail
    int jailTurns{0};                    // Number of turns spent in jail
    bool hasGetOutOfJailCard{false};     // Whether the player has a "Get out of Jail Free" card
    int boardTurns{0};                   // Number of turns the player has played

    // Utilisation de pointeurs pour éviter la dépendance circulaire
    std::vector<Street*> streetProperties;    // Owned street properties
    std::vector<RailRoad*> railroadProperties;  // Owned railroads
    std::vector<Utility*> utilityProperties;   // Owned utilities

public:
    // Constructor to initialize the player with a name and token
    Player(const std::string& playerName);

    Player();  // Constructeur par défaut

    ~Player() = default;

    // Getters
    std::string getName() const;
    std::string getToken() const;
    int getBalance() const;
    int getPosition() const;
    bool isInJail() const;
    int getJailTurns() const;
    bool hasJailCard() const;
    int getBoardTurns() const;
    std::vector<Street*> getStreetProperties() const;
    std::vector<RailRoad*> getRailroadProperties() const;
    std::vector<Utility*> getUtilityProperties() const;

    // Setters
    void setName(const std::string& newName);
    void setToken(const Token& newToken);
    void setBalance(int newBalance);
    void setPosition(int newPosition);
    void setInJail(bool jailStatus);
    void setJailTurns(int turns);
    void setHasGetOutOfJailCard(bool hasCard);
    void setBoardTurns(int turns);
    void setStreetProperties(const std::vector<Street*>& streets);
    void setRailroadProperties(const std::vector<RailRoad*>& railroads);
    void setUtilityProperties(const std::vector<Utility*>& utilities);

    // Check if the player owns all properties of a specific color group
    bool ownsFullColorGroup(Color color);  // Définie dans Player.cpp
    // Display the player's current status
    void display() const;
    // Fonction statique pour obtenir les tokens disponibles sous forme de chaîne
    static std::string getAvailableTokensAsString(const std::vector<Player>& players);
    // Function to select a token for the player
    static void choosePlayerToken(Player& currentPlayer, const std::vector<Player>& players_vector);

};

#endif // PLAYER_HPP