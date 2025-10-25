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

class payment_state:public state{
    public:
    string name;

    payment_state(){
        this->name="payment_state";
    }


};

class refund:public state{
    public:
     string name;

    refund(){
        this->name="refund";
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

    virtual bool pay(int total, int amountbyuser) =0; //pure virtual fnc - abstract function

    virtual void refund()=0;


};

class pay_coins : public payment_interface{
    public:

    bool pay(int total,int amountbyuser){

        cout<<"paying with coins \n";
        if(total > amountbyuser){
            cout<<"not sufficient money found \n";
            return false;


        }else{
            cout<<"payment successful\n";
            return true;
        }
    }

    void refund(){
        cout<<"refunding the coins...\n";

    }


};

class pay_card:public payment_interface{
    public:
    bool pay(int total,int amountbyuser){
        cout<<"paying with card \n";
        if(total > amountbyuser){
            cout<<"not sufficient money found \n";
            return false;


        }else{
            cout<<"payment successful\n";
            return true;
        }


    }

    void refund(){
        cout<<"cancelling the card transactions...\n";
    }

};



class vending_machine{
    public:
    vector<item*> items; //this is inventory
    int amount;

    unordered_map<string,int> items_selected;

    int balance;

    state* currstate;
    idle* idlestate;
    product_selection* product_selectionstate;
    payment_state* paymentstate;
    refund* refundstate;


    pay_coins* paywithcoins;
    pay_card* paywithcard;


    vending_machine(){
        items.push_back(new item("coke",30,20));
        items.push_back(new item("pepsi",50,15));
        items.push_back(new item("sting",20,30));
        balance=500;
        amount=0;
        idlestate=new idle();
        product_selectionstate=new product_selection();
        paymentstate=new payment_state();
        refundstate=new refund();
        currstate=idlestate;

        paywithcard=new pay_card();
        paywithcoins=new pay_coins();
        

    }

    //by customer
    void additems(string name,int quant){
        currstate=product_selectionstate;
        for(auto& itr:items){
            if(itr->name==name){
                if(quant<=itr->stock){
                    // items available
                    // itr->stock-=quant;
                    // amount+=(itr->price * quant);
                    // cout<<"current amount is "<<amount<<endl;
                    // currstate=paymentstate; //change to payment state
                    items_selected[name]+=(quant);
                    cout<<"items added to cart\n";
                    return;

                }else{
                    cout<<"items are out of stock...";
                    currstate=idlestate;
                    return;

                }
            }
        }

        cout<<"items not found"<<endl;
        currstate=idlestate;
        return;

    }

    void pay(string method){
        if(amount==0 || currstate==idlestate){
            cout<<"product not selected..redirecting to home page";
            currstate=idlestate;
            return;
        }else{
            //calculate amount
            for(auto itr:items_selected){

                string curritem=itr.first;

                for(auto& i:items ){
                    if(i->name==curritem){
                        amount+=(i->price * itr.second);
                        i->stock-=itr.second;
                        
                    }
                    break;

                }


            }


            cout<<"Enter *card* or *coin* as payment method \n";
            if(method=="card"){
                cout<<"enter your card amount\n";
                int temp;
                cin>>temp;
                bool result=paywithcard->pay(amount,temp);
                if(!result){
                    //make refund
                    currstate=refundstate;
                    


                }else{
                    //on success reduce the item from stock as well
                    for(auto itr:items_selected){
                        string curr=itr.first;
                        for(auto i:items){
                            if(i->name==itr.first){
                                i->stock-=itr.second;
                            }
                            break;
                        }
                        

                    }
                    currstate=dispensestate;

                }
            }else if(method=="coin"){
                cout<<"enter your coins\n";
                int temp;
                cin>>temp;

                bool result=paywithcoins->pay(amount,temp);
                if(!result){
                    currstate=refundstate;
                }else{
                      for(auto itr:items_selected){
                        string curr=itr.first;
                        for(auto i:items){
                            if(i->name==itr.first){
                                i->stock-=itr.second;
                            }
                            break;
                        }
                        

                    }
                }

            }

        }

    }




};



int main(){


return 0;
}
