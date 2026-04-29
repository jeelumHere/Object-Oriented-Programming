#include<iostream>
using namespace std;

template <class t>
class Coordinates{
    
    public : 
    t x;
    t y;
    Coordinates():x(10),y(10){}
    Coordinates(t x, t y){
        this->x = x;
        this->y = y;

        if(this->x<0 || this->y<0)
            throw "-ive value found in Constructor.";
    }

    void input(t x, t y){
        this->x = x;
        this->y = y;

        if(this->x<0 || this->y<0)
            throw "-ive value found in input function.";
    }
};

int main(){
    try{
        Coordinates <int>c2;
        c2.input(20,-40);
        Coordinates <int>c1(10,-20);
    }
    catch(const char* err){
        cout<<"Exception Found : "<<err<<endl;
    }
    catch(...){
        cout<<"Default exception running."<<endl;
    }
}