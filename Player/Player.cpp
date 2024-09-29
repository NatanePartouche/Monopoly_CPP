#include "Player.hpp"
#include "Street.hpp"
#include "RailRoad.hpp"
#include "Utility.hpp"

// Constructor that initializes the player with a specific name
Player::Player(const std::string& playerName) : name(playerName) {}

// Default constructor
Player::Player() {}

// Getters (Accessor methods)
// These functions return the respective player attributes

std::string Player::getName() const { return name; }
Token Player::getToken() const { return token; }
int Player::getBalance() const { return moneyWallet; }
int Player::getPosition() const { return position; }
bool Player::isInJail() const { return inJail; }
bool Player::getCard_out_of_jail() const { return card_get_out_of_jail; }
int Player::getJailTurns() const { return JailTurns; }
int Player::getBoardTurns() const { return boardTurns; }

// Getters for owned properties
std::vector<Street*> Player::getStreetProperties() const { return streetProperties; }
std::vector<RailRoad*> Player::getRailroadProperties() const { return railroadProperties; }
std::vector<Utility*> Player::getUtilityProperties() const { return utilityProperties; }

// Setters (Mutator methods)
// These functions allow modifying the player's attributes

void Player::setName(const std::string& newName) { name = newName; }
void Player::setToken(const Token& newToken) { token = newToken; }
void Player::setBalance(int newBalance) { moneyWallet = newBalance; }
void Player::setPosition(int newPosition) { position = newPosition; }
void Player::setInJail(bool jailStatus) { inJail = jailStatus; }
void Player::setCard_out_of_jail(bool jailStatus) { card_get_out_of_jail = jailStatus; }
void Player::setBoardTurns(int turns) { boardTurns = turns; }

// Setters for modifying owned properties
void Player::setStreetProperties(const std::vector<Street*>& streets) { streetProperties = streets; }
void Player::setRailroadProperties(const std::vector<RailRoad*>& railroads) { railroadProperties = railroads; }
void Player::setUtilityProperties(const std::vector<Utility*>& utilities) { utilityProperties = utilities; }
void Player::setJailTurns(int turns) { JailTurns = turns; }

// Check if the player owns all properties of a specific color group
// Returns true if the player owns all properties in the group
bool Player::ownsFullColorGroup(Color color) {
    int requiredProperties = (color == Color::Brown || color == Color::DarkBlue) ? 2 : 3;
    int ownedProperties = 0;

    // Iterate over the player's street properties and count those that match the given color
    for (const Street* street : streetProperties) {
        if (street->getColor() == color) {
            ownedProperties++;
        }
    }
    return ownedProperties == requiredProperties;
}

// Retrieve all properties the player owns of a specific color group
std::vector<Street*> Player::getPropertiesOfColorGroup(Color color) const {
    std::vector<Street*> colorGroupProperties;

    // Collect all properties matching the specified color
    for (Street* street : streetProperties) {
        if (street->getColor() == color) {
            colorGroupProperties.push_back(street);
        }
    }
    return colorGroupProperties;
}

// Add a street property to the player's ownership and announce it
void Player::addStreetProperty(Street* street) {
    streetProperties.push_back(street);
    std::cout << name << " has acquired the property: " << street->getName() << std::endl;
}

// Add a railroad property to the player's ownership and announce it
void Player::addRailroadProperty(RailRoad* railroad) {
    railroadProperties.push_back(railroad);
    std::cout << name << " has acquired the railroad: " << railroad->getName() << std::endl;
}

// Add a utility property to the player's ownership and announce it
void Player::addUtilityProperty(Utility* utility) {
    utilityProperties.push_back(utility);
    std::cout << name << " has acquired the utility: " << utility->getName() << std::endl;
}

// Token Management
// This function returns a list of all tokens that have not yet been selected by other players
std::string Player::getAvailableTokensAsString(const std::vector<Player>& players) {
    Token token;
    std::set<std::string> availableTokens = token.getValidTokens();

    // Remove tokens that have already been chosen by other players
    for (const Player& player : players) {
        availableTokens.erase(player.getToken().getTokenName());
    }

    // Construct the list of available tokens as a string
    std::string tokensList;
    for (const auto& tokenName : availableTokens) {
        tokensList += "\n" + tokenName;
    }
    return tokensList;
}

// Allows a player to select a token from the available ones
void Player::choosePlayerToken(Player& currentPlayer, const std::vector<Player>& players_vector) {
    std::string tmp_token_name;
    bool validTokenSelected = false;

    // Loop until the player selects a valid, available token
    while (!validTokenSelected) {
        std::cout << "\nPlayer " << currentPlayer.getName() << ", choose an available token:\n";
        std::string availableTokensList = Player::getAvailableTokensAsString(players_vector);
        std::cout << availableTokensList << std::endl;
        std::cout << "\nEnter the name of the chosen token for " << currentPlayer.getName() << ": ";
        std::getline(std::cin, tmp_token_name);

        // Check if the token name is valid and available
        if (Token::isValidToken(tmp_token_name)) {
            currentPlayer.setToken(tmp_token_name);
            validTokenSelected = true;
        } else {
            std::cout << "The token name is invalid or already taken. Please try again." << std::endl;
        }
    }
}

// Money Management
// Add money to the player's balance
void Player::addMoney(int amount) {
    if (amount > 0) {
        moneyWallet += amount;
        std::cout << name << " received " << amount << "M$. New balance: " << moneyWallet << "M$." << std::endl;
    }
}

