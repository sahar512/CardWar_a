#include "doctest.h"
#include "sources/card.hpp"
#include "sources/game.hpp"
#include "sources/player.hpp"
using namespace std; 
using namespace ariel; 

TEST_CASE("test 0 " ){
    //check player constructor 
    Player p1("p1"); 
    Player p2("p2"); 
    CHECK(p1.name=="p1"); 
    CHECK(p2.name=="p2");
    CHECK(p1.cardesTaken()==0);
    CHECK(p2.cardesTaken()==0); 
    CHECK(p1.stacksize()==0); 
    CHECK(p2.stacksize()==0); 
}
TEST_CASE("test1"){
    //check game constructor 
    Player p1("p1");
    Player p2("p2"); 
    Game game(p1,p2); 
    CHECK(p1.cardesTaken()==0); 
    CHECK(p2.cardesTaken()==0); 
    CHECK(p1.stacksize()==26); 
    CHECK(p2.stacksize()==26); 
}
TEST_CASE("test2"){
    //play one turn (both players have cards less than 26)
    Player p1("p1");
    Player p2("p2"); 
    Game game(p1,p2);
    CHECK(p1.stacksize()>26);
    CHECK(p2.stacksize()>26); 
}
TEST_CASE("test3"){
    // 6 turns have played 
    Player p1("p1");
    Player p2("p2"); 
    Game game(p1,p2);
    for (int i=0;i<6;i++) 
    game.playTurn();
    game.printLastTurn(); 
    CHECK(p1.cardesTaken()==0); 
    CHECK(p2.cardesTaken()==0); 
    CHECK(p1.stacksize()==20); 
    CHECK(p2.stacksize()==20); 
}
TEST_CASE("test4"){
    //end game
    Player p1("p1");
    Player p2("p2"); 
    Game game(p1,p2);
    game.playAll(); 
    CHECK(p1.stacksize()==0); 
    CHECK(p2.stacksize()==0); 
}
TEST_CASE("test5"){
    // p1 wins all the time  
    Player p1("p1");
    Player p2("p2"); 
    Game game(p1,p2);
    game.playAll(); 
    CHECK(p1.cardesTaken()==26); 
    CHECK(p2.cardesTaken()==0); 
}
TEST_CASE("test6"){
    //p2 won just one turn 
    Player p1("p1");
    Player p2("p2"); 
    Game game(p1,p2);
    game.playAll(); 
    CHECK(p1.cardesTaken()==24); 
    CHECK(p2.cardesTaken()==2); 
}