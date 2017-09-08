/**
 * Author: LaChapeliere
 * Copyright: GNU General Public License v3.0
 * Created on: 27-08-2017
 * Last modified on: 27-08-2017
 */

#include "Creature.h"

Creature::Creature(const int id, const int x, const int y) {
	//Initialise attributes
	m_id = id;
	m_visionCap = 3;
	m_moveCap = 1;
	m_x = x;
	m_y = y;
	m_health = 100;
	m_hunger = 0;
}

Creature::Creature(const int id) {
	//Generate random coordinates in world space
	const int x = rand() % 1000;
	const int y = rand() % 1000;

	return Creature(id, x, y);
}