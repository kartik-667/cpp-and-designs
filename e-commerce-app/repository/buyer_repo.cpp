#include<bits/stdc++.h>
using namespace std;
#include "../models/buyer.cpp"

//this contains all the buyers

class buyer_repository{
    private:
    unordered_map<string,buyer*> buyers;

    public:

    void registerBuyer(string n, int pin, int bid){
        if(buyers.find(n) == buyers.end()){
            buyers[n]= new buyer(n,pin,bid);
        }else{
            cout<<"buyer already exist \n";
        }
        return;
    }


};
