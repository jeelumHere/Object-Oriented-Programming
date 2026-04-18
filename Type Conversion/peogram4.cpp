#include<iostream>
using namespace std;

class A{

    public : 
    int x;

    A(){
        x = 10;
    }
    A(int x){
        this->x = x;
    }

    void show() const {
        cout<<"value in class A : "<<x<<endl;
    }
};

class B{
    int y;

    public:
    B(A obj)
    {
        y = obj.x;
    }

    void show() const {
        cout<<"Value in class B : "<<y<<endl;
    }
};
int main(){
    A obj(200);
    B obj1 = obj;

    obj.show();
    obj1.show();
}