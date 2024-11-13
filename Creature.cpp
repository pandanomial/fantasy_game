/*
///////////////////////////////////////////////////////////////////////////////
This is the implementation file for Project 23.1 Assignment 13 2P Inheritance II
file name: Creature.cpp
///////////////////////////////////////////////////////////////////////////////

Note: No documentation is required on this project. Suppose creating a fantasy
role-playing game. In this game we have four different types of creatures:
humans, cyberdemons, balrogs, and elves. One problem with the old implementation
is that it is unwieldy to add new Creatures. Rewrite the class to use inheritance,
which will eliminate the need for the variable "type". The Creature class should
be the base class. The classes Demon, Elf, and Human should be derived from
Creature. The classes Cyberdemon and Balrog should be derived from Demon.

the Demon class's getDamage() function can print the name of the species. No need
to repeat the cout statement "The <whatever> attacks for ?? points!" in every
class's getDamage() function. cout statement occurs just once, in the Creature
class's getDamage() function. Create a new client program. Make a function in the
client program that is called from main() and has the following prototype:
void battle(Creature &Creature1, Creature& Creature2);
(Note, the parameters are pass-by-reference because the Creature class is an
abstract class, so objects of type "Creature" cannot be declared.) The function
should calculate the damage done by Creature1, subtract that amount from Creature2's
hitpoints, and vice versa. ("subtract that amount from Creature2's hitpoints,
it means that the actual hitpoints data member of the Creature2 object will be
modified. Also note that this means that both attacks are happening simultaneously;
that is, if Creature2 dies because of Creature1's attack, Creature2 still gets a
chance to attack back.)
*/


#include <iostream>
#include <string> 
#include "Creature.h"
using namespace std;


namespace cs_creature
{
	//Default constructor, constructing a Creature object with no parameter,
	//Pre: no values assigned to private members strength and hitpoints
	//POST: creates Creature object, data members are assigned with default 
	//values initialize 10 strength, 10 hitpoints
	Creature::Creature()
	{
		strength = DEFAULT_STRENGTH;
		hitpoints = DEFAULT_HITPOINTS;
	}








	//This is a parameterized constructor (construction of a Creature object) 
	//takes two parameter, which are int. POST: assign values to private members
	Creature::Creature(int newStrength, int newHitpoints)
	{
		strength = newStrength;
		hitpoints = newHitpoints;
	}








	//this is mutator or setter function to set private member strength with a
	//new value. POST: sets private member strength with a new value
	void Creature::setStrength(int newStrength)
	{
		strength = newStrength;
	}








	//this is accessors or getter function to get private member strength's 
	//value. POST: Return private member strength with a value
	int Creature::getStrength() const
	{
		return strength;
	}







	
	//this is mutator or setter function to set private member hitpoints with a
	//new value. POST: sets private member hitpoints with a new value
	void Creature::setHitpoints(int newHitpoints)
	{
		hitpoints = newHitpoints;
	}








	//this is accessors or getter function to get private member hitpoints's 
	//value. POST: Return private member hitpoints with a value
	int Creature::getHitpoints() const
	{
		return hitpoints;
	}








	//All Creatures inflict damage which is a random number up to their strength
	//POST: returns the amount of damage the Creature inflicts in one round of combat
	//return an int representing the damage inflicted. no cout statements.
	int Creature::getDamage() const 
	{
		
		int damage;

		//All Creatures inflict damage which is a random number up to their strength
		damage = (rand() % strength) + 1;

		cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;

		return damage;
	}







	/*
	//POST: Return the type of the specie
	string Creature::getSpecies() const
	{
		return "Creature";
	}
	*/
}