#pragma once
#include <iostream>
#include <string>

class CityComponent {
protected:
    int componentID;
    std::string name;
public:
    CityComponent(int id, std::string n);
    virtual ~CityComponent();
    virtual void activate();
    virtual void deactivate();
    virtual std::string getStatus();
    virtual void processEvent() = 0; // pure virtual
};

// Power System
class PowerSystem : public CityComponent {
    double powerLevel;
public:
    PowerSystem(int id, double pl);
    void supplyPower();
    void processEvent() override;
};

// Transport System
class TransportSystem : public CityComponent {
    int trafficFlow;
public:
    TransportSystem(int id, int tf);
    void manageTraffic();
    void processEvent() override;
};
