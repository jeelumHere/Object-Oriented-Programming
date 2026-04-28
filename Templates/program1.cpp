#include<iostream>
using namespace std;

class person{

public:
     void virtual show(){
        cout << "I show person data members" << endl;
    }
};

class student : public person{
public:
    void  show(){
        cout << "I show student data members." << endl;
    }
};

class employee : public person{
public:
    void  show(){
        cout << "I show employee data members." << endl;
    }
};

int main(){
    person *ptr;
    employee e;
    ptr = &e;
    ptr->show();
}
