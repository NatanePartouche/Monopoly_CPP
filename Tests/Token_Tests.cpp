#include "doctest.h"
#include "../Player/Token.hpp"

// Test for token validation
TEST_CASE("Token validation") {
    CHECK(Token::isValidToken("Car") == true);  // "Car" is a valid token name
    CHECK(Token::isValidToken("Cat") == true);  // "Cat" is a valid token name
    CHECK(Token::isValidToken("InvalidToken") == false);  // "InvalidToken" is not valid
}

// Test for token creation and verification of name and image path
TEST_CASE("Token creation and image path verification") {
    Token token("Car");
    CHECK(token.getTokenName() == "Car");
    CHECK(token.get_Path_to_image() == "Car.png");

    Token token2("Cat");
    CHECK(token2.getTokenName() == "Cat");
    CHECK(token2.get_Path_to_image() == "Cat.png");

    CHECK_THROWS_AS(Token("InvalidToken"), std::invalid_argument);  // Creating an invalid token should throw an exception
}

// Test for copy constructor
TEST_CASE("Token copy constructor") {
    Token originalToken("Dog");
    Token copiedToken(originalToken);

    CHECK(copiedToken.getTokenName() == originalToken.getTokenName());  // The name should be copied correctly
    CHECK(copiedToken.get_Path_to_image() == originalToken.get_Path_to_image());  // The image path should be copied
}

// Test for assignment operator
TEST_CASE("Token assignment operator") {
    Token token1("Top hat");
    Token token2("Iron");

    token1 = token2;  // Assignment

    CHECK(token1.getTokenName() == token2.getTokenName());  // The name should be copied correctly
    CHECK(token1.get_Path_to_image() == token2.get_Path_to_image());  // The image path should be copied
}

// Test for the display method
TEST_CASE("Token display method") {
    Token token("Battleship");
    CHECK(token.display() == "Token: Battleship");
}

// Test for retrieving the list of valid tokens
TEST_CASE("Get valid tokens list") {
    std::set<std::string> validTokens = Token::getValidTokens();
    CHECK(validTokens.find("Car") != validTokens.end());  // "Car" should be in the list
    CHECK(validTokens.find("Thimble") != validTokens.end());  // "Thimble" should be in the list
    CHECK(validTokens.find("InvalidToken") == validTokens.end());  // "InvalidToken" should not be in the list
}