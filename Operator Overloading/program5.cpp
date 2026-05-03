// operator overloading wiht = (equals to operator)


// there is ann error in inches . Error of 1.25 inches.
#include<iostream>
using namespace std;


class FeetInches{
    double ft;
    double inch;

    public :
    FeetInches():ft(10),inch(10){}
    FeetInches(double ft,double inch):ft(ft),inch(inch){}

    void show(){
        cout<<ft<<"'-"<<inch<<"''"<<endl;
    }

    FeetInches operator = (const FeetInches& obj){
        inch = obj.inch + 1.25;
        ft = obj.ft;
        return *this;
    }
};

int main(){
    FeetInches F1(9,3.5);
    FeetInches F2;
    FeetInches F3;
    FeetInches F4;
    F4 = F3 = F2 = F1;
    F1.show();
    F2.show();
    F3.show();
    F4.show();
}

