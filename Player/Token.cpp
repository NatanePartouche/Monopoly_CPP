#include "Token.hpp"

// Definition of the static set that holds the valid token names
const std::set<std::string> Token::validTokens = {
    "Top hat", "Dog", "Car", "Thimble", "Boot", "Battleship",
    "Iron", "Wheelbarrow", "Cat"
};

// Constructor: Initializes the token with the given token name
Token::Token(const std::string& tokenName) {
    setToken(tokenName);  // Use setToken to initialize both name and path
}

// Copy constructor: Creates a new Token by copying the name and path from another token
Token::Token(const Token& other)
    : name(other.name), Path_to_image(other.Path_to_image) {}  // Copy both name and Path_to_image

// Assignment operator: Handles the assignment of one Token object to another
Token& Token::operator=(const Token& other) {
    if (this != &other) {  // Avoid self-assignment
        setToken(other.name);  // Reuse setToken to assign the token name
        Path_to_image = other.Path_to_image;  // Copy the image path
    }
    return *this;
}

// Static method: Checks if a given token name is valid
bool Token::isValidToken(const std::string& tokenName) {
    // Find the token name in the set of valid tokens
    return validTokens.find(tokenName) != validTokens.end();
}

// Method: Sets a new token, validating the token name and updating the image path
void Token::setToken(const std::string& tokenName) {
    if (!isValidToken(tokenName)) {
        // Throw an error if the token name is invalid
        throw std::invalid_argument("Invalid token name: " + tokenName);
    }

    name = tokenName;

    // Set the corresponding image path based on the token name
    if (tokenName == "Car") {
        Path_to_image = "Car.png";
    } else if (tokenName == "Cat") {
        Path_to_image = "Cat.png";
    } else if (tokenName == "Top hat") {
        Path_to_image = "Top hat.png";
    } else if (tokenName == "Dog") {
        Path_to_image = "Dog.png";
    } else if (tokenName == "Battleship") {
        Path_to_image = "Battleship.png";
    } else if (tokenName == "Thimble") {
        Path_to_image = "Thimble.png";
    } else if (tokenName == "Wheelbarrow") {
        Path_to_image = "Wheelbarrow.png";
    } else if (tokenName == "Boot") {
        Path_to_image = "Boot.png";
    } else if (tokenName == "Iron") {
        Path_to_image = "Iron.png";
    } else {
        // Default case if no token name matches (should not happen with proper validation)
        Path_to_image = "../Design/Default.png";
    }
}

// Method: Returns the current token name by value (const because it does not modify the object)
std::string Token::getTokenName() const {return name;}

// Method: Returns a string representation of the token (used for logging or display)
std::string Token::display() const {
    return "Token: " + name;
}

// Static method: Returns the set of valid token names for selection purposes
std::set<std::string> Token::getValidTokens() {
    return validTokens;
}

// Method: Returns the path to the image associated with the current token
std::string Token::get_Path_to_image() const {
    return Path_to_image;
}