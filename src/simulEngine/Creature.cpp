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

	m_maxPercepCap = m_visionCap;
}

Creature::Creature(const int id) {
	//Generate random coordinates in world space
	const int x = rand() % 1000;
	const int y = rand() % 1000;

	return Creature(id, x, y);
}

int Creature::getId() {
	return m_id;
}

int Creature::getVisionCap() {
	return m_visionCap;
}

std::pair<int, int> Creature::getCoord() {
	return std::pair<int, int> (m_x, m_y);
}

bool Creature::isAlive() {
	return (m_health > 0);
}

void Creature::hungerImpactHealth() {
	//Hunger is always positive
	if (m_hunger >= 0) {
		m_health -= m_hunger;
	}
}

void Creature::feed(const int food) {
	//Feeding power must be positive
	if (food >= 0) {
		m_hunger -= food;
	}
}

std::pair<int, int> Creature::move() {
	//Dummy implementation, no move
	return getCoord();
}