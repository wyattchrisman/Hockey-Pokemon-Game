//
// Created by Wyatt Chrisman on 2/26/23.
//

#include "Player.cpp"
#include "Normal.cpp"
#include "Sniper.cpp"
#include "Fighter.cpp"
#include "Playmaker.cpp"
#include "Veteran.cpp"
#include <iostream>
using namespace std;

bool testPlayer();
bool testNormal();
bool testSniper();
bool testFighter();
bool testPlaymaker();
bool testVeteran();


int main() {
    srand(time(NULL));

    if(testPlayer()) {
        cout << "Passed all Player Cases" << endl;
    }
    if(testNormal()) {
        cout << "Passed all Normal Cases" << endl;
    }
    if(testSniper()) {
        cout << "Passed all Sniper Cases" << endl;
    }
    if(testFighter()) {
        cout << "Passed all Fighter Cases" << endl;
    }
    if(testPlaymaker()) {
        cout << "Passed all Playmaker Cases" << endl;
    }
    if(testVeteran()) {
        cout << "Passed all Veteran Cases" << endl;
    }
}

bool testPlayer() {
    bool passed = true;

    Normal normal(1,"Wayne Gretzky", 1961, "F", 1487,894, 1963, 2857, 577, 1, 1, 1);


    return passed;
}

bool testNormal(){
    bool passed = true;

    Normal normal(1,"Wayne Gretzky", 1961, "F", 1487,894, 1963, 2857, 577, 1, 1, 1);

    return passed;
}

bool testSniper(){
    bool passed = true;

    Sniper sniper(1,"Wayne Gretzky", 1961, "F", 1487,894, 1963, 2857, 577, 1, 1, 1);

    return passed;
}

bool testFighter(){
    bool passed = true;

    Fighter fighter(1,"Wayne Gretzky", 1961, "F", 1487,894, 1963, 2857, 577, 1, 1, 1);

    return passed;
}

bool testPlaymaker(){
    bool passed = true;

    Playmaker playmaker(1,"Wayne Gretzky", 1961, "F", 1487,894, 1963, 2857, 577, 1, 1, 1);

    return passed;
}

bool testVeteran(){
    bool passed = true;

    Veteran veteran(1,"Wayne Gretzky", 1961, "F", 1487,894, 1963, 2857, 577, 1, 1, 1);

    return passed;
}
