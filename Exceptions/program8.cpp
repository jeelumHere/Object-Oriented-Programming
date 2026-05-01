/* 
1) Exception handling
2) Exception class
3) template classes
*/ 
#include<iostream>
#include<string>
using namespace std;

template <class t1,class t2>
class Exception{
    public : 
    t1 value;
    t2 location;

    Exception(t1 v,t2 loc): value(v),location(loc){}
};

template <class t>
class Coordinates{
    t x,y;

    public : 

    Coordinates():x(10),y(10){}
    Coordinates(t x1,t y1):x(x1),y(y1) // setting values using constructor
    {
        if(x<0 || y<0)
        {
            t val ;
            if(x<0){
                val = x;
            }
            else{
                val = y;
            }
            throw Exception<t,string>(val,"-ive value found in constructor.");
        }
        
    }  

    void input(int x1,int y1)  // setting values using a function.
    {
        x = x1;
        y = y1;
        if(x<0 || y<0)
        {
            t val ;
            if(x<0){
                val = x;
            }
            else{
                val = y;
            }
            throw Exception(val,"-ive value found in Input Function.");
        }
    }
};

int main(){
    try  // this will run by default
    {
        Coordinates <int>c1(-10.10101,20.3675);
    }
    catch(Exception<int,string> &e)
    {
        cout<<"Exception Found : "<<endl;
        cout<<"Location : "<<e.location<<endl;
        cout<<"-ive value : "<<e.value<<endl;
    }
    catch(...){
        cout<<"Default Exception."<<endl;
    }
}
