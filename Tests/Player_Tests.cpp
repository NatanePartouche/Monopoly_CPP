#include "doctest.h"
#include "../Player/Player.hpp"
#include "../Properties/Street.hpp"
#include "../Properties/RailRoad.hpp"
#include "../Properties/Utility.hpp"

// Test constructor with name and initial values
TEST_CASE("Player constructor with name initializes with correct values") {
    Player player("John");  // Création d'un joueur avec le nom "John"
    CHECK(player.getName() == "John");  // Vérifie que le nom est correctement initialisé
    CHECK(player.getBalance() == 1500);  // Vérifie que le solde initial est 1500
    CHECK(player.getPosition() == 0);  // Vérifie que la position initiale est 0
    CHECK(player.isInJail() == false);  // Vérifie que le joueur n'est pas en prison au début
    CHECK(player.getJailTurns() == 0);  // Vérifie que le joueur a 0 tours de prison
    CHECK(player.getBoardTurns() == 0);  // Vérifie que le joueur n'a pris aucun tour au départ
}

// Test modification du solde
TEST_CASE("Player balance can be modified correctly") {
    Player player("Alice");

    player.addMoney(500);  // Ajoute 500 au solde du joueur
    CHECK(player.getBalance() == 2000);  // Vérifie que le solde est 2000

    bool result = player.removeMoney(300);  // Enlève 300 du solde du joueur
    CHECK(result == true);  // Vérifie que l'opération a réussi
    CHECK(player.getBalance() == 1700);  // Vérifie que le solde est maintenant 1700

    result = player.removeMoney(1800);  // Essaie de retirer plus que le solde
    CHECK(player.getBalance() == -100);  // Le solde ne doit pas changer
}

// Test modification de la position du joueur sur le plateau
TEST_CASE("Player position can be set and retrieved") {
    Player player("Alice");

    player.setPosition(10);  // Modifie la position du joueur
    CHECK(player.getPosition() == 10);  // Vérifie que la position a été modifiée correctement

    player.setPosition(20);  // Change la position à nouveau
    CHECK(player.getPosition() == 20);  // Vérifie que la position est 20
}

// Test gestion du statut en prison
TEST_CASE("Player jail status can be set and retrieved") {
    Player player("Bob");

    CHECK(player.isInJail() == false);  // Vérifie que le joueur n'est pas en prison au début
    player.setInJail(true);  // Place le joueur en prison
    CHECK(player.isInJail() == true);  // Vérifie que le joueur est en prison
    player.setJailTurns(2);  // Définit le nombre de tours en prison
    CHECK(player.getJailTurns() == 2);  // Vérifie que les tours en prison sont corrects
}

// Test carte "Sortie de prison"
TEST_CASE("Player can manage 'Get Out of Jail Free' card status") {
    Player player("Charlie");

    CHECK(player.getCard_out_of_jail() == false);  // Le joueur n'a pas de carte au départ
    player.setCard_out_of_jail(true);  // Donne la carte au joueur
    CHECK(player.getCard_out_of_jail() == true);  // Vérifie que le joueur possède la carte
    player.setCard_out_of_jail(false);  // Retire la carte
    CHECK(player.getCard_out_of_jail() == false);  // Vérifie que la carte a été retirée
}

// Test ajout de propriétés de type Street
TEST_CASE("Player can own and retrieve street properties") {
    Player player("Eve");
    Street street1, street2;

    player.addStreetProperty(&street1);  // Ajoute la première propriété
    player.addStreetProperty(&street2);  // Ajoute la deuxième propriété
    CHECK(player.getStreetProperties().size() == 2);  // Vérifie que le joueur possède 2 propriétés
}

// Test ajout de propriétés de type RailRoad et Utility
TEST_CASE("Player can own and retrieve RailRoad and Utility properties") {
    Player player("David");
    RailRoad railroad1("Railroad 1");  // Ajoute un nom lors de la création de la propriété RailRoad
    Utility utility1("Utility 1");  // Ajoute un nom lors de la création de la propriété Utility

    player.addRailroadProperty(&railroad1);  // Ajoute une propriété RailRoad
    player.addUtilityProperty(&utility1);  // Ajoute une propriété Utility
    CHECK(player.getRailroadProperties().size() == 1);  // Vérifie que le joueur possède 1 RailRoad
    CHECK(player.getUtilityProperties().size() == 1);  // Vérifie que le joueur possède 1 Utility
}