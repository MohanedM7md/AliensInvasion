#pragma once
#include <random>
#include <string>
#include <fstream>//for File hanfling
#include "../DEFS.h"
#include "../Unit Armies/EG.h"
class Game;
class Unit;

class randGen {
private:
    int ErthIDs;
    int AliensthIDs;
    Game* Gptr;
    parameters param;

public:
    randGen(Game* Gptr);    // Constructor

    void setParameters(parameters& param);

    // Generates a random number from 1 to 100
    short RandmonNumGent();

    // Generates a random number between min and max
    short RandmonRangeNum(int* range) const;

    // Generates the parameters of the unit armies from the input file
    // (health, power, capacity) based on the type of the army
    void GenrateArmy(int Tj); // Army Generator
};

