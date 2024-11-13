/*

///////////////////////////////////////////////////////////////////////////////
inheritance
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


//below is client program code

#include <iostream>
#include <ctime> //Enables use of time() function for random number seed
#include <string> 
#include "Creature.h"
#include "Human.h"
#include "Elf.h"
#include "Demon.h"
#include "Cyberdemon.h"
#include "Balrog.h"
using namespace std;
using namespace cs_creature;


const int NUM_CREATURES = 4;
const int ELF_DEFAULT_STRENGTH = 24;
const int BALROG_DEFAULT_STRENGTH = 10;
const int HUMAN_DEFAULT_STRENGTH = 100;
const int CYBERDEMON_DEFAULT_STRENGTH = 50;
const int DEFAULT_HITPOINTS = 50;

void battle(Creature& Creature1, Creature& Creature2);


//In this main(), every Creature has a battle with every other Creature. To do 
//this, first declare four objects, one each of type Elf, Balrog, Human, and
//Cyberdemon.Then declare an array of type Creature* with 4 elements, and make
//each array element point to one of the four objects. (The array elements need
//to be pointers - to - Creatures rather than simply Creatures because Creature
//is an abstract class.) Then use nested for loops to call battle() with every
//possible combination of Creatures.
int main()
{
	//srand(static_cast(time(nullptr)));
	Elf elf(ELF_DEFAULT_STRENGTH, DEFAULT_HITPOINTS);
	Balrog balrog(BALROG_DEFAULT_STRENGTH, DEFAULT_HITPOINTS);
	Human human(HUMAN_DEFAULT_STRENGTH, DEFAULT_HITPOINTS);
	Cyberdemon cyberdemon(CYBERDEMON_DEFAULT_STRENGTH, DEFAULT_HITPOINTS);
	Creature* creatures[] = { &balrog, &elf, &cyberdemon, &human };
	for (int i = 0; i < NUM_CREATURES; i++) {
		for (int j = i + 1; j < NUM_CREATURES; j++) {
			battle(*creatures[i], *creatures[j]);
		}
	}
}









//POST: void function, called from main() to conduct and report fighting results.
//(Note, the parameters are pass-by-reference because the Creature class is an
//abstract class, so objects of type "Creature" cannot be declared.) The function
//calculates the damage done by Creature1, subtract that amount from Creature2's
//hitpoints, and vice versa. it means that the actual hitpoints data member of the
//Creature2 object will be modified. Also note that this means that both attacks
//are happening simultaneously; that is, if Creature2 dies because of Creature1's 
//attack, Creature2 still gets a chance to attack back.) At the end of each round,
//the function prints the total hitpoints remaining for each Creature. If, at the
//end of a round, both Creatures end up with 0 or fewer hitpoints, then the battle
//results in a tie. Otherwise, at the end of a round, if one Creature has positive
//hitpoints but the other does not, the Creature with positive hitpoints is the
//winner.The function loops until the battle is over. After the battle is over, reset
//the creatures to their values back (to get refreshed and ready for next battle)
void battle(Creature& Creature1, Creature& Creature2)
{
	int hitPtsCreature1 = Creature1.getHitpoints();
	int hitPtsCreature2 = Creature2.getHitpoints();
	int strengthCreature1 = Creature1.getStrength();
	int strengthCreature2 = Creature2.getStrength();
	int remainPtsCreature1;
	int remainPtsCreature2;


	cout << endl;
	cout << "*****  Battle between the " << Creature1.getSpecies();
	cout << " and the " << Creature2.getSpecies() << "!!  *****" << endl;
	cout << endl;

	

	do
	{
		remainPtsCreature2 = Creature2.getHitpoints() - Creature1.getDamage();
		remainPtsCreature1 = Creature1.getHitpoints() - Creature2.getDamage();

		cout << "The " << Creature2.getSpecies() << " has ";
		cout << remainPtsCreature2 << " hit points." << endl;
		cout << "The " << Creature1.getSpecies() << " has ";
		cout << remainPtsCreature1 << " hit points." << endl;
		cout << endl;

		Creature1.setHitpoints(remainPtsCreature1);
		Creature2.setHitpoints(remainPtsCreature2);

	} while (remainPtsCreature1 > 0 && remainPtsCreature2 > 0);



	if (remainPtsCreature2 <= 0 && remainPtsCreature1 <= 0)
	{
		cout << "The match is a tie!" << endl << endl;
	}
	else if (remainPtsCreature2 > 0 && remainPtsCreature1 <= 0)
	{
		cout << "The " << Creature2.getSpecies() << " wins!" << endl << endl;
	}
	else if (remainPtsCreature2 <= 0 && remainPtsCreature1 > 0)
	{
		cout << "The " << Creature1.getSpecies() << " wins!" << endl << endl;
	}


	Creature1.setHitpoints(hitPtsCreature1);
	Creature2.setHitpoints(hitPtsCreature2);
	Creature1.setStrength(strengthCreature1);
	Creature2.setStrength(strengthCreature2);
}