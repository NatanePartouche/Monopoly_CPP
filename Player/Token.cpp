#include "Token.hpp"

// Static member definition
const std::set<std::string> Token::validTokens = {
    "Top hat", "Dog", "Car", "Thimble", "Boot", "Battleship",
    "Iron", "Wheelbarrow", "Cat"
};

// Constructor
Token::Token(const std::string& tokenName) {
    setToken(tokenName);
}

// Copy constructor
Token::Token(const Token& other) : name(other.name) {}

// Assignment operator
Token& Token::operator=(const Token& other) {
    if (this != &other) {  // Avoid self-assignment
        setToken(other.name);
    }
    return *this;
}

// Static method to check if the provided token name is valid
bool Token::isValidToken(const std::string& tokenName) {
    return validTokens.find(tokenName) != validTokens.end();
}

// Set a new token, validating it against the valid options
void Token::setToken(const std::string& tokenName) {
    if (!isValidToken(tokenName)) {
        throw std::invalid_argument("Invalid token choice: '" + tokenName + "'. Please select a valid token.");
    }
    name = tokenName;
}

// Get the current token name
std::string Token::getTokenName() const {
    return name;
}

// Display the token's name as a string
std::string Token::display() const {
    return "Token: " + name;
}

// Static method to return the set of valid tokens for display or selection purposes
std::set<std::string> Token::getValidTokens() {
    return validTokens;
}