#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;



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
