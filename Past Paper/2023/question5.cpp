// We have two classes, class1 and class2, class1 can access the private data member x 
// of class2, whereas class2 can’t access private data of class1. Support this statement
//  with a valid c++ code.  

#include<iostream>
using namespace std;


class Class2;

class Class1{
    int x,y;

    public :
    Class1():x(10),y(20){}
    Class1(int x,int y):x(x),y(y){}
    friend class Class2;

};

class Class2{

    public : 
    void showDetails(){
        Class1 obj(20,54);
        cout<<"Value of x : "<<obj.x<<endl;
        cout<<"Value of y : "<<obj.y<<endl;
    }
};

int main(){
    Class2 obj;
    obj.showDetails();
}