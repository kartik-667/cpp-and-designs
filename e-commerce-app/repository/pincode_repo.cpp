#include<bits/stdc++.h>
using namespace std;
//contain all serviceble pincodes


class pincode_repository{
    private:
    unordered_set<int> pincodes;

    public:
    void addPincode(int pin){
        pincodes.insert(pin);
    }

    bool isServicableatPin(int pin){
        if(pincodes.find(pin) != pincodes.end()){
            return true;
        }
        return false;
    }





};
