#include<bits/stdc++.h>
using namespace std;


int main() {
    SmartCity city;

    city.enterJunction("UP32AB1234", "Car", "Alpha");
    city.enterJunction("UP32BB5678", "Bus", "Beta");
    city.enterJunction("UP32CC9876", "Truck", "Alpha");
    city.enterJunction("UP32DD4321", "Bike", "Beta");
    city.enterJunction("UP32EE9999", "Car", "Alpha");

    city.updateSignal("Alpha", "GREEN", 1);
    city.updateSignal("Beta", "RED", 1);
    city.updateSignal("Alpha", "RED", 2);
    city.updateSignal("Beta", "GREEN", 2);
    city.updateSignal("Alpha", "RED", 5);
    city.updateSignal("Alpha", "YELLOW", 8);

    city.checkViolations();

    city.removeVehicle("Alpha", "UP32EE9999");

    city.printVehicles();

    city.printStatus();

    city.printSignals(1, 8);

    return 0;
}
