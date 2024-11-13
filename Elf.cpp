/*
///////////////////////////////////////////////////////////////////////////////
This is the implementation file for Project 23.1 Assignment 13 2P Inheritance II
file name: Elf.cpp
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
#include "Elf.h"
#include "Creature.h"
using namespace std;


namespace cs_creature
{
	//Default constructor, constructing a Elf object with no parameter
	//PRE: no Elf object, no values assigned to Elf object. POST: creates
	//Elf object, call parent class (or superclass or base class) Creature's
	//parameterized constructor to set parent class (or superclass or base class)'s
	//data members with assigned default values. (Initializes to Elf, 10 strength,
	//10 hitpoints in parent class Creature)
	Elf::Elf()
	{
	}









	//parameterized constructor, constructing a Elf object with two parameters
	//PRE: no Elf object, no values assigned to Elf object. POST: creates
	//Elf object, call parent class (or superclass or base class) Creature's
	//parameterized constructor to set parent class (or superclass or base class)'s
	//data members int strength and int hitpoints with assigned new values
	Elf::Elf(int newStrength, int newHitpoints)

	: Creature(newStrength, newHitpoints)//initializer list

	{
	}

 


	




	//in Elf class damage only computes the damage appropriate for this specific
	//Elf class. The total damage is calculated by combining that damage with the
	//results when getDamage() is called on the parent class Creature since Elf 
	//class derived from Creature class. So this function invoks getDamage() for a
	//Creature object, which computes the basic damage that all creatures inflict.
	//then, it'll do some additional couts and calculations after the initial
	//damage inflicted is reported. The logic or equation is given as below. 
	//POST: return total damage of Elf object can have
	int Elf::getDamage() const
	{
		double damage;

		//l (1) call the Creature class's getDamage() to determine the damage inflicted
		damage = Creature::getDamage();

		//(2) print the message reporting the damage inflicted. 
		//cout << "The elf attacks for " << damage << " points!" << endl;

		//(3) couts and calculations after the initial damage inflicted is reported
		//Elves inflict multiplied magical damage with a MAGICAL_ATTACK_PROBABILITY chance
		if (rand() % 100 * 0.01 < MAGICAL_ATTACK_PROBABILITY) 
		{ 
			cout << "Magical attack inflicts " << damage;
			cout << " additional damage points!" << endl;
			damage *= MAGICAL_ATTACK_MULTIPLIER;
		}

		return static_cast<int>(damage);
	}









	//POST: return the type "elf" as appropriate for Elf.
	string Elf::getSpecies() const
	{
		return "elf";
	}
}
