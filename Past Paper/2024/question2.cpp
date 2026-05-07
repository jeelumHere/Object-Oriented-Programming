// Question #02 :  You are required to design a class to represent a Point with x and y coordinates. The coordinates can be initialized through the constructor or set via an input function. However, the coordinates should never be negative. If a negative value is provided, the system should throw an exception (using exception class), indicating where the negative value was given (either in the constructor or in the input function) and what the negative value was. Complete program including main function is required.

#include<iostream>
using namespace std;

class Exception{

    public : 

    double value;
    string err;
    string location;

    Exception(double value,string err, string location):value(value),err(err),location(location){}

};

template <class t>
class Coordinates{
    t x,y;

    public : 
    Coordinates():x(10),y(10){}

    Coordinates(t x, t y):x(x),y(y){
        if(x<0 || y<0){
            int a;
            x<0? a = x : a = y;
            throw Exception(a,"-ive value found","Constructor");
        }
    }

    void input(t x1, t y1){
        x = x1;
        y = y1;
        if(x<0 || y<0){
            t a;
            a = x<0? x : y;
            throw Exception(a,"-ive value found","input function.");
        }
    }

};

int main(){
    try{
        Coordinates <float> c1;
        c1.input(-10.45,-45.87);
    }
    catch(Exception& e){
        cout<<"Value : "<<e.value<<endl;
        cout<<"Error : "<<e.err<<endl;
        cout<<"Location : "<<e.location<<endl;
    }
}
