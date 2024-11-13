# fantasy_game
A fantasy role-playing game (inheritance): there are four different types of creatures: humans, cyberdemons, balrogs, and elves. 

The Creature class is the base class. The classes Demon, Elf, and Human are derived from Creature.

The classes Cyberdemon and Balrog are derived from Demon and Demon inherits from Creature.

Make the Creature class's getSpecies() function a pure virtual function, so that every class that is derived from the Creature class will be required to implement a getSpecies() function.

Make getDamage() a virtual function so that in "battleArena" function, you can say "Creature1.getDamage()" and the damage will automatically be calculated for the
correct Creature. The parameters for "battleArena" will be of type "Creature" and they will need to be pass-by-reference.
