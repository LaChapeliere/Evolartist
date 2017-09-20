/**
 * Author: LaChapeliere
 * Copyright: GNU General Public License v3.0
 * Created on: 27-08-2017
 * Last modified on: 27-08-2017
 */


//main function for compilation tests

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "simulEngine/World.h"
using namespace std;

int main(){

	srand (time(NULL));

    	cout << "Hello World!" << endl;

	// Run the simulation. No insight on what's happening in the back box for now
	World myWorld(100, 10);
	for (int t = 0; t < 10; t++) {
		myWorld.runSimulationStep();
	}

    	return 0;

}