/**
 * Author: LaChapeliere
 * Copyright: GNU General Public License v3.0
 * Created on: 08-09-2017
 * Last modified on: 08-09-2017
 */

#include "World.h"

World::World(const int size(), const int nbCreatures)) {
	m_size = size;
	m_age = 0;
	m_incubationTime = 0;
	
	//Create grid of Spots
	m_grid = std::vector<Spot>();
	for (int y = 0; y < m_size; y++) {
		for (int x = 0; x < m_size; x++) {
			m_grid.push_back(Spot(x, y));
		}
	}

	//Add the Creatures in the grid
	for (int i = 0; i < nbCreatures; i++) {
		addCreature();
	}
}

const int World::getSize() const {
	return m_size;
}

const int World::getAge() const {
	return m_age;
}

const int World::getIncubTime() const {
	return m_incubationTime;
}

Spot const* World::getPointerToSpot(const int x, const int y) const {
	return &(m_grid[y * m_size + x]);
}

void World::addCreature() {
	//Generate random coordinates in world space
	const int x = rand() % 1000;
	const int y = rand() % 1000;

	addCreature(x, y);
}

void World::addCreature(const int x, const int y) {
	//Create creature
	m_lastCreatureId++;
	Creature newCreature = Creature(m_lastCreatureId, x, y));
	m_creatures.push_back(newCreature);

	//Add creature to grid
	m_grid[x + y * m_size].addCreature(&newCreature);
}

void World::removeCreature(const int creatureId) {
	//Find creature in grid
	std::pair<int> coord;
	int indexInMCreatures;
	for (int i = 0; i < m_creatures.size(); i++) {
		if (creatureId == m_creatures[i].getId()) {
			coord = m_creatures[i].getCoord();
			indexInMCreatures = i;
			break;
		}
	}

	//If creature was found
	if (coord.first) {
		const int x = coord.first;
		const int y = coord.second;

		//Remove from grid
		for (int i = 0; i < m_creatures[x + y * m_size].m_creatures.size(); i++) {
			if (m_creatures[x + y * m_size].m_creatures[i].getId() == creatureId) {
				m_creatures[x + y * m_size].removeCreature(i);
				break;
			}
		}
		
		//Remove from world
		m_creatures.erase(m_creatures.begin() + indexInMCreatures);
	}
}

void World::evalEnvCreature() {
	//For each Creature
	for (int c = 0; i < m_creatures.size(); i++) {
		m_creatures[c].perceiveLocalEnv(this);
	}
}

void World::moveCreatures() {
	//For each Creature
	for (int c = 0; i < m_creatures.size(); i++) {
		//Perform move of Creature
		const std::pair<int, int> oldCoord = m_creatures[i].getCoord();
		const std::pair<int, int> newCoord = m_creatures[c].move();

		//Update the grid
		//Remove Creature from old Spot
		m_grid[oldCoord.second * m_size + oldCoord.first].removeCreature(m_creatures[i].getId());
		//Add Creature to new Spot
		m_grid[newCoord.second * m_size + newCoord.first.addCreature(&m_creatures[i]);
	}
}

void World::interactBtwCreatures() {
	// Get Creatures to interact
	// For now, dummy reproduction: each Spot with more than one Creature generates a new random Creature in one of the neighboring spots. The Creature is not added immediately but will be born in the simulation resolving step
	//Create creature
	m_lastCreatureId++;
	Creature newCreature = Creature(m_lastCreatureId, x, y));
	m_toBeBornCreatures.push_back(newCreature);
}

