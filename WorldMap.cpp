#include "WorldMap.h"

Location::Location(const std::string& locName) : name(locName) {}

void Location::print() const {
    std::cout << "[Location] " << name << "\n";
}

Region::Region(const std::string& regName) : name(regName) {}

Region::~Region() {
    for (size_t i = 0; i < children.size(); ++i) {
        delete children[i];
    }
    children.clear();
}

void Region::print() const {
    std::cout << "[Region] " << name << " contains:\n";
    for (size_t i = 0; i < children.size(); ++i) {
        std::cout << "  ";
        children[i]->print();
    }
}

void Region::add(Place* place) {
    if (place) {
        children.push_back(place);
    }
}

void Region::remove(Place* place) {
    for (typename std::vector<Place*>::iterator it = children.begin(); it != children.end(); ++it) {
        if (*it == place) {
            delete *it;
            children.erase(it);
            break;
        }
    }
}