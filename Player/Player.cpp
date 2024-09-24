#include "Player.hpp"
#include "Street.hpp"
#include "RailRoad.hpp"
#include "Utility.hpp"

// Constructor: Initialize the player with a name
Player::Player(const std::string& playerName) : name(playerName) {}

// Getters
std::string Player::getName() const { return name; }
std::string Player::getToken() const { return token.getTokenName(); }
int Player::getBalance() const { return moneyWallet; }
int Player::getPosition() const { return position; }
bool Player::isInJail() const { return inJail; }
bool Player::getCard_out_of_jail() const { return card_get_out_of_jail; }
int Player::getJailTurns() const { return JailTurns; }
int Player::getBoardTurns() const { return boardTurns; }
std::vector<Street*> Player::getStreetProperties() const { return streetProperties; }
std::vector<RailRoad*> Player::getRailroadProperties() const { return railroadProperties; }
std::vector<Utility*> Player::getUtilityProperties() const { return utilityProperties; }

// Setters
void Player::setName(const std::string& newName) { name = newName; }
void Player::setToken(const Token& newToken) { token = newToken; }
void Player::setBalance(int newBalance) { moneyWallet = newBalance; }
void Player::setPosition(int newPosition) { position = newPosition; }
void Player::setInJail(bool jailStatus) { inJail = jailStatus; }
void Player::setCard_out_of_jail(bool jailStatus) { card_get_out_of_jail = jailStatus; }
void Player::setBoardTurns(int turns) { boardTurns = turns; }
void Player::setStreetProperties(const std::vector<Street*>& streets) { streetProperties = streets; }
void Player::setRailroadProperties(const std::vector<RailRoad*>& railroads) { railroadProperties = railroads; }
void Player::setUtilityProperties(const std::vector<Utility*>& utilities) { utilityProperties = utilities; }
void Player::setJailTurns(int turns) { JailTurns = turns; }

// Check if the player owns all properties in a color group
bool Player::ownsFullColorGroup(Color color) {
    int requiredProperties = 0;

    // Determine how many properties are needed for each color group
    switch (color) {
        case Color::Brown:
            requiredProperties = 2;
            break;
        case Color::LightBlue:
        case Color::Pink:
        case Color::Orange:
        case Color::Red:
        case Color::Yellow:
        case Color::Green:
            requiredProperties = 3;
            break;
        case Color::DarkBlue:
            requiredProperties = 2;
            break;
    }

    // Count how many properties of the specified color the player owns
    int ownedProperties = 0;
    for (const Street* street : streetProperties) {
        if (street->getColor() == color) {
            ownedProperties++;
        }
    }

    return ownedProperties == requiredProperties;
}

// Display the player's current status
void Player::display() const {
    std::cout << "Player: " << name << "\n"
              << "Token: " << token.getTokenName() << "\n"
              << "Position: " << position << "\n"
              << "Balance: $" << moneyWallet << "\n"
              << "In Jail: " << (inJail ? "Yes" : "No") << "\n"
              << "Get Out of Jail Card: " << (card_get_out_of_jail ? "Yes" : "No") << "\n"
              << "Owned Properties: " << streetProperties.size() + railroadProperties.size() + utilityProperties.size() << "\n"
              << "Turns Played: " << boardTurns << std::endl;
}

// Get a list of available tokens for selection by filtering out those already taken by other players
std::string Player::getAvailableTokensAsString(const std::vector<Player>& players) {
    Token token;  // Temporary token object to access valid tokens
    std::set<std::string> availableTokens = token.getValidTokens();  // Get the set of valid tokens

    // Remove tokens that are already taken by other players
    for (const Player& player : players) {
        std::string playerToken = player.getToken();  // Get the player's token
        availableTokens.erase(playerToken);  // Remove it from available tokens
    }

    // Convert the remaining available tokens into a string
    std::string tokensList;
    for (const auto& tokenName : availableTokens) {
        tokensList += "\n" + tokenName;
    }

    return tokensList;
}

// Player token selection: prompts player to select a token from available options
void Player::choosePlayerToken(Player& currentPlayer, const std::vector<Player>& players_vector) {
    std::string tmp_token_name;
    bool validTokenSelected = false;

    // Loop until a valid token is selected
    while (!validTokenSelected) {
        std::cout << "\nPlayer " << currentPlayer.getName() << ", choose an available token:\n";
        std::string availableTokensList = Player::getAvailableTokensAsString(players_vector);
        std::cout << availableTokensList << std::endl;
        std::cout << "\nEnter the name of the chosen token for " << currentPlayer.getName() << ": ";
        std::getline(std::cin, tmp_token_name);

        // Check if the selected token is valid
        if (Token::isValidToken(tmp_token_name)) {
            currentPlayer.setToken(tmp_token_name);  // Set the token for the player
            validTokenSelected = true;
        } else {
            std::cout << "The token name is invalid or already taken. Please try again." << std::endl;
        }
    }
}

// Add money to the player's balance
void Player::addMoney(int amount) {
    if (amount > 0) {
        moneyWallet += amount;
        std::cout << name << " received " << amount << "M$. New balance: " << moneyWallet << "M$." << std::endl;
    }
}

