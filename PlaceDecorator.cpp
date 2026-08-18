#include "PlaceDecorator.h"
#include <iostream>

PlaceDecorator::PlaceDecorator(Place* place) : wrappedPlace(place) {}

PlaceDecorator::~PlaceDecorator() {
    delete wrappedPlace;
    wrappedPlace = nullptr;
}

void PlaceDecorator::print() const {
    if (wrappedPlace) {
        wrappedPlace->print();
    }
}

void PlaceDecorator::add(Place* place) {
    if (wrappedPlace) {
        wrappedPlace->add(place);
    }
}

void PlaceDecorator::remove(Place* place) {
    if (wrappedPlace) {
        wrappedPlace->remove(place);
    }
}

WeatherFeature::WeatherFeature(Place* place, const std::string& weather)
    : PlaceDecorator(place), weatherCondition(weather) {}

void WeatherFeature::print() const {
    PlaceDecorator::print();
    std::cout << "    [Feature: Weather] Condition: " << weatherCondition << "\n";
}

TollFeature::TollFeature(Place* place, double fee)
    : PlaceDecorator(place), tollFee(fee) {}

void TollFeature::print() const {
    PlaceDecorator::print();
    std::cout << "    [Feature: Toll] Fee Amount: $" << tollFee << "\n";
}

QuestFeature::QuestFeature(Place* place, const std::string& quest)
    : PlaceDecorator(place), questName(quest) {}

void QuestFeature::print() const {
    PlaceDecorator::print();
    std::cout << "    [Feature: Quest] Available Quest: " << questName << "\n";
}