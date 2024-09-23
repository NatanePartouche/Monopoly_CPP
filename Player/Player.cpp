#include "Player.hpp"
#include "Street.hpp"  // Inclure Street.hpp ici, pas dans Player.hpp
#include "RailRoad.hpp"
#include "Utility.hpp"

// Constructor to initialize the player with a name and token
Player::Player(const std::string& playerName) : name(playerName) {}

// Default constructor
Player::Player() : name("Default Player"), token("Car") {}  // Constructeur par défaut

// Getters
std::string Player::getName() const { return name; }
std::string Player::getToken() const { return token.getTokenName(); }
int Player::getBalance() const { return moneyWallet; }
int Player::getPosition() const { return position; }
bool Player::isInJail() const { return inJail; }
int Player::getJailTurns() const { return jailTurns; }
bool Player::hasJailCard() const { return hasGetOutOfJailCard; }
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
void Player::setJailTurns(int turns) { jailTurns = turns; }
void Player::setHasGetOutOfJailCard(bool hasCard) { hasGetOutOfJailCard = hasCard; }
void Player::setBoardTurns(int turns) { boardTurns = turns; }
void Player::setStreetProperties(const std::vector<Street*>& streets) { streetProperties = streets; }
void Player::setRailroadProperties(const std::vector<RailRoad*>& railroads) { railroadProperties = railroads; }
void Player::setUtilityProperties(const std::vector<Utility*>& utilities) { utilityProperties = utilities; }

// Fonction pour vérifier si le joueur possède toutes les propriétés d'un groupe de couleur
bool Player::ownsFullColorGroup(Color color) {
    int requiredProperties = 0;
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

    int ownedProperties = 0;
    for (const Street* street : streetProperties) {
        if (street->getColor() == color) {
            ownedProperties++;
        }
    }

    return ownedProperties == requiredProperties;
}

// Affichage de l'état actuel du joueur
void Player::display() const {
    std::cout << "Player: " << name << "\n"
              << "Token: " << token.getTokenName() << "\n"
              << "Position: " << position << "\n"
              << "Balance: $" << moneyWallet << "\n"
              << "In Jail: " << (inJail ? "Yes" : "No") << "\n"
              << "Get Out of Jail Card: " << (hasGetOutOfJailCard ? "Yes" : "No") << "\n"
              << "Owned Properties: " << streetProperties.size() + railroadProperties.size() + utilityProperties.size() << "\n"
              << "Turns Played: " << boardTurns << std::endl;
}

std::string Player::getAvailableTokensAsString(const std::vector<Player>& players) {
    // Liste initiale de tous les tokens valides
    Token token;  // Objet temporaire pour accéder aux tokens valides
    std::set<std::string> availableTokens = token.getValidTokens();

    // Parcours de la liste des joueurs pour enlever les tokens déjà choisis
    for (const Player& player : players) {
        std::string playerToken = player.getToken();  // Récupérer le token du joueur
        availableTokens.erase(playerToken);  // Supprimer le token du joueur des tokens disponibles
    }

    // Concaténer chaque token dans un string avec un \n avant chaque nom
    std::string tokensList;
    for (const auto& tokenName : availableTokens) {
        tokensList += "\n" + tokenName;  // Ajouter le retour à la ligne avant chaque nom de token
    }

    return tokensList;  // Retourner la chaîne de caractères avec les tokens disponibles
}

// Function to handle player token selection
void Player::choosePlayerToken(Player& currentPlayer, const std::vector<Player>& players_vector) {
    std::string tmp_token_name;
    bool validTokenSelected = false;  // This flag indicates if the player has selected a valid token

    // This loop continues until the player selects a valid, available token
    while (!validTokenSelected) {
        // Prompt the player to choose a token
        std::cout << "\nPlayer " << currentPlayer.getName() << ", choose an available token:\n";

        // Retrieve and display the list of available tokens by calling a method from the Player class
        std::string availableTokensList = Player::getAvailableTokensAsString(players_vector);
        std::cout << availableTokensList << std::endl;

        // Ask the player to enter their chosen token name
        std::cout << "Enter the name of the chosen token for " << currentPlayer.getName() << ": ";
        std::getline(std::cin, tmp_token_name);  // Read the player's input

        // Check if the entered token name is valid
        // The `isValidToken` method checks if the token name exists in the set of valid tokens
        if (Token::isValidToken(tmp_token_name)) {
            // If the token is valid, assign it to the current player using the `setToken` method
            currentPlayer.setToken(tmp_token_name);
            validTokenSelected = true;  // Set the flag to true to exit the loop
        } else {
            // If the token is invalid (or already taken), prompt the player to try again
            std::cout << "The token name is invalid or already taken. Please try again." << std::endl;
        }
    }
}
