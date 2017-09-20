/**
 * Author: LaChapeliere
 * Copyright: GNU General Public License v3.0
 * Created on: 08-09-2017
 * Last modified on: 08-09-2017
 */


#ifndef SPOT_H
#define SPOT_H

#include <vector>
#include <iostream>
#include "Creature.h"

//Class for the spots in the grid
class Spot
{
private:
	/**
	 * Horizontal coordinate of the position in the world grid
	 */
	const int m_x;

	/**
	 * Vertical coordinate of the position in the world grid
	 */
	const int m_y;

	/**
	 * Feeding power of the spot
	 */
	int m_food;

	/**
	 * List of Creatures (pointers) on this spot
	 */
	std::vector<Creature*> m_creatures;

public:
	/**
 	 * Spot constructor
 	 * @param x Horizontal coordinate
	 * @param y Vertical coordinate
 	 * @return A new Spot object with the specified location
 	 */
	Spot(const int x, const int y);


	/**
	 * Accessor of feeding power
	 * @return m_food
	 */
	const int getFood() const;

	/**
	 * Give the number of creatures on the spot
	 * @return The length of m_creatures
	 */
	const int getNbCreatures() const;

	/**
	 * Give the pointer to a specific creature of the spot
	 * @param id Index of the desired creature in m_creatures
	 * @return The value of m_creatures[id]
	 */
	Creature const* getCreatureFromIndex(const int id) const;


	/**
	 * Simulate vegetation growth
	 */
	void growFood();

	/**
	 * Simulate feeding from vegetation
	 */
	void feedCreatures();

	/**
	 * Add a creature to the spot
	 * @param creaturePointer The pointer to the added Creature
	 */
	void addCreature(Creature *const creaturePointer);

	/**
	 * Remove a specific creature from the spot
	 * @param id Identifier of the creature to remove from m_creatures
	 */
	void removeCreature(const int id);
	
};

#endif