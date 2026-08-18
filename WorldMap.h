#ifndef COS_214_PA2_WORLDMAP_H
#define COS_214_PA2_WORLDMAP_H

#include <string>
#include <vector>
#include <iostream>

class Place {
public:
    virtual ~Place() {}
    virtual void print() const = 0;
    virtual void add(Place* place) {}
    virtual void remove(Place* place) {}
};

class Location : public Place {
private:
    std::string name;

public:
    Location(const std::string& locName);
    void print() const override;
};

class Region : public Place {
private:
    std::string name;
    std::vector<Place*> children;

public:
    Region(const std::string& regName);
    ~Region() override;
    void print() const override;
    void add(Place* place) override;
    void remove(Place* place) override;
};

#endif //COS_214_PA2_WORLDMAP_H
