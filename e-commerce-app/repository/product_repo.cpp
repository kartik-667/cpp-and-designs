#include<bits/stdc++.h>
using namespace std;
#include "../models/product.cpp"

class product_repository{
    private:

    unordered_map<string,product*> storage;

    public:

    void additem(string name,double price,int id,int quantity){
        if(storage.find(name) == storage.end()){
            storage[name]=new product(id,quantity,price,name);


        }else{
            //update product
            auto prod=storage[name];
            prod->setprice(price);
            prod->setstock(quantity);
            
        }

    }



};
