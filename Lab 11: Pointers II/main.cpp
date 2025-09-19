//
//  main.cpp
//  COMSC-210 | Lab 11: Pointers II| Guo An Wang
//  IDE used: Xcode
//  Created by Guo An Wang on 9/18/25.
//

#include <iostream>
using namespace std;

const int numMembers = 3;

//Struct Gymperson records information about people who go to the gym
struct Gymperson {
    string name; //name of gym lifter
    int maxBench; //int for max bench press
    int *daysAtGym; //dynamic array that stores number of times going to gym a week
};

void inputGymperson(Gymperson *);
void outputGymperson(Gymperson *);

int main(int argc, const char * argv[]) {
    Gymperson *members = new Gymperson[numMembers];
    
    for (int i= 0 ; i<numMembers; i++) {
        //inputGymperson(&members[i]);
    }
    
    for (int i = 0; i<numMembers; i++) {
        //outGymperson(&members[i])
    }
}

void inputGymperson(Gymperson *member){
    static int number = 1;
    cout << "Input data for Gym member #" << number;
    cout << "\nName: ";
    getline(cin,member->name);
    cout << "\nMax Bench: ";
    cin >> member-> maxBench;
    
    member->daysAtGym = new int()
}

void outputGymperson(Gymperson *){
    
}
