#include<bits/stdc++.h>
using namespace std;

#include "classes.cpp"
//this contains the main atm machien class

enum class state{
    IDLE,
    HASCARD,
    PINVERIFIED,
    SELECTOPR,
    TRANSACTION
};

class atm_machine{
    private:
    unordered_map<int,account*> accounts;
    card* currentcard;
    atm_inventory* inventory;
    state currstate;

    public:
    string machinename;

    atm_machine(string n){
        this->machinename=n;
        currentcard=NULL;
        inventory=new atm_inventory();
        this->currstate=state::IDLE;
    }

    void addAccount(){
        
    }






};