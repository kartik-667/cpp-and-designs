#include<bits/stdc++.h>
using namespace std;

class state{
    public:

    // string name;
    // state(string nm){
    //     this->name=nm;
    // }

};

class idle:public state{
    public:
    string name;
    
    idle(){
        name="idle";
    }


};

class product_selection:public state{
    public:
    string name;

    product_selection(){
        this->name="product_selection";
    }
};

class item{
    public:
    string name;
    int price;
    int stock;

    item(string n,int p,int st){
        name=n;
        price=p;
        stock=st;
    }

};



class payment_interface{
    public:

    virtual void pay() =0; //pure virtual fnc


};

class pay_coins : public payment_interface{
    public:

    void pay(){
        cout<<"paying with coins \n";
    }


};



class vending_machine{
    public:
    vector<item*> items;
    int amount;
    state* currstate;
    idle* idlestate;
    product_selection* product_selectionstate;


    vending_machine(){
        items.push_back(new item("coke",30,20));
        items.push_back(new item("pepsi",50,15));
        items.push_back(new item("sting",20,30));

        idlestate=new idle();
        product_selectionstate=new product_selection();
        currstate=idlestate;

    }




};



int main(){


return 0;
}
