#include<iostream>
using namespace std;

// + operator overloading

class Complex{
    int real,img;
    
    public :
    Complex():real(10),img(10){}
    Complex(int real,int img)
    {
        this->real = real;
        this->img = img;
    }

    void show() const{
        cout<<real<<" , "<<img<<"i"<<endl;
    }

    Complex operator + (Complex obj){

        return Complex (real + obj.real, img + obj.img);
        // or 
        // Complex c ;
        // c.real = real + obj.real; c.img = img + obj.img;
        // return c;
    }
};

int main(){
    Complex c1(12,30),c2(10,5),c3(7,17);
    Complex c4 = c1 + c2 + c3;
    c4.show();
}