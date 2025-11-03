#include<bits/stdc++.h>
using namespace std;
#include "../repository/pincode_repo.cpp"

class pincodeservice{
    private:
    pincode_repository* pincodes;
    public:
    pincodeservice(pincode_repository* p){
        pincodes=p;
    }

    void addPinCode(int pin){
        pincodes->addPincode(pin);
        return;
    }

    bool isServicableatPin(int pin){
        return pincodes->isServicableatPin(pin);
    }


};
