#include "RouteStrategy.h"

void ShortestRoute::calculateRoute(const std::string& start, const std::string& destination) {
    std::cout << "[Shortest Route] Calculating the shortest path from "
              << start << " to " << destination << " (minimizing distance).\n";
}

void FastestRoute::calculateRoute(const std::string& start, const std::string& destination) {
    std::cout << "[Fastest Route] Calculating the fastest path from "
              << start << " to " << destination << " (prioritizing highways/speed).\n";
}

void ScenicRoute::calculateRoute(const std::string& start, const std::string& destination) {
    std::cout << "[Scenic Route] Calculating the scenic path from "
              << start << " to " << destination << " (routing through landmarks and nature).\n";
}

Trip::Trip(RouteStrategy* initialStrategy) : strategy(initialStrategy) {
    if (!strategy) {
        std::cout << "Trip initialized with a null strategy.\n";
    }
}

Trip::~Trip() {
    delete strategy;
    strategy = nullptr;
}

void Trip::setStrategy(RouteStrategy* newStrategy) {
    if (strategy != newStrategy) {
        delete strategy;
        strategy = newStrategy;
    }
}

void Trip::executeTrip(const std::string& start, const std::string& destination) {
    if (strategy) {
        strategy->calculateRoute(start, destination);
    } else {
        std::cout << "No route strategy set for this trip.\n";
    }
}
