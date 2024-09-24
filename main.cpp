#include <iostream>
#include <vector>
#include <limits>
#include "../Player/Player.hpp"
#include "Board.hpp"
#include "Dice.hpp"

int main() {

    std::cout << "Monopoly C++ Game Started!" << std::endl;

    // Initialize BOARD, PLAYERS and DICE
    Board board;  // Create the game board
    Dice dice;    // Create a dice object for rolling
    std::vector<Player> players_vector; // Vector to store players
    int num_of_Players;  // Variable to store the number of players
    std::string tmp_player_name;  // Temporary string for player names

    // STEP 1 :
    // Create players with just their names
    // Allow each player to choose a token
    {
    // Loop to ensure a valid number of players is entered
    bool validNumberOfPlayers = false;
    while (!validNumberOfPlayers) {
        // Prompt the user to enter the number of players
        std::cout << "Enter the desired number of players (between 2 and 8): ";
        std::cin >> num_of_Players;
        if (std::cin.fail()) {
            // Handle invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Invalid input. Please enter a valid number." << std::endl;
            continue;
        }
        std::cin.ignore(); // Clear the input buffer
        if (num_of_Players >= 2 && num_of_Players <= 8) {
            validNumberOfPlayers = true;  // Accept valid number of players
        } else {
            std::cerr << "Invalid input. Player amount should be between 2 and 8 players." << std::endl;
        }
    }

        // Loop to create players by their names
        for (int i = 0; i < num_of_Players; ++i) {
            std::cout << "Enter the name of player " << i + 1 << ": ";
            std::getline(std::cin, tmp_player_name);
            players_vector.emplace_back(tmp_player_name);  // Add player to vector
        }

        // Loop to allow each player to choose a token
        for (int i = 0; i < num_of_Players; ++i) {
            Player::choosePlayerToken(players_vector[i], players_vector);
        }
    }

    // STEP 2 : Game loop
    {
        std::cout << "\n" << std::endl;
        bool gameOn = true;  // Main game loop flag
        while (gameOn) {
            // Iterate through each player's turn
            for (int i = 0; i < num_of_Players; ++i) {
                std::cout << players_vector[i].getName() << "'s turn!" << std::endl;

                // Check if the player is in jail
                if( (players_vector[i].isInJail()) && (players_vector[i].getPosition()==10) ) {
                    players_vector[i].attemptToReleaseFromJail(); // Try to release from jail
                    continue;  // Skip the rest of the turn if in jail
                }

                // Ask player if they want to roll the dice
                char choice;
                bool validChoice = false;

                while (!validChoice) {
                    std::cout << "Do you want to roll the dice? (y/n): ";
                    std::cin >> choice;

                    // Handle player decision to roll or not
                    if (choice == 'y' || choice == 'Y') {
                        validChoice = true;
                    } else if (choice == 'n' || choice == 'N') {
                        validChoice = true;
                        std::cout << players_vector[i].getName() << " has chosen not to roll the dice this turn." << std::endl;
                        break;  // Skip player movement if they don't roll the dice
                    } else {
                        std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << std::endl;
                    }
                }
                // Skip to the next player if they chose not to roll the dice
                if (choice == 'n' || choice == 'N') {continue;}

                // Roll the dice
                int diceRoll = dice.roll();
                std::cout << players_vector[i].getName() << " rolled a " << diceRoll << "!" << std::endl;

                // Move the player according to the dice roll
                int position = players_vector[i].getPosition() + diceRoll;
                if (position > 39) {
                    position = position - 39;  // Player passed GO, loop back
                    std::cout << "You passed the GO space, you receive 200M$ !!!" << std::endl;
                    players_vector[i].addMoney(200);  // Award 200 when passing GO
                    players_vector[i].setBoardTurns(players_vector[i].getBoardTurns() + 1);  // Track turns on the board
                }
                players_vector[i].setPosition(position);  // Update player position
                std::cout << players_vector[i].getName() << " is now on square " << players_vector[i].getPosition() << std::endl;

                // Handle player's action for the square they landed on
                Board::handlePlayerTurn(board, players_vector[i]);

                // Allow player to manage properties
                players_vector[i].manageProperties();

                // Check if the game continues based on player balances
                gameOn = Player::checkPlayerBalances(players_vector);


                /*
                 *  This block of code manages the special case where a player rolls doubles with the dice.
                 *  According to Monopoly rules, if a player rolls a double, they get an additional turn and can roll the dice again.
                 *  The code is structured to allow the player to roll again for each double they roll.
                 *  However, if a player rolls three consecutive doubles, they are immediately sent to jail.
                 *  The code checks for this scenario and, if triggered,moves the player directly to the jail square (position 10)
                 *  and sets their “in jail” status to true, thus ending their turn.
                 *  Each double-roll sequence is handled within its own block, allowing the player to continue their turn seamlessly
                 *  until either they stop rolling doubles or are sent to jail after three consecutive doubles.
                 */
                {
                    /**************************************************************************************************************************/
                    // if the first roll of the dice is a double he rolls the dice again to play again
                    if (dice.isDouble()) {
                        std::cout << players_vector[i].getName() << " rolled a " << dice.get_die_1() << " and " << dice.get_die_2() << "." << std::endl;
                        std::cout << "You made a double! " << players_vector[i].getName() << ", you get to roll again!" << std::endl;
                        std::cout << players_vector[i].getName() << "'s turn!" << std::endl;
                        if( (players_vector[i].isInJail()) && (players_vector[i].getPosition()==10) ) {players_vector[i].attemptToReleaseFromJail();continue;}
                        char choice;bool validChoice = false;while (!validChoice) { std::cout << "Do you want to roll the dice? (y/n): ";std::cin >> choice;
                            if (choice == 'y' || choice == 'Y') {validChoice = true;} else if (choice == 'n' || choice == 'N') {
                                validChoice = true;std::cout << players_vector[i].getName() << " has chosen not to roll the dice this turn." << std::endl;break;
                            } else {std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << std::endl;}}if (choice == 'n' || choice == 'N') {continue;}
                        int diceRoll = dice.roll();std::cout << players_vector[i].getName() << " rolled a " << diceRoll << "!" << std::endl;int position = players_vector[i].getPosition() + diceRoll;
                        if (position > 39) {position = position - 39;std::cout << "You passed the GO space, you receive 200M$ !!!" << std::endl;
                            players_vector[i].addMoney(200);players_vector[i].setBoardTurns(players_vector[i].getBoardTurns() + 1);}players_vector[i].setPosition(position);
                        std::cout << players_vector[i].getName() << " is now on square " << players_vector[i].getPosition() << std::endl;
                        Board::handlePlayerTurn(board, players_vector[i]);players_vector[i].manageProperties();gameOn = Player::checkPlayerBalances(players_vector);
                    }/**************************************************************************************************************************/

                    /**************************************************************************************************************************/
                    // if the second roll of the dice is a double he rolls the dice again to play again
                    if (dice.isDouble()) {
                        std::cout << players_vector[i].getName() << " rolled a " << dice.get_die_1() << " and " << dice.get_die_2() << "." << std::endl;
                        std::cout << "You made a double! " << players_vector[i].getName() << ", you get to roll again!" << std::endl;std::cout << players_vector[i].getName() << "'s turn!" << std::endl;
                        if( (players_vector[i].isInJail()) && (players_vector[i].getPosition()==10) ) {players_vector[i].attemptToReleaseFromJail();continue;}
                        char choice;bool validChoice = false;while (!validChoice) {
                            std::cout << "Do you want to roll the dice? (y/n): ";std::cin >> choice;
                            if (choice == 'y' || choice == 'Y') {validChoice = true;} else if (choice == 'n' || choice == 'N') {
                                validChoice = true;std::cout << players_vector[i].getName() << " has chosen not to roll the dice this turn." << std::endl;break;
                            } else {std::cout << "Invalid input. Please enter 'y' for yes or 'n' for no." << std::endl;}}if (choice == 'n' || choice == 'N') {continue;}
                        int diceRoll = dice.roll();
                        if (dice.isDouble()) {/*****************************************************************************************************/
                            std::cout <<"Oh no! You’ve rolled three doubles in a row. Go to jail!"<< std::endl;
                            players_vector[i].setPosition(10);
                            players_vector[i].setInJail(true);
                            continue;/***************************************************************************************************************/
                        }
                        std::cout << players_vector[i].getName() << " rolled a " << diceRoll << "!" << std::endl;int position = players_vector[i].getPosition() + diceRoll;
                        if (position > 39) {position = position - 39;std::cout << "You passed the GO space, you receive 200M$ !!!" << std::endl;
                            players_vector[i].addMoney(200);players_vector[i].setBoardTurns(players_vector[i].getBoardTurns() + 1);}players_vector[i].setPosition(position);
                        std::cout << players_vector[i].getName() << " is now on square " << players_vector[i].getPosition() << std::endl;
                        Board::handlePlayerTurn(board, players_vector[i]);players_vector[i].manageProperties();gameOn = Player::checkPlayerBalances(players_vector);
                    }
                    /**************************************************************************************************************************/
                }

            }
        }
    }

    std::cout << "Game over!" << std::endl;

    return 0;
}