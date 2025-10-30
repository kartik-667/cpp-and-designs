#include<bits/stdc++.h>
using namespace std;
#include "atm_service.cpp"


int main(){

    atm_machine* atm=new atm_machine("hdfc bank machine 1");

    atm->addAccount("kartik",1234,40000);
    atm->addAccount("rishabh",1235,50000);

    cout<<"starting atm demo \n";
    atm->insertCard(new card("kartik",1234,575934));

    atm->enterPin(575934);

    atm->selectOperation(transaction::WITHDRAW,5500);

    cout<<atm->getBalance()<<endl;

    atm->returnCard();
    



    

return 0;
}
