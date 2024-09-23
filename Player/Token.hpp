#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <set>
#include <stdexcept>

class Token {
private:
    std::string name;  // The name of the token (e.g., "Top hat", "Car", "Dog")

    // Static set of valid tokens, shared across all instances
    static const std::set<std::string> validTokens;

public:
    // Constructor
    Token(const std::string& tokenName = "Car");

    // Copy constructor
    Token(const Token& other);

    // Assignment operator
    Token& operator=(const Token& other);

    // Static method to check if the provided token name is valid
    static bool isValidToken(const std::string& tokenName);

    // Set a new token, validating it against the valid options
    void setToken(const std::string& tokenName);

    // Get the current token name
    std::string getTokenName() const;

    // Display the token's name as a string (can be used for logging or display elsewhere)
    std::string display() const;

    // Static method to return the set of valid tokens for display or selection purposes
    static std::set<std::string> getValidTokens();
};

#endif // TOKEN_HPP