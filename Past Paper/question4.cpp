

#include<iostream>
using namespace std;

class FeetInches{
    double ft;
    double inch;

    public :
    FeetInches():ft(0),inch(0){} 
    FeetInches(double ft,double inch):ft(ft),inch(inch){}

    void show() const {
        cout<<"=================="<<endl;
        cout<<ft<<"'-"<<inch<<"''"<<endl;
        cout<<"=================="<<endl;
    }

    FeetInches operator = (const FeetInches& m)
    {
        inch  = m.inch + 1.25;
        ft = m.ft;
        return *this;
    }

};

int main(){
    FeetInches F1(9,3.5);
    FeetInches F2;
    FeetInches F3;
    F3 = F2 = F1;
    F1.show();
    F2.show();
    F3.show();

}
