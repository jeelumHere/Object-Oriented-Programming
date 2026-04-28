#include<iostream>
using namespace std;
// template function
class Calculator{
    // int a,b;

    public : 
    // Calculator(int a,int b){
    //     this->a = a;   
    //     this->b = b;   
    // }

    template <class t>
    t Add(t a, t b){
        return a+b;
    }
    
};

int main(){
    Calculator c1;
    cout<<"addition : "<<c1.Add(10.5,11.5)<<endl;
    cout<<"addition : "<<c1.Add(10,11);
}
