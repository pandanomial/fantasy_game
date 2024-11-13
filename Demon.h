/*
///////////////////////////////////////////////////////////////////////////////
This is the header file for Project 23.1 Assignment 13 2P  Inheritance Part Two
file name: Demon.h
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



#ifndef DEMON_H
#define DEMON_H
#include <iostream>
#include <string>
#include "Creature.h"


namespace cs_creature
{
	class Demon: public Creature //Demon class is derived from Creature class
	{
		public:
			static constexpr double DEMONIC_ATTACK_PROBABILITY = 0.25;
			static const int DEMONIC_BONUS_DAMAGE = 50;
			Demon();
			Demon(int newStrength, int newHitpoints);
			std::string getSpecies() const; // returns the type of the specie
			virtual int getDamage() const;
	};
}

#endif
