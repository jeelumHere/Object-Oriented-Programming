#include<iostream>
using namespace std;

class A{

    public : 
    int x,y,z;

    A(int x,int y,int z):x(x),y(y),z(z){}

    void const Show(){
        cout<<"Value 1 : "<<x<<endl;
        cout<<"Value 2 : "<<y<<endl;
        cout<<"Value 3 : "<<z<<endl;
    }


};

class B{
    int x,y,z;

    public : 
    B(A obj):x(obj.x),y(obj.y),z(obj.z){}

    void const Show(){
        cout<<"Value 1 : "<<x<<endl;
        cout<<"Value 2 : "<<y<<endl;
        cout<<"Value 3 : "<<z<<endl;
    }

    
};

int main()
{
    A a1(10,20,30);
    B b1 = a1;
    a1.Show();
    b1.Show();
}