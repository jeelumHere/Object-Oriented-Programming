/* With reference to Eid-ul-Azha Qurbani booking system, One of the organization is managing Qurbani of Goats and sharing of Cows every year with the manual system. They are facing many issues so your assistance is required to automate the entire process in C++ based on the following rules:
1. They want to record the Person's data (Name and Contact) in a separate class.
2. They manage two type of classes/Qurbani’s i.e. Goat and Cow. Where only cow is shared in 7 Persons
3. The Goat price is different for every goat whereas Cow share price is fixed i.e. Rs.25000
4. There are total 100 Goats &100 Cows maximum and can be booked for Day1, 2 or 3 and time between 6am to 7pm
5. Inheritance is not allowed to use in your code.
6. The Program should be menu driven with the following Options:
    For Goat booking press 1 
    For Cow share booking press 2
    For Display all Goat bookings press 3 
    For Display all Cow bookings press 4
    For Search Goat on Person’s contact basis press 5 
    For Search Cow Share on Person’s contact basis press 6
    For Exit press 7 */

#include<iostream>
#include<string>
using namespace std;

class Person{
    int contact;
    string name;

    public :
    Person(int contact, string name){
        this->contact = contact;
        this->name = name;
    }
};

// Cow is ahred in 7 persons.
class Cow{
    const double price;
};

double cow::price = 25000;

class Goat{
};


int main(){
    do{
        cout<<"Press 1 to : "<<endl;
        cout<<"Press 2 to : "<<endl;
        cout<<"Press 3 to : "<<endl;
        cout<<"Press 4 to : "<<endl;
        cout<<"Press 5 to : "<<endl;
        cout<<"Press 6 to : "<<endl;
        cout<<"Press 7 to exit : "<<endl;
    }
}