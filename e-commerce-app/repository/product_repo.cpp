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
    void updateProductRepo(string name,int quantity){
        storage[name]->updatestock(quantity);

    }
    
    bool checkStock(string prodname, int quantity){
        if(storage.find(prodname) != storage.end()){
            if(storage[prodname]->getstock() >= quantity){
                //update stock as well
                // updateProductRepo(prodname,quantity);
                return true;
            };
        }
        return false;
    }

    int getStock(string name){
        if(storage.find(name) != storage.end()){
            return storage[name]->getstock();
        }
        return 0;
    }



};
