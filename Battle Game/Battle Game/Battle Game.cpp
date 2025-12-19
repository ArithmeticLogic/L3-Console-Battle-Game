#include <iostream>  // For input/output operations like cin and cout
#include <string>    // For using the string class to handle and manipulate text
#include <cstdlib>   // For functions like rand() and srand() (random number generation)
#include <ctime>     // For functions related to time, such as time() (used for seeding the random number generator)
#include "Monster.h"  // Assuming this header defines the Monster class

using namespace std;

// Random Number Generator for monster selection
// Generates a random integer between a specified range (min to max).
int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;  // Generates random number between min and max (inclusive)
}

// Generates a random percentage/number (1 to 100).
int getRandomPercentage() {
    return rand() % 100 + 1;  // Random number between 1 and 100
}

// Converts a string to lowercase manually
void toLowerCase(string& s) {
    // Convert each character to lowercase using ASCII values
    for (char& c : s) {
        if (c >= 'A' && c <= 'Z') {
            c += 32;  // Convert uppercase character to lowercase by adding 32 to its ASCII value
        }
    }
}

// Player class inherits from Monster class (Encapsulation and Inheritance)
// Holds the player-specific properties, like the selected monster.
class Player : public Monster {  // Inheriting from Monster class (demonstrating Inheritance)
private:
    string playerMonster;  // Player's selected monster

public:
    // Setter for player's monster
    void setPlayerMonster(string name) {
        playerMonster = name;  // Set the player's monster name
    }

    // Getter for player's monster
    string getPlayerMonster() {
        return playerMonster;  // Return the name of the player's monster
    }
};

// Declared Monsters (these are predefined instances of the Monster class)
// These objects represent different monsters in the game.
Monster Igris(100, "Igris", "Fire", "Volcano", 1, 1);  // Example monster
Monster Aqua(100, "Aqua", "Water", "Tsunami", 1, 1);   // Another example monster
Monster Goblin(1000, "Goblin", "Dark", "Stab", 100, 100);  // Example monster
Monster Slime(1000, "Slime", "Goo", "Smash", 100, 100);   // Example monster
Monster ElderBlackDragonGod(9999, "Elder Black Dragon God", "Holy", "Obliterate", 9999, 9999); // Ultimate monster

// Area class inherits from Player
// Handles the player's journey between different areas (OpenWorld, Base)
class Area : public Player {  // Inheriting from Player class (demonstrating Inheritance)
private:
    string areaType;  // Type of area selected (OpenWorld or Base)

public:
    Area() {}  // Default constructor

    Monster* selectedMonster;  // Pointer to selected monster during gameplay
    int scoreAmount = 0;  // Player's score

    // Method to choose an area (OpenWorld or Base)
    void chooseAnArea() {
        cout << "\nScore: " + to_string(scoreAmount) + "\n";  // Display the player's score
        cout << "Choose an area, OpenWorld | Base\n";  // Prompt user for area choice
        cin >> areaType;  // Get the area input from the user
        toLowerCase(areaType);  // Convert input to lowercase for consistency

        try {
            // Check areaType and call respective method
            if (areaType == "openworld") {
                openWorld();  // Enter the open world (combat area)
            }
            else if (areaType == "base") {
                base();  // Enter the base (monster selection area)
            }
            else {
                cout << "Invalid area\n";  // Invalid area type input
                return chooseAnArea();  // Prompt user again
            }
        }
        catch (...) {
            cout << "Error: During area selection";  // Error handling for invalid area selection
        }
    }

    // Overriding monsterAttack to use the specific monster's attack move
    // Overriding: Modifying the base class method to provide specific behavior for each derived class object
    void monsterAttack() override {
        cout << selectedMonster->getMonster() << " uses " << selectedMonster->getAttack() << "\n";  // Show the monster's attack
    }

