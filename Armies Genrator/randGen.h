#pragma once

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <string>
#include <fstream>//for File hanfling

class Unit;

class randGen {
private:
    int ErthIDs;
    int AliensthIDs;

    // Generates a random number from 1 to 100
    short RandmonNumGent();

    // Generates a random number between min and max
    short RandmonRangeNum(int min, int max);

    // Generates the parameters of the unit armies from the input file
    // (health, power, capacity) based on the type of the army
    void genrateUnitParam(const std::string& unit, int& hlth, int& pwr, int& cap);

public:
    randGen();    // Constructor
    Unit* GenrateArmy(); // Army Generator
    bool isProbValid(int&); // Checks if the probability achieved or not
};

