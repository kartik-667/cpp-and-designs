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
    int bannedcount;

    junctionnode(string n,int maxi){
        name=n;
        maxload=maxi;
        currentload=0;
        signal="";
        bannedcount=0;
        signaltime=0;

    }

};

class SmartCity{
    

    public:
    unordered_map<string,int> vehloads={{"Car",2},{"Bike",2},{"Bus",4},{"Truck",5}};

    unordered_map<string,junctionnode*> junctionmap; //junc and its node
    unordered_map<string,vehiclenode*> vehiclemap;
    set<int> signaltimes;

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
        //for each junction
        for(auto itr:junctionmap){
            junctionnode* junc=itr.second;
            if(junc->signal=="RED"){
                //get all vehicles
                // vector<vehiclenode banned;
                unordered_set<vehiclenode*> banned;
                for(auto& v:vehiclemap){
                    if(v.second->junction==itr.first){
                        v.second->violation++;
                        if(v.second->violation>=3){
                            banned.insert(v.second);
                            junc->currentload-=v.second->load;
                            junc->bannedcount++;
                        }
                        // allveh.push_back(v.second);
                    }
                }
                //now remove banned vehicles
                int qsize=junc->vehiclesqueue.size();
                for(int i=0;i<qsize;i++){
                    auto ele=junc->vehiclesqueue.front();
                    junc->vehiclesqueue.pop_front();
                    if(banned.find(ele) == banned.end()){
                        //push unbanned again in queue
                        junc->vehiclesqueue.push_back(ele);
                    }

                }
                for(auto itr:banned){
                    vehiclemap.erase(itr->number);
                }




            }else{
                continue; //go for next junc
            }


        }

    }

    void removeVehicle(string junctionName, string vehicleNumber)
    {
        if(vehiclemap.find(vehicleNumber) == vehiclemap.end()){
            return;
        }
        junctionnode* junc=junctionmap[junctionName];
        vehiclenode* vehicle=vehiclemap[vehicleNumber];

        int size=junc->vehiclesqueue.size();
        for(int i=0;i<size;i++){
            auto ele=junc->vehiclesqueue.front();
            junc->vehiclesqueue.pop_front();
            if(ele->number!=vehicleNumber){
                junc->vehiclesqueue.push_back(ele);

            }
        }
        vehiclemap.erase(vehicleNumber);
        return;
    }


    
    void printSignals(int startTime, int endTime)
    {
        // unordered_map<int,vector<string>> mp; //time,junctionname
        for(int i=startTime;i<=endTime;i++){

            if(signaltimes.find(i) != signaltimes.end()){
                cout<<"Time "<<i<<endl;
                for(auto itr:junctionmap){
                    if(itr.second->signaltime==i){
                        cout<<itr.second->name<<endl;
                    }
                }

            }
        }
        return;

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
