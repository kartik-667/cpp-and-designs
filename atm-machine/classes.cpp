#include<bits/stdc++.h>
using namespace std;


class card{
    private:

    int pin;
    int accountno;
    
    public:
    string name;

    card(string n, int acc,int pin){
        this->name=n;
        this->pin=pin;
        this->accountno=acc;
    }

    int getAccountno(){
        return accountno;
    }

    bool authenticatePin(int pin){
        if(this->pin != pin){
            return false;
        }
        return true;

    }

    // int getpin(){
    //     return this->pin ;
    // } 



};

class account{
    private:
    int accountno;
    double balance;

    protected:
    
    
    public:
    string name;
    
    account(){
        
    }
    
    account(string n, int acc, double bal){
        this->accountno=acc;
        this->name=n;
        this->balance=bal;
    }
    
    
    double showBalance(){
        return balance;
    }
    
    void deposit(double money){
        this->balance+=money;
    }
    
    void processtransaction(double amount){
        this->balance-=amount;
    }


    
};

class atm_inventory : protected account{
    private:
    vector<int> notes={1000,500,100,50,10};
    unordered_map<int,int> freq; //store notes counts

    public:

    atm_inventory(){
        freq[1000]=100;
        freq[500]=90;
        freq[100]=80;
        freq[50]=50;
        freq[10]=100;

    }
    //checks balance and perform transaction
    // bool perform_transaction(double amount){
    //     double amt=amount;
    //     vector<pair<int,int>> temp;

    //     for(int i=0;i<notes.size();i++){
    //         if(notes[i] <=amt){
    //             int t=notes[i]/amt;
    //             if(t>0){
    //                 temp.push_back({notes[i],t});
    //                 amt=amt - (notes[i]*t);
    //             }

    //         }
    //     }

    //     if(amt>0){
    //         return false; //not sufficient balance
    //     }else{
    //         //dispense the cash
    //         for(auto itr:temp){
    //             freq[itr.first]-=itr.second;
    //         }
    //     }
    //     account::processtransaction(amount); //so this fnc is protected, so cant access outside the class also

    //     return true;



    // }

    bool perform_transaction(double amount) {
    double amt = amount;
    vector<pair<int,int>> temp;

    for (int note : notes) {
        int available = freq[note];
        int needed = amt / note;
        int use = min(needed, available);

        if (use > 0) {
            temp.push_back({note, use});
            amt -= note * use;
        }
    }

    if (amt > 0) {
        cout << " Cannot dispense exact amount with available notes.\n";
        return false;
    }

    // Deduct notes
    for (auto itr : temp){

        freq[itr.first] -= itr.second;
    }

    cout << " Dispensed: \n";
    for (auto itr : temp){
        cout << itr.first << " x " << itr.second << "\n";

    }


    // You can later integrate account deduction here
    // acc.processtransaction(amount);

    return true;
}


};