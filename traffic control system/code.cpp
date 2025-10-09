#include<bits/stdc++.h>
using namespace std;

class vehiclenode{
    public:

    string number;
    string type;
    int violation;
    bool isbanned;
    string junction;

    vehiclenode(string num,string type,string junc){
        number=num;
        type=type;
        violation=0;
        isbanned=false;
        junction=junc;

    }

};

class junctionnode{
    public:

    string name;
    int maxload;
    int currentload;
    // deque<vehiclenode*> vehicles;
    unordered_set<vehiclenode*> vehicles;
    string signal;
    int signaltime;

    junctionnode(string n,int maxi,string signal, int time){
        name=n;
        maxload=maxi;
        currentload=0;
        signal=signal;
        signaltime=time;

    }

};

class SmartCity{
    

    public:
    unordered_map<string,int> vehloads={{"Car",2},{"Bike",2},{"Bus",4},{"Truck",5}};




};


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
