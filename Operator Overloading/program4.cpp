#include<iostream>
using namespace std;

class Measurement{
    float inch;
    float ft;

    public : 
    Measurement():ft(10),inch(10){}
    Measurement(float ft,float inch):ft(ft),inch(inch){} 

    void  show() const{
        cout<<ft<<"'"<<inch<<"''"<<endl;
    }

    Measurement operator = (const Measurement& m){
        inch = m.inch + 1.25;
        ft = m.ft;
        return *this;
    }
};

int main(){
    Measurement m1(9,3.5);
    m1.show();
    Measurement m2;
    Measurement m3;
    Measurement m4;
    m4 = m3 = m2 = m1;
    m2.show();
    m3.show();
    m4.show();
}

