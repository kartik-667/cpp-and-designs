#include<bits/stdc++.h>
using namespace std;

#include "classes.cpp"
//this contains the main atm machien class

enum class state{
    IDLE,
    HASCARD,
    PINVERIFIED,
    SELECTOPR,
    TRANSACTION
};

enum class transaction{
    DEPOSIT,
    WITHDRAW

};

class atm_machine{
    private:
    unordered_map<int,account*> accounts; // acc no , acc object
    card* currentcard;
    atm_inventory* inventory;
    state currstate;

    void resetATM(){
        currentcard=NULL;
        currstate=state::IDLE;
    }

    public:
    string machinename;

    atm_machine(string n){
        this->machinename=n;
        currentcard=NULL;
        inventory=new atm_inventory();
        this->currstate=state::IDLE;
    }

    double getBalance(){
        if(currstate == state::PINVERIFIED){
            return accounts[currentcard->getAccountno()]->showBalance();
        }else{
            cout<<"Please verify pin first";
            return 0.0;
        }

        
    }

    void addAccount(string name,int accno, double balance){
        if(currstate!= state::IDLE){
            cout<<"cant add account, atm under processing \n";
            return;
        }
        if(accounts.find(accno) == accounts.end()){
            accounts[accno]=new account(name,accno,balance);
        }
        return;


    }

    void insertCard(card* card){
        if(currstate != state::IDLE){
            cout<<"cant insert card \n";
            return;
        }
        int accno=card->getAccountno();
        if(accounts.find(accno) == accounts.end()){
            cout<<"account not found";
            return;
        }

        currentcard=card;
        currstate=state::HASCARD;
        return;
        

    }

    void enterPin(int pin){
        if(currstate!= state::HASCARD){
            cout<<"cant enter pin, card not found \n";
            return;
        }

        if(currentcard->authenticatePin(pin)){
            cout<<"pin verified successfully \n";
            currstate=state::PINVERIFIED;
        }
        return;

    }

    void selectOperation(transaction trans,double money){
        if(currstate != state::PINVERIFIED){
            cout<<"pin not verified \n";
            return;
        }

        if(trans == transaction::DEPOSIT){
            auto account=accounts[currentcard->getAccountno()];
            account->deposit(money);
            cout<<"transaction successful \n";
            
        }else if(trans == transaction::WITHDRAW){
            //withdraw cash
            auto account=accounts[currentcard->getAccountno()];
            if(money > account->showBalance()){
                cout<<"balance not sufficient \n";
                return;
            }
            bool res=inventory->perform_transaction(money);
            if(res){
                cout<<"transaction successful \n";
                account->processtransaction(money);
            }else{
                cout<<"transaction valid, invalid balance in acc/atm \n";
            }
        }else{
            cout<<"invalid operation, try again \n";
        }



    }

    void returnCard(){
        if(currstate == state::HASCARD || currstate == state::PINVERIFIED || currstate == state::SELECTOPR){
            cout<<"ejecting the card \n";
            resetATM();
        }else{
            cout<<"no card present to eject \n";
        }
    }

    








};