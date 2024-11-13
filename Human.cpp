/*
///////////////////////////////////////////////////////////////////////////////
This is the implementation file for Project 23.1 Assignment 13 2P Inheritance II
file name: Human.cpp
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
#include "Human.h"
#include "Creature.h"
using namespace std;


namespace cs_creature
{
	//Default constructor, constructing a Human object with no parameter
	//PRE: no Human object, no values assigned to Human object. POST: creates
	//Human object, call parent class (or superclass or base class) Creature's
	//parameterized constructor to set parent class (or superclass or base class's)
	//data members with assigned default values. (Initializes to Human, 10 strength,
	//10 hitpoints in parent class Creature)
	Human::Human()
	{
	}








	//parameterized constructor, constructing a Human object with two parameters
	//PRE: no Human object, no values assigned to Human object. POST: creates
	//Human object, call parent class (or superclass or base class) Creature's
	//parameterized constructor to set parent class (or superclass or base class's)
	//data members int strength and int hitpoints with assigned new values
	Human::Human(int newStrength, int newHitpoints) 
	
	: Creature(newStrength, newHitpoints)//initializer list

	{
	}
 

	 




	//POST: return the type "human" as appropriate for Human.
	string Human::getSpecies() const
	{
		return "human";
	}
}
