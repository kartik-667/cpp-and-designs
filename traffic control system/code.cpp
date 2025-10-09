#include<bits/stdc++.h>
using namespace std;

class vehiclenode{
    public:

    string number;
    string type;
    int violation;
    bool isbanned;
    string junction;
    int load;

    vehiclenode(string num,string type,string junc, int load){
        number=num;
        type=type;
        violation=0;
        isbanned=false;
        junction=junc;
        load=load;

    }

};

class junctionnode{
    public:

    string name;
    int maxload;
    int currentload;
    deque<vehiclenode*> vehiclesqueue;
    // unordered_set<vehiclenode*> vehicles; //we fetch it from vehicle maps
    string signal;
    int signaltime;

    junctionnode(string n,int maxi){
        name=n;
        maxload=maxi;
        currentload=0;
        signal="";

        signaltime=0;

    }

};

class SmartCity{
    

    public:
    unordered_map<string,int> vehloads={{"Car",2},{"Bike",2},{"Bus",4},{"Truck",5}};

    unordered_map<string,junctionnode*> junctionmap; //junc and its node
    unordered_map<string,vehiclenode*> vehiclemap;

    SmartCity(){
        //make all junctions
        junctionmap["Alpha"]=new junctionnode("Alpha",7);
        junctionmap["Beta"]=new junctionnode("Beta",8);
        junctionmap["Gamma"]=new junctionnode("Gamma",6);

    }



    bool enterJunction(string vehn,string type, string junc){
        //if junc is not found then only make object
        junctionnode* junction=NULL;

        if(junctionmap.find(junc) != junctionmap.end()){
            junction=junctionmap[junc];
        }else{
            return false;
        }

        if(junction->currentload + vehloads[type] > junction->maxload){
            return false;// cant add vehicles

        }else{
            vehiclenode* newv=new vehiclenode(vehn,type,junc,vehloads[type]);
            vehiclemap[vehn]=newv;
            junction->vehiclesqueue.push_back(newv);
            junction->currentload+=vehloads[type];
        }

        return true;


        


    }

    void updateSignal(string junctionName, string signal, int time)
    {
        if(junctionmap.find(junctionName) == junctionmap.end()){
            return;
        }

        junctionnode* junc=junctionmap[junctionName];
        junc->signal=signal;
        junc->signaltime=time;
        return;


    }

    void checkViolations(){
        
    }






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
