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
#include<cstring>
#include<fstream>
using namespace std;

class Person{


    public : 
     int contact;
    string name;
    void getData(){
        cout<<"Enter person name : "; cin>>name;
        cout<<"Enter contact number : "; cin>>contact;
    }
    void showData(){
        cout<<"Name : "<<name<<endl;
        cout<<"Contact : "<<contact<<endl;
    }

};

class Cow{
    Person p[7];
    static double price;
    static int pCount;
    public : 
    void book(){
        if(pCount>=0 && pCount<7){
            cout<<"Enter person no "<<pCount+1<<"details"<<endl;
            p[pCount].getData();
            pCount++;
        }
        else{
            cout<<"No booking available for this cow anymore"<<endl;
        }
    }

    void searchCowPerson(int cont){
        for(int n=0;n<pCount;n++){
            if(cont==p[n].contact){
                cout<<"Detail of the person.";
                p[n].showData();
            }
            else{
                cout<<"No detail found for that contact"<<endl;
            }
        }
    }

    void display(){
        cout<<"Cow share price : "<<price<<endl;
        for(int n=0;n<=pCount; n++){
            cout<<n+1<<" share holder data out of 7"<<endl;
            p[n].showData();
        }
    }
};

class Goat{
    Person p;
    double price;
    public : 
    void book(){
        cout<<"Enter goat price : ";
        cin>>price;
        cout<<"Enter goat owner details : "<<endl;
        p.getData();
    }

    void searchGoatPerson(int cont){
        if(cont==p.contact){
            cout<<"Goat owner detail : "<<endl;
            p.showData();
        }
    }

    void display(){
        cout<<"Goat price : "<<price<<endl;
        cout<<"goat owner detail : "<<endl;
        p.showData();
    }
};

double Cow::price = 25000;
int Cow::pCount = 0;

int main(){
    Goat g[100];
    int gCount = 0;
    int personOnCow = 0;
    Cow c[100];
    int cCount = 0;
    int cont;
    bool con = true;

    do{
        cout<<"For Goat booking press 1"<<endl;
        cout<<"For Cow sharing booking press 2"<<endl;
        cout<<"For display all Goat booking press 3"<<endl;
        cout<<"For display all Cow booking press 4"<<endl;
        cout<<"For Search Goat on Person’s contact basis press 5 "<<endl;
        cout<<"For Search Cow Share on Person’s contact basis press 6"<<endl;
        cout<<"For exit press 7."<<endl;
        cout<<"Enter choice  : "; int choice; cin>>choice;

        switch(choice){
            case 1: 
            g[gCount].book();
            gCount++;
            break;

            case 2:
            personOnCow++;
            if(personOnCow>=7){
                cCount++;
                personOnCow = 0;
            }
            c[cCount].book();
            break;

            case 3:
            for(int n=0;n<gCount;n++){
                g[n].display();
            }
            break;


            case 4:
            for(int n=0;n<=cCount; n++){
                c[n].display();
            }
            break;

            case 5:
            cout<<"Enter person contact .";  cin>>cont;
            for(int n=0;n<gCount; n++){
                g[n].searchGoatPerson(cont);
            }
            break;

            case 6: 
            cout<<"Enter person contact ."; cin>>cont;
            for(int n=0;n<cCount; n++){
                c[n].searchCowPerson(cont);
            }
            break;
            case 7 : 
            con = false;
            break;

            default: 
            cout<<"Enter ppropiae choice"<<endl;
        }
    }
    while(con);
}