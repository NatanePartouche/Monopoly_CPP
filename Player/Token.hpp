#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <set>
#include <stdexcept>

class Token {
private:
    std::string name;  // The name of the token (e.g., "Top hat", "Car", "Dog")
    std::string Path_to_image;  // Path to the image representing the token

    // Static set of valid tokens, shared across all instances
    static const std::set<std::string> validTokens;

public:
    // Constructor: Initializes the token with a given token name
    Token(const std::string& tokenName = "Car");

    // Copy constructor: Copies another Token object
    Token(const Token& other);

    // Assignment operator: Assigns one Token object to another
    Token& operator=(const Token& other);

    // Static method to check if the provided token name is valid
    static bool isValidToken(const std::string& tokenName);

    // Set a new token, validating it against the valid options
    void setToken(const std::string& tokenName);

    // Get the current token name (const because it does not modify the object)
    std::string getTokenName() const;

    // Display the token's name as a string (for logging or display purposes)
    std::string display() const;

    // Static method to return the set of valid tokens for display or selection purposes
    static std::set<std::string> getValidTokens();

    // Get the path to the image associated with the token
    std::string get_Path_to_image() const;
};

#endif // TOKEN_HPP