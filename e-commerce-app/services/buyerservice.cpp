#include<bits/stdc++.h>
using namespace std;
#include "../repository/buyer_repo.cpp"


class buyerservice{
    private:
    buyer_repository* buyrepo;

    public:
    buyerservice(buyer_repository* b){
        buyrepo=b;
    }

    bool buyProduct(string name,string prodname,int quantity){
        if(buyrepo->findBuyer(name)){
            return true;
        }
        cout<<"user doesnt exist, create account first \n";
        return false;

    }

    void registerBuyer(string n, int pin, int bid){
        buyrepo->registerBuyer(n,pin,bid); 
    }

    bool findBuyer(string name){
        return buyrepo->findBuyer(name);

    }



};