    // OpenWorld area method where the player faces random monsters
    void openWorld() {
        short attackEnemy;
        int randomMonsterIndex = getRandom(1, 2);  // Generate a random number between 1 and 2 to select a monster

        selectedMonster = &Goblin;  // Default monster if no random selection occurs

        // Randomly select a monster based on the random number
        switch (randomMonsterIndex) {
        case 1:
            selectedMonster = &Goblin;  // Select Goblin as the monster
            break;
        case 2:
            selectedMonster = &Slime;  // Select Slime as the monster
            break;
        }

        // Display the selected monster
        cout << "Player is in Open World\n";
        cout << "A " << selectedMonster->getMonster() << " Has Appeared\n";
        cout << "Do you wish to attack?, 0 (Yes) | 1 (No)\n";
        cin >> attackEnemy;  // Ask the player if they want to attack

        try {
            int percentage = getRandomPercentage();  // Random percentage for attack outcomes

            switch (attackEnemy) {
            case 0:
                // 25% chance for the enemy to be the dragon
                getRandomPercentage();  // Generate another random percentage for attack chance

                if (percentage <= 25) {
                    selectedMonster = &ElderBlackDragonGod;  // Select ElderBlackDragonGod as the enemy
                    cout << "Enemy was actually level 99999 " << selectedMonster->getMonster() << "\n";
                    cout << "Player attacks " << selectedMonster->getMonster() << "\n";
                    getRandomPercentage();  // Another random percentage for dodge chance
                    if (percentage == 1) {
                        cout << "Player dodged " << selectedMonster->getMonster() << "\n!!!Victory!!!\n";
                        return;  // Victory, player dodges the attack
                    }
                    else if (percentage > 1) {
                        monsterAttack();  // Calling overridden method to show the monster's attack
                        cout << selectedMonster->getMonster() << " ate the player\n";
                        cout << "Player Died to " << selectedMonster->getMonster() << "\n";  // Player died
                        return;
                    }
                }

                // 75% chance for the enemy to be normal (not the dragon)
                else if (percentage > 25) {
                    cout << "Player attacks " << selectedMonster->getMonster() << "\n";
                    monsterAttack();  // Calling overridden method to show the monster's attack
                    getRandomPercentage();  // Generate another random percentage for attack results
                    // 25% chance for player to die from monster
                    if (percentage <= 25) {
                        cout << "Player Died to " << selectedMonster->getMonster();
                        return;  // Player died
                    }
                    // 75% chance for player to kill the monster
                    else if (percentage > 25) {
                        cout << "Player Successfully Attacks " << selectedMonster->getMonster() << " and it Die\n";
                        scoreAmount = scoreAmount + 100;  // Increase score by 100
                        return chooseAnArea();  // Allow player to choose another area
                    }
                }

            case 1: {
                cout << "You ran away\n";  // If player chooses to run away
                return chooseAnArea();  // Allow player to choose another area
            }
            }
        }
        catch (...) {
            cout << "Error: During attacking enemy";  // Error handling for attack logic
        }
    }

    // Base area method where the player selects a monster to use
    void base() {
        string monsterChoice;
        cout << "Player is at Base\n";
        cout << "Choose a Monster: Igris, Aqua, No\n";  // Prompt player for monster choice
        cin >> monsterChoice;  // Get monster choice input
        toLowerCase(monsterChoice);  // Convert to lowercase for consistency

        // Choosing a monster based on player input
        try {
            if (monsterChoice == "igris") {
                setPlayerMonster("Igris");  // Set player monster to Igris
            }
            else if (monsterChoice == "aqua") {
                setPlayerMonster("Aqua");  // Set player monster to Aqua
            }
            else if (monsterChoice == "no") {
                cout << "No Monster Chosen\n";  // If no monster is chosen
            }
            else {
                cout << "Invalid monster\n";  // If invalid input
                return base();  // Prompt player again
            }
        }
        catch (...) {
            cout << "Error: During choosing monster";  // Error handling for monster selection
        }

        cout << "You currently have " << getPlayerMonster() << "!\n";  // Display chosen monster
        return chooseAnArea();  // Allow player to choose another area
    }
};

// Main function where the game begins
int main() {
    srand(time(0));  // Seed the random number generator with the current time

    Area area;  // Create an instance of the Area class (object instantiation)
    area.chooseAnArea();  // Start the area selection process
}