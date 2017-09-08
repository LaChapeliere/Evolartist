/**
 * Author: LaChapeliere
 * Copyright: GNU General Public License v3.0
 * Created on: 08-09-2017
 * Last modified on: 08-09-2017
 */


#ifndef WORLD_H
#define WORLD_H


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

public:
	/**
 	 * World constructor
	 * @param size The size of the square grid
 	 * @return A new World object with the specified size of grid
 	 */
	World(const int size);
    	
};

#endif