/*
///////////////////////////////////////////////////////////////////////////////
This is the implementation file for Project 23.1 Assignment 13 2P Inheritance II
file name:	Balrog.cpp
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
#include "Balrog.h"
#include "Demon.h"
using namespace std;


namespace cs_creature
{
	//Default constructor, constructing a Balrog object with no parameter
	//PRE: no Balrog object, no values assigned to Balrog object. 
	//POST: creates Balrog object, call parent class (or superclass or base
	//class) Demon's parameterized constructor to set its own parent class (or
	//superclass or base ) (Balrog's grandparent) parameterized constructor, 
	//which is Creature's data members with assigned default values. Initializes
	//to Balrog object, (10 strength, 10 hitpoints in Balrog's grandparent Creature) 
	Balrog::Balrog()
	{
	}








	//parameterized constructor, constructing a Balrog object with two parameters.
	//PRE: no Balrog object, no values assigned to Balrog object.
	//POST: creates Balrog object, call parent class (or superclass or base class)
	//Demon's parameterized constructor to set parent class (or superclass or base)
	//class's parent class Creature (grandparent) class's parameterized constructor
	//which is Creature's data members with assigned default values. Initializes
	//to Balrog object, assign values to Balrog object
	Balrog::Balrog(int newStrength, int newHitpoints)

	: Demon(newStrength, newHitpoints)//initializer list

	{
	}








	//in Balrog class damage computes the damage appropriate for this specific
	//Balrog class. The total damage is calculated by combining that damage
	//with the results when getDamage() is called on the parent class Demon since
	//Balrog class derived from Demon class. So this function invoks getDamage()
	//for a Demon object, which computes the damage that Demon inflicts. Also, 
	//Demon's getDamage() invoks it's own parent class Creature's function getDamage()
	//for a Creature object, which computes the basic damage that all creatures
	//inflict. so, Balrog inherits from Demon, and Demon inherits from Creature.
	//So invoking getDamage() for a Balrog object invokes getDamage() for a Demon
	//object, which should invoke getDamage() for the Creature object, which will
	//compute the basic damage that all creatures inflict, followed by
	//the random 25 % damage that demons inflict, followed by the double damage
	//that balrogs inflict. POST: return total damage of Balrog object can have
	int Balrog::getDamage() const
	{
		double damage;

		//(1) print the words "The balrog"
		//cout << "The balrog";


		//(2) call the Demon class's getDamage() function to determine the damage
		damage = Demon::getDamage();


		//(3) calculate the damage inflicted by the balrog's second attack 
		//(which is a basic "Creature" attack), Don't call the Creature class's
		//getDamage() to calculate the damage inflicted by the second attack.
		//Instead use something like "damage2 = (rand() % strength) + 1;"
		//Balrogs are very fast, so they get to attack twice
		int damage2 = (rand() % Creature::getStrength()) + 1;


		//4)print those results. 
		cout << "Balrog speed attack inflicts " << damage2;
		cout << " additional damage points!" << endl;
		
		damage += damage2;

		return static_cast<int>(damage);
	}





	
	
	
	//POST: return the type "balrog" as appropriate
	string Balrog::getSpecies() const
	{
		return "balrog";
	}

}