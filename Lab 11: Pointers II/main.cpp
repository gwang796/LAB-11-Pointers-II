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
    Gymperson *members = new Gymperson[numMembers];
    
    //looping to gather each members data
    for (int i= 0 ; i<numMembers; i++) {
        inputGymperson(&members[i]);
    }
    
    //looping to output each members data
    for (int i = 0; i<numMembers; i++) {
        outputGymperson(&members[i]);
    }
    
    //loops to free each members dynamic memory
    for (int i = 0; i < numMembers; i++) {
        delete[] members[i].daysAtGym;  // free each member’s dynamic array
    }

    delete[] members; // free the array of Gymperson struct
    return 0;
}

void inputGymperson(Gymperson *member){
    static int number = 1;
    cout << "Input data for Gym member #" << number;
    cout << "\nName: ";
    getline(cin,member->name);
    cout << "Max Bench: ";
    cin >> member-> maxBench;
    
    member->daysAtGym = new int[7]; // 7 days in a week
    cout << "Days went to the gym,  Enter in 1 for yes, and 0 for No" << endl;
    for (int i = 0; i < 7; i++) {
        cout << " Day " << (i+1) << ": ";
        cin >> member->daysAtGym[i];
    }
    
    cin.ignore();
    cout << endl;
    number++;
}

void outputGymperson(Gymperson *member){
    cout << "Gym member Summary: \n";
    cout << "Name: " << member->name << endl;
    cout << "Max Bench: " << member->maxBench << endl;
    for (int i = 0; i < 7; i++) {
        cout << "Day #" << (i+1) << ": ";
        if (member->daysAtGym[i]==1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
