#include "Monster.h"  // Including the header file for the Monster class
#include <string>      // For using the string class
#include <iostream>    // For using input/output functionality

using namespace std;

// Overriding the monsterAttack method in the Monster class
// This method is used to define the behavior when a monster attacks.
// In this case, it prints a generic message stating that the monster attacks.
void Monster::monsterAttack() {
    cout << "Monster attacks!\n";  // Output message indicating the monster is attacking
}

// Getter method for health
// This function returns the current health of the monster.
// It is marked as 'const' to ensure it doesn't modify any member variables.
int Monster::getHealth() const {
    return health;  // Returns the monster's health attribute
}

// Getter method for monster name
// This function returns the name of the monster as a string.
// It is marked as 'const' to ensure the original object is not modified.
string Monster::getMonster() const {
    return monster;  // Returns the name of the monster
}

// Getter method for attack
// This function returns the type of attack the monster uses as a string.
// It is marked as 'const' to ensure it doesn't alter any member data.
string Monster::getAttack() const {
    return attack;  // Returns the attack type of the monster
}