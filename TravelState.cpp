#include "TravelState.h"

// FootState: the fallback state. Always available, never runs out.
void FootState::move(Traveller *t) const
{
    std::cout << "[On Foot] You walk steadily along the path.\n";
    t->stamina -= 5;
    if (t->stamina < 0)
        t->stamina = 0;
}

std::string FootState::getName() const
{
    return "On Foot";
}

bool FootState::canEnter(const Traveller *t) const
{
    (void)t;
    return true;
}

bool FootState::isExhausted(const Traveller *t) const
{
    (void)t;
    return false;
}

void BicycleState::move(Traveller *t) const
{
    std::cout << "[Bicycle] You pedal hard, covering ground fast.\n";
    t->stamina -= 10;
    if (t->stamina < 0)
        t->stamina = 0;
}

std::string BicycleState::getName() const
{
    return "Bicycle";
}

bool BicycleState::canEnter(const Traveller *t) const
{
    return t->stamina >= 20;
}

bool BicycleState::isExhausted(const Traveller *t) const
{
    return t->stamina <= 0;
}

void FlyState::move(Traveller *t) const
{
    std::cout << "[Flying] You catch a thermal and soar above the map.\n";
    t->fuel -= 25;
    if (t->fuel < 0)
        t->fuel = 0;
    t->stamina -= 5;
    if (t->stamina < 0)
        t->stamina = 0;
}

std::string FlyState::getName() const
{
    return "Flying";
}

bool FlyState::canEnter(const Traveller *t) const
{
    return t->hasGlider && t->fuel >= 30 && t->stamina >= 50;
}

bool FlyState::isExhausted(const Traveller *t) const
{
    return t->fuel <= 0;
}

Traveller::Traveller(TravelState *startingState)
    : currentState(startingState), stamina(100), fuel(50), hasGlider(false)
{
    if (!currentState)
    {
        currentState = new FootState();
    }
}

Traveller::~Traveller()
{
    delete currentState;
}

void Traveller::move()
{
    currentState->move(this);
    if (currentState->isExhausted(this))
    {
        std::cout << "[Traveller] Out of resources for " << currentState->getName()
                << ", forced back on foot.\n";
        setState(new FootState());
    }
}

void Traveller::setState(TravelState *s)
{
    if (!s)
    {
        return;
    }
    if (s == currentState)
    {
        return;
    }
    if (s->getName() == currentState->getName())
    {
        delete s;
        return;
    }
    if (!s->canEnter(this))
    {
        std::cout << "[Traveller] Cannot switch to " << s->getName() << " right now.\n";
        delete s;
        return;
    }
    std::cout << "[Traveller] Switching from " << currentState->getName()
            << " to " << s->getName() << ".\n";
    delete currentState;
    currentState = s;
}
