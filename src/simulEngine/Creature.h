/**
 * Author: LaChapeliere
 * Copyright: GNU General Public License v3.0
 * Created on: 27-08-2017
 * Last modified on: 08-09-2017
 */


#ifndef CREATURE_H
#define CREATURE_H

#include <time.h>
#include <utility>
#include "World.h"

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

	/**
	 * Flattened matrix of the perceived local environment, centered on current position
	 */
	int m_env;

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
	const int getId() const;

	/**
	 * Vision capacity accessor
	 * @return m_visionCap
	 */
	const int getVisionCap() const;

	/**
	 * Maximum perception capacity accessor
	 * @return m_maxPercepCap
	 */
	const int getmaxPercepCap() const;

	/**
	 * Coordinates accessor
	 * @return The pair of horizontal and vertical coordinates
	 */
	const std::pair<int, int> getCoord() const;

	/**
	 * Check whether the creature should still be alive
	 * @return False if the creature's health is negative
	 */
	const bool isAlive() const;

	
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
	 * Build local perception map
	 * @param A pointer to the World object
	 */
	void perceiveLocalEnv(World const* world);

	/**
	 * Move the creature towards the visible spot with highest feeding power
	 * @return The pair of new horizontal and vertical coordinates
	 */
	const std::pair<int, int> move();
    	
};

#endif