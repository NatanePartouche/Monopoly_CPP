#include <iostream>
#include <vector>
#include <limits>  // Inclure <limits> pour std::numeric_limits
#include "../Player/Player.hpp"
#include "Board.hpp"

int main() {
    std::cout << "Monopoly C++ Game Started!" << std::endl;
    int num_of_Players;
    std::string tmp_player_name;

    // Initialize BOARD
    Board board;

    // Set players
    std::vector<Player> players_vector;

    // Loop to ensure a valid number of players is entered
    bool validNumberOfPlayers = false; // Flag to track if we have a valid number of players
    while (!validNumberOfPlayers) {
        std::cout << "Enter the desired number of players (between 2 and 8): ";
        std::cin >> num_of_Players;

        // If the input is not a number, clear the error and prompt again
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cerr << "Invalid input. Please enter a valid number." << std::endl;
            continue; // Prompt the user again
        }

        std::cin.ignore();  // Clear the newline character from the input buffer

        // Check if the number of players is within the valid range
        if (num_of_Players >= 2 && num_of_Players <= 8) {
            validNumberOfPlayers = true; // Exit the loop if the number of players is valid
        } else {
            std::cerr << "Invalid input. Player amount should be between 2 and 8 players." << std::endl;
        }
    }
    // STEP 1: Create players with just their names
    for (int i = 0; i < num_of_Players; ++i) {
        std::cout << "Enter the name of player " << i + 1 << ": ";
        std::getline(std::cin, tmp_player_name);

        // Create player with the name and add to the vector
        players_vector.emplace_back(tmp_player_name);  // Add player to the vector
    }
    // STEP 2: Allow each player to choose a token
    for (int i = 0; i < num_of_Players; ++i) {
        Player::choosePlayerToken(players_vector[i], players_vector);
    }









    return 0;
}