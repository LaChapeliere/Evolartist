/**
 * Author: LaChapeliere
 * Copyright: GNU General Public License v3.0
 * Created on: 27-08-2017
 * Last modified on: 08-09-2017
 */


#ifndef CREATURE_H
#define CREATURE_H

#include <time.h>
#include <pair>

//Class for the creatures
class Creature
{
private:
	/**
	 * Identifier of the creature
	 */
	const int m_id;

	/**
	 * Vision capacity of the creature
	 */
	const int m_visionCap;

	/**
	 * Maximum range of perception
	 */
	const int m_maxPercepCap;

	/**
	 * Movement capacity of the creature
	 */
	const int m_moveCap;

	/**
	 * Horizontal coordinate of the creature in the world grid
	 */
	int m_x;

	/**
	 * Vertical coordinate of the creature in the world grid
	 */
	int m_y;

	/**
	 * Health of the creature
	 */
	int m_health;

	/**
	 * Hunger of the creature
	 */
	int m_hunger;

public:
	/**
 	 * Creature constructor with specified coordinates
	 * @param id Creature id
 	 * @param x Horizontal coordinate
	 * @param y Vertical coordinate
 	 * @return A new Creature object at the specified location
 	 */
	Creature(const int id, const int x, const int y);

	/**
 	 * Creature constructor at random location
	 * @param id Creature id
 	 * @return A new Creature object
 	 */
	Creature(const int id);

	/**
	 * Identifier accessor
	 * @return m_id
	 */
	int getId();

	/**
	 * Vision capacity accessor
	 * @return m_visionCap
	 */
	int getVisionCap();

	/**
	 * Coordinates accessor
	 * @return The pair of horizontal and vertical coordinates
	 */
	std::pair<int, int> getCoord();

	/**
	 * Check whether the creature should still be alive
	 * @return False if the creature's health is negative
	 */
	bool isAlive();

	
	/**
	 * Decrease health according to hunger
	 */
	void hungerImpactHealth();

	/**
	 * Feed creature
	 * @param food The feeding power of the food
	 */
	void feed(const int food);

	/**
	 * Move the creature towards the visible spot with highest feeding power
	 * @return The pair of new horizontal and vertical coordinates
	 */
	std::pair<int, int> move();
    	
};

#endif