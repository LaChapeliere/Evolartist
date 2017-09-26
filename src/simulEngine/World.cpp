/**
 * Author: LaChapeliere
 * Copyright: GNU General Public License v3.0
 * Created on: 08-09-2017
 * Last modified on: 08-09-2017
 */

#include "World.h"

World::World(const int size, const int nbCreatures): m_size(size) {
	m_age = 0;
	m_incubationTime = 0;
	m_lastCreatureId = -1;
	
	//Create grid of Spots
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
	const int x = rand() % m_size;
	const int y = rand() % m_size;

	addCreature(x, y);
}

void World::addCreature(const int x, const int y) {
	//Create creature
	m_lastCreatureId++;
	m_creatures.push_back(Creature(m_lastCreatureId, x, y));

	//Add creature to grid
	m_grid[x + y * m_size].addCreature(&m_creatures[m_creatures.size() - 1]);
}

void World::removeCreature(const int creatureId) {
	//Find creature in grid
	std::pair<int, int> coord;
	int indexInMCreatures = -1;
	for (int i = 0; i < m_creatures.size(); i++) {
		if (creatureId == m_creatures[i].getId()) {
			coord = m_creatures[i].getCoord();
			indexInMCreatures = i;
			break;
		}
	}

	//If creature was found
	if (indexInMCreatures >= 0) {
		const int x = coord.first;
		const int y = coord.second;
		std::cout << " remove creature ";
		(m_creatures.begin() + indexInMCreatures)->printDebug();
		std::cout << std::endl;

		//Remove from grid
		m_grid[x + y * m_size].removeCreature(creatureId);
		
		//Remove from world
		m_creatures.erase(m_creatures.begin() + indexInMCreatures);
	}
}

void World::evalEnvCreatures() {
	//For each Creature
	for (int c = 0; c < m_creatures.size(); c++) {
		m_creatures[c].perceiveLocalEnv(this);
	}
}

void World::moveCreatures() {
	//For each Creature
	for (int c = 0; c < m_creatures.size(); c++) {
		//Perform move of Creature
		const std::pair<int, int> oldCoord = m_creatures[c].getCoord();
		const std::pair<int, int> newCoord = m_creatures[c].move();

		//Update the grid
		if (oldCoord.first!=newCoord.first && oldCoord.second!=newCoord.second) {
			//Remove Creature from old Spot
			m_grid[oldCoord.second * m_size + oldCoord.first].removeCreature(m_creatures[c].getId());
			//Add Creature to new Spot
			m_grid[newCoord.second * m_size + newCoord.first].addCreature(&m_creatures[c]);
		}
	}
}

void World::interactBtwCreatures() {
	// Get Creatures to interact
	// For now, dummy reproduction: each Spot with more than one Creature generates a new random Creature in one of the neighboring spots. The Creature is not added immediately but will be born in the simulation resolving step
	for (int x = 0; x < m_size; x++) {
		for (int y = 0; y < m_size; y++) {
			if (m_grid[y * m_size + x].getNbCreatures() > 1) {
				//Create creature
				int newX = (x + (rand() % 2 - 1)) % m_size;
				int newY = (y + (rand() % 2 - 1)) % m_size;
				m_lastCreatureId++;
				Creature newCreature = Creature(m_lastCreatureId, newX, newY);
				m_toBeBornCreatures.push_back(newCreature);
			}
		}
	}
}

void World::interactCreaturesEnv() {
	//For each Spot
	for (int s = 0; s < m_grid.size(); s++) {
		m_grid[s].feedCreatures();
	}
}

void World::resolveTurn() {
	//Update health and hunger for each Creature, then check if it's alive, remove it if not
	for (int c = m_creatures.size() - 1; c >= 0; c--) {
		m_creatures[c].hungerImpactHealth();
		m_creatures[c].growHungry();
		if (!m_creatures[c].isAlive()) {
			std::cout << "creature " << m_creatures[c].getId() << " is dead" << std::endl;
			removeCreature(m_creatures[c].getId());
		}
	}

	//Give birth to new Creatures
	for (int c = 0; c < m_toBeBornCreatures.size(); c++) {
		m_creatures.push_back(m_toBeBornCreatures[c]);
		const std::pair<int, int> coord = m_toBeBornCreatures[c].getCoord();

		//Add creature to grid
		m_grid[coord.first + coord.second * m_size].addCreature(&m_creatures[m_creatures.size() -1]);
	}
	m_toBeBornCreatures.clear();

	//Update vegetation on Spot objects
	for (int s = 0; s < m_grid.size(); s++) {
		m_grid[s].growFood();
	}

	//Update age and incubation time
	m_age++;
	m_incubationTime++;
}

void World::runSimulationStep() {

	std::cout << "State of the world:" << std::endl;
	for (int y = 0; y < m_size; y++) {
		for (int x = 0; x < m_size; x++) {
			std::cout << "(" << m_grid[y * m_size + x].getFood() << ", " << m_grid[y * m_size + x].getNbCreatures() << ") ";
		}
		std::cout << std::endl;
	}


	std::cout << "evalEnv" << m_age << std::endl;
	evalEnvCreatures();
	std::cout << "move" << m_age << std::endl;
	moveCreatures();
	std::cout << "interactX" << m_age << std::endl;
	interactBtwCreatures();
	std::cout << "interactEnv" << m_age << std::endl;
	interactCreaturesEnv();
	std::cout << "resolve" << m_age << std::endl;
	resolveTurn();
}
