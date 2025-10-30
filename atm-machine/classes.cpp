#include<bits/stdc++.h>
using namespace std;


class card{
    private:

    int pin;
    
    public:
    string name;

    card(string n, int pin){
        this->name=n;
        this->pin=pin;
    }

    int getpin(){
        return this->pin ;
    } 

};