// Deduct money from the player's balance
bool Player::removeMoney(int amount) {
    moneyWallet -= amount;
    std::cout << name << " paid " << amount << "M$. New balance: " << moneyWallet << "M$." << std::endl;
    return true;
}

// Check player balances to determine if any have been eliminated or won the game
bool Player::checkPlayerBalances(std::vector<Player>& players) {
    // Remove players with a balance of 0 or less
    players.erase(std::remove_if(players.begin(), players.end(),
        [](const Player& player) {
            if (player.getBalance() <= 0) {
                std::cout << player.getName() << " has been eliminated from the game due to a negative balance." << std::endl;
                return true;
            }
            return false;
        }), players.end());

    // Check if any player has won the game by reaching 4000 balance or if only one player remains
    for (const auto& player : players) {
        if (player.getBalance() >= 4000) {
            std::cout << "Congratulations " << player.getName() << "! You have won the game with a balance of " << player.getBalance() << " $ !" << std::endl;
            return false;
        }
    }

    if (players.size() == 1) {
        std::cout << "Congratulations " << players[0].getName() << "! You have won the game with a balance of " << players[0].getBalance() << " $ !" << std::endl;
        return false;
    }
    return true;
}

// Jail Management
// Handle player attempts to get out of jail
void Player::attemptToReleaseFromJail() {
    if (!this->isInJail()) { return; }

    // Check if player has a "Get Out of Jail Free" card
    if (this->getCard_out_of_jail()) {
        std::cout << this->getName() << " used a 'Get Out of Jail Free' card!" << std::endl;
        this->setInJail(false);
        this->setCard_out_of_jail(false);
        return;
    }

    // Offer to pay a fine to get out of jail
    char choice;
    std::cout << this->getName() << ", do you want to pay a fine of 50 NIS to get out of jail? (y/n): ";
    std::cin >> choice;

    // If player chooses to pay and has sufficient balance, release them from jail
    if ((choice == 'y' || choice == 'Y') && this->getBalance() >= 50) {
        this->removeMoney(50);
        this->setInJail(false);
        std::cout << this->getName() << " paid 50 NIS and is out of jail!" << std::endl;
    } else if (choice == 'y' && this->getBalance() < 50) {
        std::cout << "Insufficient funds to pay the fine!" << std::endl;
    }

    // Roll dice to try to get a double for automatic release from jail
    Dice dice;
    dice.roll();
    std::cout << this->getName() << " rolled a " << dice.get_die_1() << " and " << dice.get_die_2() << "." << std::endl;

    if (dice.isDouble()) {
        this->setInJail(false);
        std::cout << this->getName() << " rolled a double and is out of jail!" << std::endl;
    } else {
        std::cout << this->getName() << " did not roll a double." << std::endl;
    }

    // After 3 turns in jail, the player is forced to pay to get out
    if (this->getJailTurns() >= 3) {
        std::cout << this->getName() << " has spent 3 turns in jail. Must pay 50 NIS to get out." << std::endl;
        if (this->getBalance() >= 50) {
            this->removeMoney(50);
            this->setInJail(false);
        } else {
            this->setInJail(false);
            std::cout << this->getName() << " has been released from jail after 3 turns." << std::endl;
        }
    } else {
        this->setJailTurns(this->getJailTurns() + 1);
    }
}

// Property Building (Houses & Hotels)
// Manage the player's properties, allowing them to build houses or hotels
void Player::manageProperties() {
    if (streetProperties.empty()) {
        std::cout << "You don't own any properties." << std::endl;
        return;
    }

    // Iterate through the player's street properties and check if they can build
    for (Street* street : streetProperties) {
        if (ownsFullColorGroup(street->getColor())) {
            std::vector<Street*> colorGroupProperties = getPropertiesOfColorGroup(street->getColor());
            bool canBuild = true;
            int minHouses = colorGroupProperties[0]->getNumberOfHouses();

            // Ensure balanced building across the color group
            for (Street* prop : colorGroupProperties) {
                minHouses = std::min(minHouses, prop->getNumberOfHouses());
            }

            // Ensure the player builds evenly within the color group
            if (street->getNumberOfHouses() > minHouses) {
                std::cout << "You must build on the other properties of the same color group first." << std::endl;
                canBuild = false;
            }

            // Allow the player to build houses or hotels
            while (canBuild) {
                int houseCount = street->getNumberOfHouses();
                if (houseCount < 4) {
                    char choice;
                    std::cout << "Do you want to add a house to this property? (y/n): ";
                    std::cin >> choice;

                    if (choice == 'y' || choice == 'Y') {
                        if (street->buildHouse()) {
                            std::cout << "House added to " << street->getName() << std::endl;
                        } else {
                            std::cout << "Unable to build a house." << std::endl;
                        }
                    }
                } else if (houseCount == 4 && !street->getHasHotel()) {
                    char choice;
                    std::cout << "Do you want to add a hotel to this property? (y/n): ";
                    std::cin >> choice;

                    if (choice == 'y' || choice == 'Y') {
                        if (street->buildHotel()) {
                            std::cout << "Hotel added to " << street->getName() << std::endl;
                        } else {
                            std::cout << "Unable to build a hotel." << std::endl;
                        }
                    }
                } else {
                    std::cout << "No further construction possible on " << street->getName() << std::endl;
                    break;
                }
            }
        } else {
            std::cout << "You don't own all properties of the color group for " << street->getName() << "." << std::endl;
        }
    }
}