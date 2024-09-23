#ifndef DICE_HPP
#define DICE_HPP

#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

class Dice {
public:
    int die_1;
    int die_2;
    int dice_roll;

    // Constructor: Initializes random seed and rolls the dice
    Dice() {
        // Seed for random number generation (should be done only once per program run)
        srand(static_cast<unsigned int>(time(0)));
        // Roll the dice for the first time
        roll();
    }

    // Roll the dice (generate new random values for both dice)
    void roll() {
        die_1 = rand() % 6 + 1;
        die_2 = rand() % 6 + 1;
        dice_roll = die_1 + die_2;
    }

    // Get the total dice roll
    int get_dice_roll() const { return dice_roll; }
    // Get the value of die 1
    int get_die_1() const { return die_1; }
    // Get the value of die 2
    int get_die_2() const { return die_2; }
};

#endif // DICE_HPP