// Remove money from the player's balance
bool Player::removeMoney(int amount) {
    moneyWallet -= amount;
    std::cout << name << " paid " << amount << "M$. New balance: " << moneyWallet << "M$." << std::endl;
    return true;
}

// Add a Street property to the player's portfolio
void Player::addStreetProperty(Street* street) {
    streetProperties.push_back(street);
    std::cout << name << " has acquired the property: " << street->getName() << std::endl;
}

// Add a RailRoad property to the player's portfolio
void Player::addRailroadProperty(RailRoad* railroad) {
    railroadProperties.push_back(railroad);
    std::cout << name << " has acquired the railroad: " << railroad->getName() << std::endl;
}

// Add a Utility property to the player's portfolio
void Player::addUtilityProperty(Utility* utility) {
    utilityProperties.push_back(utility);
    std::cout << name << " has acquired the utility: " << utility->getName() << std::endl;
}

// Check balances of all players and remove those with a negative balance
bool Player::checkPlayerBalances(std::vector<Player>& players) {
    // Remove players with negative balances and notify
    players.erase(std::remove_if(players.begin(), players.end(),
        [](const Player& player) {
            if (player.getBalance() <= 0) {
                std::cout << player.getName() << " has been eliminated from the game due to a negative balance." << std::endl;
                return true;
            }
            return false;
        }),
        players.end());

    // Check if any player has won by reaching 4000 balance
    for (const auto& player : players) {
        if (player.getBalance() >= 4000) {
            std::cout << "Congratulations " << player.getName() << "!" << std::endl;
            std::cout << "You have won the game with a balance of " << player.getBalance() << " $ !" << std::endl;
            return false;  // End game
        }
    }
    return true;  // Game continues
}

// Manage player's properties (add houses or hotels)
void Player::manageProperties() {
    if (streetProperties.empty()) {
        std::cout << "You don't own any properties." << std::endl;
        return;
    }

    char choice;
    std::cout << "Do you want to add a house or hotel? (y/n): ";
    std::cin >> choice;

    if (choice != 'y' && choice != 'Y') {
        std::cout << "No changes made to your properties." << std::endl;
        return;
    }

    // Iterate through owned street properties and allow the player to upgrade them
    for (Street* street : streetProperties) {
        if (ownsFullColorGroup(street->getColor())) {
            int houseCount = street->getNumberOfHouses();
            if (houseCount < 4) {
                std::cout << "You can add a house to the property: " << street->getName() << std::endl;
                street->buildHouse();
            } else if (houseCount == 4) {
                std::cout << "You can add a hotel to " << street->getName() << "." << std::endl;
                street->buildHotel();
            }
        } else {
            std::cout << "You don't own all properties of the color group." << std::endl;
        }
    }
}

// Handle player attempting to release from jail
void Player::attemptToReleaseFromJail() {
    if (!this->isInJail()) { return; }

    // Option 1: Use "Get Out of Jail Free" card
    if (this->getCard_out_of_jail()) {
        std::cout << this->getName() << " used a 'Get Out of Jail Free' card!" << std::endl;
        this->setInJail(false);
        this->setCard_out_of_jail(false);
        return;
    }

    // Option 2: Pay 50 NIS fine
    char choice;
    std::cout << this->getName() << ", do you want to pay a fine of 50 NIS to get out of jail? (y/n): ";
    std::cin >> choice;

    if ((choice == 'y' || choice == 'Y') && this->getBalance() >= 50) {
        this->removeMoney(50);
        std::cout << this->getName() << " paid 50 NIS and is out of jail!" << std::endl;
        this->setInJail(false);
        return;
    } else if (choice == 'y' && this->getBalance() < 50) {
        std::cout << "Insufficient funds to pay the fine!" << std::endl;
    }

    // Option 3: Roll for a double to get out
    Dice dice;
    dice.roll();
    std::cout << this->getName() << " rolled a " << dice.get_die_1() << " and " << dice.get_die_2() << "." << std::endl;

    if (dice.isDouble()) {
        std::cout << this->getName() << " rolled a double and is out of jail!" << std::endl;
        this->setInJail(false);
    } else {
        std::cout << this->getName() << " did not roll a double." << std::endl;
    }

    // If player spends 3 turns in jail, they must pay the fine
    if (this->getJailTurns() >= 3) {
        std::cout << this->getName() << " has spent 3 turns in jail. Must pay 50 NIS to get out." << std::endl;
        if (this->getBalance() >= 50) {
            this->removeMoney(50);
            std::cout << this->getName() << " paid 50 NIS and is out of jail after 3 turns." << std::endl;
            this->setInJail(false);
        } else {
            std::cout << this->getName() << " does not have enough money to pay the fine, but must still leave jail." << std::endl;
            this->setInJail(false);  // Player is released after 3 turns, even without money
        }
    } else {
        this->setJailTurns(this->getJailTurns() + 1);
        std::cout << this->getName() << " has been in jail for " << this->getJailTurns() << " turns." << std::endl;
    }
}