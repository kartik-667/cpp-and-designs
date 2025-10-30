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

    int getpin(){
        return this->pin ;
    } 

};

class account{
    private:
    int accountno;
    double balance;
    public:
    string name;

    account(string n, int acc, double bal){
        this->accountno=acc;
        this->name=n;
        this->balance=bal;
    }

    
};

class atm_inventory{
    private:
    vector<int> notes={1000,500,100,50,10};
    unordered_map<int,int> freq; //store notes counts

    public:

    atm_inventory(){
        freq[100]=100;
        freq[500]=90;
        freq[100]=80;
        freq[50]=50;
        freq[10]=100;

    }
    //checks balance and perform transaction
    bool perform_transaction(double amount){
        double amt=amount;
        vector<pair<int,int>> temp;

        for(int i=0;i<notes.size();i++){
            if(notes[i] >=amt){
                int t=notes[i]/amt;
                if(t>0){
                    temp.push_back({notes[i],t});
                    amt=amt - (notes[i]*t);
                }

            }
        }

        if(amt>0){
            return false; //not sufficient balance
        }else{
            //dispense the cash
            for(auto itr:temp){
                freq[itr.first]-=itr.second;
            }
        }
        return true;



    }

};