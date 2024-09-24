#ifndef CHANCECARD_HPP
#define CHANCECARD_HPP

#include <iostream>
#include <vector>
#include <functional>  // To use std::function for actions
#include <random>
#include "../Player/Player.hpp"  // Include the Player class to apply actions on the player

class ChanceCard {
private:
    std::vector<std::function<void(Player*)>> actions;  // A vector to store 16 actions

public:
    // Constructor to initialize the 16 actions
    ChanceCard() {
        // Add 16 different actions to the actions vector
        actions.emplace_back([](Player* player) {
            std::cout << "You win 150M$!" << std::endl;
            player->addMoney(150);
        });
        actions.emplace_back([](Player* player) {
            std::cout << "You lose 200M$!" << std::endl;
            player->removeMoney(200);
        });
        actions.emplace_back([](Player* player) {
            std::cout << "You move forward 3 spaces." << std::endl;
            player->setPosition(player->getPosition() + 3);


            ///
            ///
            ///
            ///
            ///
        });
        actions.emplace_back([](Player* player) {
            std::cout << "Move back 2 spaces." << std::endl;
            player->setPosition(player->getPosition() - 2);
            ////
            ///
            ///
            ///
            ///
            ///
        });
        actions.emplace_back([](Player* player) {
            std::cout << "Go directly to jail." << std::endl;
            player->setPosition(10);  // Assuming 10 is the jail position
            player->setInJail(true);
        });
        actions.emplace_back([](Player* player) {
            std::cout << "You win 200M$!" << std::endl;
            player->addMoney(200);
        });
        actions.emplace_back([](Player* player) {
            std::cout << "Pay a 100M$ tax." << std::endl;
            player->removeMoney(100);
        });
        actions.emplace_back([](Player* player) {
            std::cout << "Receive a 250M$ bonus." << std::endl;
            player->addMoney(250);
        });
        actions.emplace_back([](Player* player) {
            // Nothing to do
        });
        actions.emplace_back([](Player* player) {
            std::cout << "Pay 250M$ in maintenance fees." << std::endl;
            player->removeMoney(250);
        });
        actions.emplace_back([](Player* player) {
            std::cout << "You win 200M$!" << std::endl;
            player->addMoney(200);
        });
        actions.emplace_back([](Player* player) {
            std::cout << "Donate 50M$ to charity." << std::endl;
            player->removeMoney(50);
        });
        actions.emplace_back([](Player* player) {
            std::cout << "Go to Free Parking." << std::endl;
            player->setPosition(20);  // Assuming 20 is Free Parking
        });
        actions.emplace_back([](Player* player) {
            std::cout << "You get a refund of 100M$!" << std::endl;
            player->addMoney(100);
        });
    }

    // Function to randomly choose and apply an action on a player
    void drawCard(Player* player) {
        // Initialize random number generator
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(0, actions.size() - 1);  // Random index between 0 and 15
        // Choose a random action
        int randomIndex = distrib(gen);
        std::cout << "Drawing a Chance card..." << std::endl;
        // Apply the chosen action to the player
        actions[randomIndex](player);
    }
};

#endif // CHANCECARD_HPP