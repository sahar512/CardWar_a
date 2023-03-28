#include <string>
#pragma once 
using namespace std; 
class Player {
    public:
    int stackSize; 
    int cardsTaken; 
    string name; 
    
    Player(string name){
        this->stackSize=0; 
        this->cardsTaken=0; 
        this->name=name; 
    }
    int stacksize(); 
    int cardesTaken(); 
};
