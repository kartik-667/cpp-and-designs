#include<bits/stdc++.h>
using namespace std;

class product{
    private:
    int id;
    double price;
    int stock;
    
    public:
    string name;

    product(int id, int st, double price,string nm){
        id=id;
        stock=st;
        price=price;
        name=nm;
    }

    void setstock(int n){
        this->stock+=n;
    }

    void setprice(double p){
        this->price=p;
    }


};

