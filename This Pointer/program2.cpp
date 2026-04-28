#include<iostream>
#include<string>
using namespace std;
// this pointer points to the data members and member function of it's class 
class student{
    int rollNo;
    string name;

    public : 
    student(int rollNo, string name){
        this->rollNo = rollNo;
        this->name  = name;
    }

    void show() {
        cout<<"Name : "<<name<<endl;
        cout<<"roll number : "<<rollNo<<endl;
    }
};

int main(){
    student s1(1309,"Syed sharjeel ahmed");
    s1.show();
}

