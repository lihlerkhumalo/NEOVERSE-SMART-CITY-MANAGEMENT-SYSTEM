#include "CityComponent.h"

CityComponent::CityComponent(int id, std::string n) : componentID(id), name(n) {}
CityComponent::~CityComponent() {}

void CityComponent::activate() { std::cout << name << " is now ONLINE.\n"; }
void CityComponent::deactivate() { std::cout << name << " is now OFFLINE.\n"; }
std::string CityComponent::getStatus() { return name + " is stable."; }

// Power System
PowerSystem::PowerSystem(int id, double pl) : CityComponent(id, "Power Grid"), powerLevel(pl) {}
void PowerSystem::supplyPower() { std::cout << "Grid output: " << powerLevel << "MW.\n"; }
void PowerSystem::processEvent() { std::cout << "Adjusting voltage for city event...\n"; }

// Transport System
TransportSystem::TransportSystem(int id, int tf) : CityComponent(id, "Traffic Control"), trafficFlow(tf) {}
void TransportSystem::manageTraffic() { std::cout << "Optimizing " << trafficFlow << " traffic lanes.\n"; }
void TransportSystem::processEvent() { std::cout << "Rerouting autonomous vehicles...\n"; }
