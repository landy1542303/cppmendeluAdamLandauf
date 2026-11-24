#include "RoverTest.hpp"
#include "../Rover.h"
#include "../materials/Ice.h"
#include "../materials/Water.h"
#include "../materials/Soil.h"
#include "../materials/Concrete.h"
#include <cmath>
#include <memory>

void RoverTest::run() {
    testProcessMaterialInStorageWithIce();
    testProcessMaterialInStorageWithSoil();
    testTransferBetweenRovers();
}

void RoverTest::testProcessMaterialInStorageWithIce() {
    Rover<Ice, Water> iceRover;
    iceRover.loadMaterial(std::make_unique<Ice>(10.0f, -20.0f));
    iceRover.loadMaterial(std::make_unique<Ice>(20.0f, -15.0f));
    iceRover.printStorageInfo();

    auto waterStorage = iceRover.processMaterialInStorage();
    test_(waterStorage.size() == 2);
    test_(std::abs(waterStorage[0]->m_volume - 9.0f) < 0.001f);
    test_(std::abs(waterStorage[1]->m_volume - 18.0f) < 0.001f);
}

void RoverTest::testProcessMaterialInStorageWithSoil() {
    Rover<Soil, Concrete> soilRover;
    soilRover.loadMaterial(std::make_unique<Soil>(100.0f, "basalt"));
    soilRover.loadMaterial(std::make_unique<Soil>(50.0f, "iron oxide"));
    soilRover.printStorageInfo();

    auto concreteStorage = soilRover.processMaterialInStorage();
    test_(concreteStorage.size() == 2);
    test_(std::abs(concreteStorage[0]->m_weight - 14.0f) < 0.001f);
    test_(std::abs(concreteStorage[1]->m_weight - 7.0f) < 0.001f);
}

void RoverTest::testTransferBetweenRovers() {
    Rover<Ice, Water> roverA;
    Rover<Ice, Water> roverB;

    roverA.loadMaterial(std::make_unique<Ice>(30.0f, -10.0f));
    roverA.transferStorageTo(roverB);

    test_(roverA.processMaterialInStorage().empty());
    auto waterFromB = roverB.processMaterialInStorage();
    test_(waterFromB.size() == 1);
    test_(std::abs(waterFromB[0]->m_volume - 27.0f) < 0.001f);
}
