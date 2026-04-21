#include<iostream>
using namespace std;

template <class t>
class Distance{
    t inch;
    t ft;

    public : 
    Distance():ft(5),inch(5){}
    Distance(t ft,t inch){
        this->inch = inch;
        this->ft = ft;
    }

    void display() const {
        cout<<"<<<<<<<------->>>>>>>>>"<<endl;
        cout<<"Distance : "<<ft<<" feet , "<<inch<<" inches"<<endl;
        cout<<"<<<<<<<------->>>>>>>>>"<<endl;
    }

    Distance operator + (Distance &obj){
        Distance d;
        double tempDivide = (inch + obj.inch)/12;
        int tempInt = (int)(tempDivide);
        d.inch = (inch + obj.inch) % 12;
        d.ft = ft + obj.ft + tempInt;

        return d;
    }
};

int main(){
    Distance <int> d1(12,6);
    Distance <int> d2(7,9);

    Distance d3 = d1 + d2;
    d3.display();
}