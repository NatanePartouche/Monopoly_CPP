#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include "../Player/Player.hpp"
#include "Board.hpp"
#include "Dice.hpp"
#include <string>

// Fonction pour initialiser les positions des 40 cases du plateau
std::vector<sf::Vector2f> initializeBoardPositions(float scaleX, float scaleY) {
    std::vector<sf::Vector2f> positions(40);
    // Bas du plateau (cases 0 à 9)
    positions[0] = sf::Vector2f(1800 * scaleX, 1800 * scaleY);
    positions[1] = sf::Vector2f(1580 * scaleX, 1800 * scaleY);
    positions[2] = sf::Vector2f(1420 * scaleX, 1800 * scaleY);
    positions[3] = sf::Vector2f(1240 * scaleX, 1800 * scaleY);
    positions[4] = sf::Vector2f(1080 * scaleX, 1800 * scaleY);
    positions[5] = sf::Vector2f(915 * scaleX, 1800 * scaleY);
    positions[6] = sf::Vector2f(750 * scaleX, 1800 * scaleY);
    positions[7] = sf::Vector2f(590 * scaleX, 1800 * scaleY);
    positions[8] = sf::Vector2f(425 * scaleX, 1800 * scaleY);
    positions[9] = sf::Vector2f(260 * scaleX, 1800 * scaleY);
    positions[10] = sf::Vector2f(20 * scaleX, 1800 * scaleY);
    positions[11] = sf::Vector2f(10 * scaleX, 1590 * scaleY);
    positions[12] = sf::Vector2f(10 * scaleX, 1410* scaleY);
    positions[13] = sf::Vector2f(10 * scaleX, 1250 * scaleY);
    positions[14] = sf::Vector2f(10 * scaleX, 1090 * scaleY);
    positions[15] = sf::Vector2f(10 * scaleX, 930 * scaleY);
    positions[16] = sf::Vector2f(10 * scaleX, 760 * scaleY);
    positions[17] = sf::Vector2f(10 * scaleX, 600 * scaleY);
    positions[18] = sf::Vector2f(10 * scaleX, 440 * scaleY);
    positions[19] = sf::Vector2f(10 * scaleX, 260 * scaleY);
    positions[20] = sf::Vector2f(20 * scaleX, 20 * scaleY);
    positions[21] = sf::Vector2f(260 * scaleX, 20 * scaleY);
    positions[22] = sf::Vector2f(430 * scaleX, 20 * scaleY);
    positions[23] = sf::Vector2f(590 * scaleX, 20 * scaleY);
    positions[24] = sf::Vector2f(760 * scaleX, 20 * scaleY);
    positions[25] = sf::Vector2f(920 * scaleX, 20 * scaleY);
    positions[26] = sf::Vector2f(1080 * scaleX, 20 * scaleY);
    positions[27] = sf::Vector2f(1250 * scaleX, 20 * scaleY);
    positions[28] = sf::Vector2f(1405 * scaleX, 20 * scaleY);
    positions[29] = sf::Vector2f(1575 * scaleX, 20 * scaleY);
    positions[30] = sf::Vector2f(1800 * scaleX, 20 * scaleY);
    positions[31] = sf::Vector2f(1800 * scaleX, 270 * scaleY);
    positions[32] = sf::Vector2f(1800 * scaleX, 430 * scaleY);
    positions[33] = sf::Vector2f(1800 * scaleX, 600 * scaleY);
    positions[34] = sf::Vector2f(1800 * scaleX, 770 * scaleY);
    positions[35] = sf::Vector2f(1800 * scaleX, 930 * scaleY);
    positions[36] = sf::Vector2f(1800 * scaleX, 1100 * scaleY);
    positions[37] = sf::Vector2f(1800 * scaleX, 1250 * scaleY);
    positions[38] = sf::Vector2f(1800 * scaleX, 1420 * scaleY);
    positions[39] = sf::Vector2f(1800 * scaleX, 1580 * scaleY);
    return positions;
}

