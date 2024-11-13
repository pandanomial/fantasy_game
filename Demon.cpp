/*
///////////////////////////////////////////////////////////////////////////////
This is the implementation file for Project 23.1 Assignment 13 2P Inheritance II
file name: Demon.cpp
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
#include "Demon.h"
#include "Creature.h"
using namespace std;


namespace cs_creature
{
	//Default constructor, constructing a Demon object with no parameter
	//PRE: no Demon object, no values assigned to Human object. POST: creates
	//Demon object, call parent class (or superclass or base class) Creature's
	//parameterized constructor to set parent class (or superclass or base class)'s
	//data members with assigned default values. (10 strength, 10 hitpoints in
	//Demon's parent class Creature) 
	Demon::Demon()
	{
	}









	//parameterized constructor, constructing a Demon object with two parameters
	//PRE: no Demon object, no values assigned to Demon object. POST: creates
	//Demon object, call parent class or superclass or base class Creature's
	//parameterized constructor to set parent class or superclass or base class's
	//data members int strength and int hitpoints with assigned new values
	Demon::Demon(int newStrength, int newHitpoints)

	: Creature(newStrength, newHitpoints)//initializer list

	{
	}










	//in Demon class damage only computes the damage appropriate for this specific
	//Demon class. The total damage is calculated by combining that damage with the
	//results when getDamage() is called on the parent class Creature since Demon 
	//class derived from Creature class. So this function invoks getDamage() for a
	//Creature object, which computes the basic damage that all creatures inflict.
	//then, there will be some additional couts and calculations after the initial
	//damage inflicted is reported. The logic or equation is given as below. 
	//POST: return total damage of Demon object can have
	int Demon::getDamage() const
	{
		double damage;

		//(1) call the Creature class's getDamage() to determine damage inflicted
		damage = Creature::getDamage();


		//(2)print the words "attacks for ?? points!",
		//cout << " attacks for " << damage << " points!" << endl;


		//(3) determine whether a demonic attack occurs, and if so, 
		//(4) print the "demonic attack" message.
		//Demons can inflict bonus damage of DEMONIC_BONUS_DAMAGE with a
		//DEMONIC_ATTACK_PROBABILITY chance
		if (rand() % 100 * 0.01 < DEMONIC_ATTACK_PROBABILITY)
		{
			damage = damage + DEMONIC_BONUS_DAMAGE;

			cout << "Demonic attack inflicts " << DEMONIC_BONUS_DAMAGE;
			cout << " additional damage points!" << endl;
		}
		
		return static_cast<int>(damage);
	}









	//POST: return the type "demon" as appropriate for Demon.
	string Demon::getSpecies() const
	{
		return "demon";
	}
}
