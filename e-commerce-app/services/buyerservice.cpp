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



};