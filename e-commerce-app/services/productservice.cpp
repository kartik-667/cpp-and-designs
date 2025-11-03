#include<bits/stdc++.h>
using namespace std;
#include "../repository/product_repo.cpp"

class productservice{
    private:
    product_repository* products;

   
    

    public:
    productservice(product_repository* p ){
        products=p;
    }

    void additem(string name,double price,int id,int quantity){
        products->additem(name,price,id,quantity);

    }

    bool checkStock(string prodname, int quantity){
       bool temp= products->checkStock(prodname,quantity);
       if(temp){
        products->updateProductRepo(prodname,quantity);
       }
    }
    int getStock(string name){
        return products->getStock(name);
    }




};

