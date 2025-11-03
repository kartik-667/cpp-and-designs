#include<bits/stdc++.h>
using namespace std;
#include "./controller/ecommerceapp.cpp"

int main(){
    cout<<"ecommerce app LLD"<<endl;
    //lets initialize the repo, service and then controller

    //repos
    ecommerceapp* app = new ecommerceapp();

    // Add serviceable pincodes
    app->addServicablePincode(110096);
    app->addServicablePincode(110091);

    // Register buyers
    app->registerUser("Kartik", 110096,100);
    app->registerUser("Rohan", 110091,101);

    // Add products
    app->addItem("iPhone 15", 79999,1, 10);
    app->addItem("MacBook Air", 120000,2, 5);

    // Check inventory
    cout << "\n--- Inventory Check ---\n";
     app->checkInventory("iPhone 15");
     app->checkInventory("MacBook Air");

    // Place orders
    cout << "\n--- Order Placement ---\n";
    app->buyproduct("Kartik", 110096,"iPhone 15", 2);       // valid
    app->buyproduct("Kartik",110096, "MacBook Air", 10);    // invalid (not enough stock)
    app->buyproduct("Rohan",110091, "iPhone 15", 1);        // valid
    app->buyproduct("UnknownBuyer",110091, "iPhone 15", 1); // invalid (buyer not found)

    // Check inventory again
     cout << "\n--- Inventory Check ---\n";
     app->checkInventory("iPhone 15");
     app->checkInventory("MacBook Air");

    // cleanup memory
    delete app;
    



return 0;
}
