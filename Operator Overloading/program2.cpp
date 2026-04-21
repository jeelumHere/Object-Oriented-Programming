#include<iostream>
using namespace std;

template <class t>
class Complex{
    t real;
    t img;

    public : 

    Complex():img(10),real(10){}
    Complex(t real,t img){
        this->real = real;
        this->img = img;
    }

    void display() const
    {
        cout<<"complex number : "<<real<< " + "<<img<<"i"<<endl;
    }

    Complex operator + (Complex &c1){
        return Complex(real + c1.real , img + c1.img) ; 
    }
    Complex operator - (Complex &c1){
        return Complex(real - c1.real , img - c1.img) ; 
    }

};

int main(){
    Complex <int> c1(12,10);
    Complex <int> c2;
    Complex <int> c3;
    c3 = c1 + c2;
    c3.display();
    Complex <int> c4 = c1 - c2;
    c4.display();
}
