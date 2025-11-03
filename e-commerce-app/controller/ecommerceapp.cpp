#include<bits/stdc++.h>
using namespace std;
#include "../services/buyerservice.cpp"
#include "../services/pincodeservice.cpp"
#include "../services/productservice.cpp"

//this is controller for ecommerce app
//controller talks with services, services with repo , repos with classes/models
class ecommerceapp{
    private:
    buyerservice* buyer_service;
    pincodeservice* pincode_service;
    productservice* product_service;


    public:

    ecommerceapp(){
    buyer_repository* buyerrepo=new buyer_repository();
    pincode_repository* pincoderepo=new pincode_repository();
    product_repository* productrepo=new product_repository();

    //services
    buyerservice* buyer_service=new buyerservice(buyerrepo);
    pincodeservice* pincode_service=new pincodeservice(pincoderepo);
    productservice* product_service=new productservice(productrepo);

    this->buyer_service=buyer_service;
        this->pincode_service=pincode_service;
        this->product_service=product_service;


    }

    ecommerceapp(buyerservice* b,pincodeservice* pinc,productservice* p){
        
        buyer_service=b;
        pincode_service=pinc;
        product_service=p;

        
    }

    void registerUser(string n, int pin, int bid){
        buyer_service->registerBuyer(n,pin,bid);
    }

    void buyproduct(string buyername,int pincode,string prodname,int quantity){
        //first check buyer, then check pincode, then check productquantity
        bool res1=buyer_service->findBuyer(buyername);
        if(res1){
            bool res2=pincode_service->isServicableatPin(pincode);
            if(res2){
                bool res3=product_service->checkStock(prodname,quantity);
                if(res3){
                    cout<<"products bought sucessfully \n";
                }else{
                    cout<<"not enough stock \n";
                }

            }else{
                cout<<"cant deliver at pincode \n";
            }

        }else{
            cout<<"user not found, create acc first \n";
        }


    }

    void addItem(string name, double price, int id,int quant ){
        product_service->additem(name,price,id,quant);
    }

    void addServicablePincode(int pin){
        pincode_service->addPinCode( pin);
    }

    void checkInventory(string name){
        int val=product_service->getStock(name);
        cout<<name<<" stock is "<<val<<endl;

    }


};