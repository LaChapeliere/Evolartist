/**
 * Author: LaChapeliere
 * Copyright: GNU General Public License v3.0
 * Created on: 08-09-2017
 * Last modified on: 08-09-2017
 */

#include "Spot.h"

Spot::Spot(const int x, const int y) {
	m_x = x;
	m_y = y;
	m_food = rand() % 100;
	m_creatures = std::vector<Creature const*>();
}

const int Spot::food() const {
	return m_food;
}

const int nbCreatures() const {
	return m_creatures.size();
}

Creature const* Spot::creatureFromIndex(const int id) const {
	return m_creatures[id];
}

void Spot::growFood() {
	m_food++;
}