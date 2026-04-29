#include<iostream>
using namespace std;
// template classes

template <class t>
class Calculate{
    t a;
    t b;

    public : 
    Calculate(t a1,t b1){
        a = a1;
        b = b1;
    }

    t average(){
        return (a+b)/2;
    }

    t sum(){
        return a+b;
    }

    t Difference(){
        return a-b;
    }

    t produuct(){
        return a*b;
    }
};

int main(){
    cout<<endl<<"Template classes using float or double"<<endl;
    Calculate <double> c1(10.10,5.5);
    cout<<"sum : "<<c1.sum()<<endl;
    cout<<"Product : "<<c1.produuct()<<endl;
    cout<<"average : "<<c1.average()<<endl;
    cout<<"difference : "<<c1.Difference()<<endl;


    cout<<endl<<"Template classes using integer"<<endl;
    Calculate <int> c2(10,5);
    cout<<"sum : "<<c2.sum()<<endl;
    cout<<"Product : "<<c2.produuct()<<endl;
    cout<<"average : "<<c2.average()<<endl;
    cout<<"difference : "<<c2.Difference()<<endl;
}
