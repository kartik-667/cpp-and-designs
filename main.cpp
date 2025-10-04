#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include<bits/stdc++.h>
using namespace std;

class AstronautNode{
    public:
    string name;
    string module;
    string role;

    AstronautNode(string n,string r,string m){
        name=n;
        role=r;
        module=m;
    }

};

class ExperimentNode{
    public:
    string name;
    string module;
    int day;

    ExperimentNode(string n,string m, int d){
        name=n;
        module=m;
        day=d;
    }



};


class SpaceStation{
    public:

    unordered_map<string,AstronautNode*> astromap;
    unordered_map<string,vector<string>> modulemap; //modulename, and people

    int maxcapacity=3;

    unordered_map<string,vector<ExperimentNode*>> moduleexpmap;
    unordered_map<int,vector<ExperimentNode*>> dayexpmap;

    void addAstronaut(string name,string role,string module){
        if(modulemap[module].size() >= maxcapacity){
            cout<<module<<"is full, max capacity reached it cannot be added\n";
            
        }else{
            AstronautNode* newn=new AstronautNode(name,role,module);
            astromap[name]=newn;
            modulemap[module].push_back(name);
            cout<<"Added "<<name<<"to "<<module<<endl;
            
            
        }

        return;

    }

    void scheduleExperiment(string expname,string module, int day){
        ExperimentNode* newn=new ExperimentNode(expname,module,day);
        moduleexpmap[module].push_back(newn);
        dayexpmap[day].push_back(newn);
        cout<<"Scheduled experiment "<<expname<<"in "<<module<<"on day "<<day<<endl;
        return;


    }




};


int main() {
    SpaceStation station;

    // === Add astronauts ===
    station.addAstronaut("Dr. Elena Chen", "Botany", "Greenhouse");
    station.addAstronaut("Prof. Marco Rodriguez", "Physics", "Laboratory");
    station.addAstronaut("Engineer Sarah Smith", "Engineering", "Engineering");
    station.addAstronaut("Dr. Arjun Patel", "Medical", "Habitat");

    // Try to overfill a module
    station.addAstronaut("Extra Crew 1", "Engineering", "Engineering");
    station.addAstronaut("Extra Crew 2", "Engineering", "Engineering");
    station.addAstronaut("Extra Crew 3", "Engineering", "Engineering"); // Should fail

    // === Schedule experiments ===
    station.scheduleExperiment("Plant Growth Zero-G", "Greenhouse", 1);
    station.scheduleExperiment("Quantum Entanglement", "Laboratory", 1);
    station.scheduleExperiment("Life Support Stress Test", "Engineering", 2);
    station.scheduleExperiment("Zero-G Bone Density", "Habitat", 2);

    // === Process experiments ===
    station.processExperiments(1);
    station.processExperiments(2);
    station.processExperiments(3); // No experiments

    // === Print final status ===
    station.printStatus();

    // === Bonus: Show astronauts with given role ===
    cout << "\nAstronauts with role 'Engineering':" << endl;
    vector<string> engineers = station.getAstronautsByRole("Engineering");
    if (engineers.empty()) {
        cout << " None found." << endl;
    } else {
        for (const string& name : engineers) {
            cout << " - " << name << endl;
        }
    }

    // === Bonus: Emergency handling function ===
    station.handleEmergency("Laboratory", "Oxygen Leak");

    // Attempt to add astronaut or schedule experiment in emergency module (should be blocked)
    station.addAstronaut("New Astronaut", "Physics", "Laboratory");
    station.scheduleExperiment("Emergency Research", "Laboratory", 5);

    // Processing experiments again after emergency
    station.processExperiments(5);

    return 0;
}
