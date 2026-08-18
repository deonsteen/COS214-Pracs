#ifndef COS_214_PA2_PLACEDECORATOR_H
#define COS_214_PA2_PLACEDECORATOR_H

#include "WorldMap.h"
#include <string>

class PlaceDecorator : public Place {
protected:
    Place* wrappedPlace;

public:
    PlaceDecorator(Place* place);
    virtual ~PlaceDecorator();
    void print() const override;
    void add(Place* place) override;
    void remove(Place* place) override;
};

class WeatherFeature : public PlaceDecorator {
private:
    std::string weatherCondition;

public:
    WeatherFeature(Place* place, const std::string& weather);
    void print() const override;
};

class TollFeature : public PlaceDecorator {
private:
    double tollFee;

public:
    TollFeature(Place* place, double fee);
    void print() const override;
};

class QuestFeature : public PlaceDecorator {
private:
    std::string questName;

public:
    QuestFeature(Place* place, const std::string& quest);
    void print() const override;
};

#endif //COS_214_PA2_PLACEDECORATOR_H
