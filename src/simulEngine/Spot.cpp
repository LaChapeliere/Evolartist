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

const int Spot::getFood() const {
	return m_food;
}

const int Spot::getNbCreatures() const {
	return m_creatures.size();
}

Creature const* Spot::getCreatureFromIndex(const int id) const {
	return m_creatures[id];
}

void Spot::growFood() {
	m_food++;
}

void Spot::feedCreatures() {
	const int nbCreatures = m_creatures.size();
	if (nbCreatures > 0) {
		int share = m_food / nbCreatures;
		//Each Creature present on the spot gets an equal share of the food
		for (int c = 0; c < nbCreatures; c++) {
			m_creatures[c]->feed(share);
			// The available vegetation is diminished from feeding
			m_food -= share;
		}
	}
}

void Spot::addCreature(Creature *const creaturePointer) {
	m_creatures.push_back(creaturePointer);
}

void Spot::removeCreature(const int id) {
	for (int c = 0; c < m_creatures.size(); c++) {
		if (m_creatures[c]->getId() == id) {
			m_creatures.erase(m_creatures.begin() + c);
			return;
		}
	}
	std::cout << "Trying to remove unexisting Creature from Spot" << ends;
}