#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Dice.hpp"

// Test that dice values are between 1 and 6 after initialization
TEST_CASE("Dice values should be between 1 and 6 after initialization") {
    Dice dice;
    CHECK(dice.get_die_1() >= 1);
    CHECK(dice.get_die_1() <= 6);
    CHECK(dice.get_die_2() >= 1);
    CHECK(dice.get_die_2() <= 6);
}

// Test that rolling the dice gives a sum between 2 and 12
TEST_CASE("Rolling the dice should return a sum between 2 and 12") {
    Dice dice;
    int sum = dice.roll();
    CHECK(sum >= 2);
    CHECK(sum <= 12);
}

// Test that rolling the dice updates die_1 or die_2 values
TEST_CASE("Rolling the dice should update the values of die_1 or die_2") {
    Dice dice;
    int old_die_1 = dice.get_die_1();
    int old_die_2 = dice.get_die_2();
    dice.roll();
    CHECK((dice.get_die_1() != old_die_1 || dice.get_die_2() != old_die_2));  // At least one die should change
}

// Test that the dice correctly identify a double when rolled
TEST_CASE("isDouble() should return true when both dice are the same") {
    Dice dice;
    // Force a double for testing
    dice.die_1 = 3;
    dice.die_2 = 3;
    CHECK(dice.isDouble() == true);  // Should return true since both dice are the same
}

// Test that isDouble() returns false when dice have different values
TEST_CASE("isDouble() should return false when dice values differ") {
    Dice dice;
    dice.die_1 = 2;
    dice.die_2 = 5;
    CHECK(dice.isDouble() == false);  // Should return false since dice have different values
}

// Test that initial roll after object creation generates valid dice values
TEST_CASE("Initial roll in constructor should generate valid dice values") {
    Dice dice;
    CHECK(dice.get_die_1() >= 1);
    CHECK(dice.get_die_1() <= 6);
    CHECK(dice.get_die_2() >= 1);
    CHECK(dice.get_die_2() <= 6);
}

// Test that both dice can generate all possible values (1 through 6)
TEST_CASE("Dice should be able to roll all values between 1 and 6") {
    Dice dice;
    bool found_values_die_1[7] = {false};
    bool found_values_die_2[7] = {false};

    // Roll the dice multiple times and track which values appear for die_1 and die_2
    for (int i = 0; i < 100; ++i) {
        dice.roll();
        found_values_die_1[dice.get_die_1()] = true;
        found_values_die_2[dice.get_die_2()] = true;
    }

    // Check if both dice produced all values from 1 to 6 at least once
    for (int i = 1; i <= 6; ++i) {
        CHECK(found_values_die_1[i] == true);
        CHECK(found_values_die_2[i] == true);
    }
}

// Test that both dice can generate the same value (doubles)
TEST_CASE("Dice should be able to roll doubles") {
    Dice dice;
    bool rolled_double = false;

    // Roll the dice multiple times to check if we get any doubles
    for (int i = 0; i < 100; ++i) {
        dice.roll();
        if (dice.get_die_1() == dice.get_die_2()) {
            rolled_double = true;
            break;
        }
    }

    CHECK(rolled_double);  // Test passes if at least one double is rolled
}