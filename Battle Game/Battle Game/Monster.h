#pragma once  // Ensures the header file is included only once during compilation to prevent redefinition errors
#include <string>  // Includes the string class to handle and manipulate text strings

using namespace std;

// Monster class defines the attributes and behavior of a monster in the game
class Monster {
    // Access modifier
private:
    string monster, attribute, attack;  // Strings to hold the monster's name, its attribute (like Fire, Water), and the attack name
    int attackDamage, defence, health;  // Integer values for the monster's attack damage, defense, and health points

    // Access modifier
public:

    // Default constructor (Overloading)
    Monster() {}  // Default constructor that does nothing (used when creating a Monster object without passing any parameters)

    // Parameterized constructor (Overloading)
    // This constructor initializes a monster with its specific attributes: health, name, attribute, attack, attack damage, and defense.
    Monster(int healthC, string monsterC, string attributeC, string attackC, int attackDamageC, int defenceC) : health(healthC), monster(monsterC), attribute(attributeC), attack(attackC), attackDamage(attackDamageC), defence(defenceC) {}

    // Overriding (Method)
    // A virtual method that will be overridden in derived classes (such as Player or Area) to provide specific behavior for monster attacks.
    virtual void monsterAttack();  // This method is virtual, meaning subclasses can modify it to provide specific attack behavior.

    // Getter for health
    // This method is used to retrieve the health of the monster.
    int getHealth() const;

    // Getter for monster name
    // This method retrieves the name of the monster.
    string getMonster() const;

    // Getter for attack type
    // This method retrieves the type of attack the monster has (e.g., "Smash", "Obliterate").
    string getAttack() const;

}; // End of Monster class definition