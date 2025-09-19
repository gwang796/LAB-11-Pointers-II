//
//  main.cpp
//  COMSC-210 | Lab 11: Pointers II| Guo An Wang
//  IDE used: Xcode
//  Created by Guo An Wang on 9/18/25.
//  Program Use:
//  This program tracks some basic information of gym members.
//  For each member it tracks their name, max bench, and the days that they go to the gym.
//

#include <iostream>
using namespace std;

const int numMembers = 3;
const int DAYS_OF_WEEK = 7;
//Struct Gymperson records information about people who go to the gym
struct Gymperson {
    string name; //name of gym member
    int maxBench; //max bench press for gym member
    int *daysAtGym; //dynamic array that stores the days a member goes to the gym a week
};

//function inputGymperson gathers information about members
//arguments: pointer to Gymperson struct
//return: none
void inputGymperson(Gymperson *);
//function outputGymperson gathers information about members
//arguments: pointer to Gymperson struct
//return: none
void outputGymperson(Gymperson *);

int main(int argc, const char * argv[]) {
    //create dynamic array of Gymperson struct with size numMembers
    //allows us to track multiple gym members
    Gymperson *members = new Gymperson[numMembers];
    
    //looping to gather each members data
    for (int i= 0 ; i<numMembers; i++) {
        inputGymperson(&members[i]); // passes adress of each Gymperson
    }
    
    //looping to output each members data
    for (int i = 0; i<numMembers; i++) {
        outputGymperson(&members[i]);  // passes adress of each Gymperson
    }
    
    //clean up memory
    //loops to free each members dynamic memory
    for (int i = 0; i < numMembers; i++) {
        delete[] members[i].daysAtGym;
    }

    //deletes dynamic array of Gymperson struct
    delete[] members;
    return 0;
}

void inputGymperson(Gymperson *member){
    static int number = 1; //static int number makes it so the value of number doesn't change between loops
    cout << "Input data for Gym member #" << number;
    cout << "\nName: ";
    getline(cin,member->name); //asks for member name
    cout << "Max Bench: ";
    cin >> member-> maxBench; //asks for member bench
    
    // dynamic array of size 7(for all days of the weeks)
    member->daysAtGym = new int[DAYS_OF_WEEK];
    cout << "Days went to the gym,  Enter in 1 for yes, and 0 for No" << endl;
    for (int i = 0; i < DAYS_OF_WEEK; i++) {
        cout << " Day " << (i+1) << ": ";
        cin >> member->daysAtGym[i];
    }
    //clear buffer so getline works properly in loop
    cin.ignore();
    cout << endl;
    number++; //number increase after each time function is called
}

void outputGymperson(Gymperson *member){
    cout << "Gym member Summary: \n";
    cout << "Name: " << member->name << endl;
    cout << "Max Bench: " << member->maxBench << "lbs" << endl;
    //loop through each day of the week to print yes/no depending on if member went to the gym
    for (int i = 0; i < DAYS_OF_WEEK; i++) {
        cout << "Day #" << (i+1) << ": ";
        //conditional to choose what to print
        if (member->daysAtGym[i]==1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
