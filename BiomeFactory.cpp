#include "BiomeFactory.h"

// Desert Products Implementation
void DesertTerrain::describe() const {
    std::cout << "[Desert Terrain] Endless dunes of hot sand under a blazing sun.\n";
}

void DesertNPC::interact() const {
    std::cout << "[Desert NPC] A wandering nomad offers you a flask.\n";
}

void DesertObstacle::encounter() const {
    std::cout << "[Desert Obstacle] A sudden, blinding sandstorm blocks your path!\n";
}

// Ocean Products Implementation
void OceanTerrain::describe() const {
    std::cout << "[Ocean Terrain] Rolling waves stretching to the horizon.\n";
}

void OceanNPC::interact() const {
    std::cout << "[Ocean NPC] A friendly mermaid surfaces on a rock and sings the direction of a reef for you.\n";
}

void OceanObstacle::encounter() const {
    std::cout << "[Ocean Obstacle] Whirlpool threatens to pull you under!\n";
}

// Desert Factory Implementation
Terrain* DesertFactory::createTerrain() {
    return new DesertTerrain();
}

NPC* DesertFactory::createNPC() {
    return new DesertNPC();
}

Obstacle* DesertFactory::createObstacle() {
    return new DesertObstacle();
}

// Ocean Factory Implementation
Terrain* OceanFactory::createTerrain() {
    return new OceanTerrain();
}

NPC* OceanFactory::createNPC() {
    return new OceanNPC();
}

Obstacle* OceanFactory::createObstacle() {
    return new OceanObstacle();
}