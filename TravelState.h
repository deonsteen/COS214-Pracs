#ifndef COS_214_PA2_TRAVELSTATE_H
#define COS_214_PA2_TRAVELSTATE_H

#include <string>
#include <iostream>

class Traveller;

class TravelState {
public:
    virtual ~TravelState() {}
    virtual void move(Traveller* t) const = 0;
    virtual std::string getName() const = 0;
    virtual bool canEnter(const Traveller* t) const = 0;
    virtual bool isExhausted(const Traveller* t) const = 0;
};

class FootState : public TravelState {
public:
    void move(Traveller* t) const override;
    std::string getName() const override;
    bool canEnter(const Traveller* t) const override;
    bool isExhausted(const Traveller* t) const override;
};

class BicycleState : public TravelState {
public:
    void move(Traveller* t) const override;
    std::string getName() const override;
    bool canEnter(const Traveller* t) const override;
    bool isExhausted(const Traveller* t) const override;
};

class FlyState : public TravelState {
public:
    void move(Traveller* t) const override;
    std::string getName() const override;
    bool canEnter(const Traveller* t) const override;
    bool isExhausted(const Traveller* t) const override;
};

class Traveller {
    friend class FootState;
    friend class BicycleState;
    friend class FlyState;

private:
    TravelState* currentState;
    int stamina;
    int fuel;
    bool hasGlider;

public:
    explicit Traveller(TravelState* startingState);
    ~Traveller();

    void move();
    void setState(TravelState* s);
};

#endif //COS_214_PA2_TRAVELSTATE_H