int main() {

    // Dimensions de la fenêtre
    const unsigned int windowWidth = 900;
    const unsigned int windowHeight = 800;
    const unsigned int boardWidth = 2000;
    const unsigned int boardHeight = 2000;
    // Création de la fenêtre SFML
    sf::RenderWindow window___2(sf::VideoMode(windowWidth, windowHeight), "Monopoly Board");
    // Chargement de l'image du plateau
    sf::Texture boardTexture;
    if (!boardTexture.loadFromFile("board.png")) {
        std::cerr << "Error: Unable to load the board image.\n";
        return -1;
    }
    boardTexture.setSmooth(true);
    sf::Sprite boardSprite;
    boardSprite.setTexture(boardTexture);
    float scaleX = static_cast<float>(windowWidth) / boardWidth;
    float scaleY = static_cast<float>(windowHeight) / boardHeight;
    boardSprite.setScale(scaleX, scaleY);
    std::vector<sf::Vector2f> boardPositions = initializeBoardPositions(scaleX, scaleY);
    std::vector<sf::RectangleShape> zoneRectangles(40);
    for (int i = 0; i < 40; ++i) {
        sf::RectangleShape rect(sf::Vector2f(160 * scaleX, 150 * scaleY));
        rect.setPosition(boardPositions[i]);
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineColor(sf::Color::Red);
        rect.setOutlineThickness(1);
        zoneRectangles[i] = rect;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        }
        else {std::cerr << "Invalid input. Player amount should be between 2 and 8 players." << std::endl;}
    }
    for (int i = 0; i < num_of_Players; ++i) {
        do {
            std::cout << "Enter the name of player " << i + 1 << ": ";
            std::getline(std::cin, tmp_player_name);

            if (tmp_player_name.empty()) {
                std::cout << "Player name cannot be empty. Please enter a valid name." << std::endl;
            }
        } while (tmp_player_name.empty());

        players_vector.emplace_back(tmp_player_name);  // Add player to vector
    }
    // Loop to allow each player to choose a token
    for (int i = 0; i < num_of_Players; ++i) {
        Player::choosePlayerToken(players_vector[i], players_vector);
    }
    /////// TELECHARGEMENT DE L IMAGE DEs DU PIONs //////////
    std::vector<sf::Sprite> playerSprites(players_vector.size());
    std::vector<sf::Texture> playerTextures(players_vector.size());
    for (size_t i = 0; i < players_vector.size(); ++i) {
        if (!playerTextures[i].loadFromFile(players_vector[i].getToken().get_Path_to_image())) {
            std::cerr << "Error: Unable to load the token image for player " << i + 1 << ".\n";
        }
        playerTextures[i].setSmooth(true);
        playerSprites[i].setTexture(playerTextures[i]);
        float redSquareWidth = 160 * scaleX;
        float redSquareHeight = 150 * scaleY;
        float pionScaleX = (redSquareWidth / 4) / playerTextures[i].getSize().x;
        float pionScaleY = (redSquareHeight / 2) / playerTextures[i].getSize().y;
        playerSprites[i].setScale(pionScaleX, pionScaleY);
    }
    auto getPlayerOffset = [](int playerIndex, float squareWidth, float squareHeight) -> sf::Vector2f {
        float offsetX = (playerIndex % 4) * (squareWidth / 4);
        float offsetY = (playerIndex / 4) * (squareHeight / 2);
        return sf::Vector2f(offsetX, offsetY);
    };
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

     while (window___2.isOpen()) {

         // STEP 2 : Game loop
         std::cout << "\n" << std::endl;
         bool gameOn = true;  // Main game loop flag

         while (gameOn) {
             // Iterate through each player's turn
             for (int i = 0; i < num_of_Players; ++i) {

// affichage du plateau
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                 sf::Event event;
                 while (window___2.pollEvent(event)) {
                     if (event.type == sf::Event::Closed) {window___2.close();}
                 }
                 window___2.clear(sf::Color(255, 255, 255));
                 window___2.draw(boardSprite);
                 for (size_t i = 0; i < players_vector.size(); ++i) {
                     int currentSquare = players_vector[i].getPosition();
                     int playerIndexInSquare = 0;
                     for (size_t j = 0; j < players_vector.size(); ++j) {
                         if (players_vector[j].getPosition() == currentSquare) {
                             sf::Vector2f offset = getPlayerOffset(playerIndexInSquare++, 160 * scaleX, 150 * scaleY);
                             playerSprites[j].setPosition(boardPositions[currentSquare] + offset);
                             window___2.draw(playerSprites[j]);
                         }
                     }
                 }
                 window___2.display();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                 std::cout << "-------------------------------------------------------------" << std::endl;
                 std::cout << players_vector[i].getName() << "'s turn!" << std::endl;
                 // Check if the player is in jail
                 if( (players_vector[i].isInJail()) && (players_vector[i].getPosition()==10) ) {
                     players_vector[i].attemptToReleaseFromJail(); // Try to release from jail
                     continue;  // Skip the rest of the turn if in jail
                 }

                 // Roll the dice
                 int diceRoll = dice.roll();
                 std::cout << players_vector[i].getName() << " rolled a " << diceRoll << "!" << std::endl;
                 std::cout << "-------------------------------------------------------------" << std::endl;
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
                     }
                     /**************************************************************************************************************************/
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
    std::cout << "Game over!" << std::endl;
    return 0;
}