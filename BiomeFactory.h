#ifndef COS_214_PA2_BIOMEFACTORY_H
#define COS_214_PA2_BIOMEFACTORY_H

#include <string>
#include <iostream>

// Abstract Products
class Terrain {
public:
    virtual ~Terrain() {}
    virtual void describe() const = 0;
};

class NPC {
public:
    virtual ~NPC() {}
    virtual void interact() const = 0;
};

class Obstacle {
public:
    virtual ~Obstacle() {}
    virtual void encounter() const = 0;
};

// Concrete Products for Desert
class DesertTerrain : public Terrain {
public:
    void describe() const override;
};

class DesertNPC : public NPC {
public:
    void interact() const override;
};

class DesertObstacle : public Obstacle {
public:
    void encounter() const override;
};

// Concrete Products for Ocean
class OceanTerrain : public Terrain {
public:
    void describe() const override;
};

class OceanNPC : public NPC {
public:
    void interact() const override;
};

class OceanObstacle : public Obstacle {
public:
    void encounter() const override;
};

// Abstract Factory
class WorldBuilder {
public:
    virtual ~WorldBuilder() {}
    virtual Terrain* createTerrain() = 0;
    virtual NPC* createNPC() = 0;
    virtual Obstacle* createObstacle() = 0;
};

// Concrete Factory for Desert
class DesertFactory : public WorldBuilder {
public:
    Terrain* createTerrain() override;
    NPC* createNPC() override;
    Obstacle* createObstacle() override;
};

// Concrete Factory for Ocean
class OceanFactory : public WorldBuilder {
public:
    Terrain* createTerrain() override;
    NPC* createNPC() override;
    Obstacle* createObstacle() override;
};

#endif //COS_214_PA2_BIOMEFACTORY_H
