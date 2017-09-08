/**
 * Author: LaChapeliere
 * Copyright: GNU General Public License v3.0
 * Created on: 08-09-2017
 * Last modified on: 08-09-2017
 */


#ifndef SPOT_H
#define SPOT_H

#include <vector>

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
	int food();

	/**
	 * Give the number of creatures on the spot
	 * @return The length of m_creatures
	 */
	int nbCreatures();

	/**
	 * Give the pointer to a specific creature of the spot
	 * @param id Index of the desired creature in m_creatures
	 * @return The value of m_creatures[id]
	 */
	Creature* creatureFromIndex(const int id);


	/**
	 * Simulate vegetation growth
	 */
	void growFood();
};

#endif