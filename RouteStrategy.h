#ifndef COS_214_PA2_ROUTESTRATEGY_H
#define COS_214_PA2_ROUTESTRATEGY_H

#include <string>
#include <iostream>
#include <vector>

class RouteStrategy {
public:
    virtual ~RouteStrategy() {}
    virtual void calculateRoute(const std::string& start, const std::string& destination) = 0;
};

class ShortestRoute : public RouteStrategy {
public:
    void calculateRoute(const std::string& start, const std::string& destination) override;
};

class FastestRoute : public RouteStrategy {
public:
    void calculateRoute(const std::string& start, const std::string& destination) override;
};

class ScenicRoute : public RouteStrategy {
public:
    void calculateRoute(const std::string& start, const std::string& destination) override;
};

class Trip {
private:
    RouteStrategy* strategy;

public:
    Trip(RouteStrategy* initialStrategy);
    ~Trip();
    void setStrategy(RouteStrategy* newStrategy);
    void executeTrip(const std::string& start, const std::string& destination);
};

#endif //COS_214_PA2_ROUTESTRATEGY_H
