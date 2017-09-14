/**
 * Author: LaChapeliere
 * Copyright: GNU General Public License v3.0
 * Created on: 08-09-2017
 * Last modified on: 08-09-2017
 */


#ifndef WORLD_H
#define WORLD_H

#include "Spot.h"
#include "Creature.h"


//Class for the world grid
class World
{
private:
	/**
	 * Size of the world grid
	 */
	const int m_size;

	/**
	 * Time since initialization, in simulation steps
	 */
	int m_age;

	/**
	 * Time since last manual modification, in simulation steps
	 */
	int m_incubationTime;

	/**
	 * Flattened matrix of Spot objects, represent the grid
	 */
	const std::vector<Spot> m_grid;

	/**
	 * Identifier of most recent Creature object
	 */
	int m_lastCreatureId;

	/**
	 * List of Creature objects in the world
	 */
	std::vector<Creature> m_creatures;

public:
	/**
 	 * World constructor
	 * @param size The size of the square grid
 	 * @return A new World object with the specified size of grid
 	 */
	World(const int size);

	
	/**
	 * Accessor of age of the world
	 * @return m_age
	 */
	const int getAge() const;

	/**
	 * Accessor of incubation time of the world
	 * @return m_incubationTime
	 */
	const int getIncubTime() const;


	/**
	 * Add a Creature to the world, in a random position
	 */
	void addCreature();

	/**
	 * Add a Creature to the world, in a specified position
	 */
	void addCreature(const int x, const int y);

	/**
	 * Delete a Creature from the world, according to its identifier
	 */
	void removeCreature(const int creatureId);

	/**
	 * Evaluate environment for each Creature object
	 */
	void evalEnvCreatures();

	/**
	 * Move all Creature objects
	 */
	void moveCreatures();

	/**
	 * Have Creatures interact in each Spot
	 */
	void interactBtwCreatures();
	
	/**
	 * Have Creatures interact with their environment
	 */
	void interactCreaturesEnv();

	/**
	 * Survival and aging step
	 */
	void resolveTurn();

};

#endif