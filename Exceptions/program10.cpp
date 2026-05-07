#include<iostream>
#include<string>
using namespace std;

class Exception{
    public : 

    int val;
    string location;

    Exception(){}
    Exception(int v,string loc): val(v),location(loc){}
};

class TakeNumber{
    int num;

    public : 
    TakeNumber(){}
    TakeNumber(int n):num(n){
        if(num<0){
            Exception e(num,"-ive Value found in Constructor");
            throw e;
        }
    }

    void getData(){
        cout<<"Enter number  : "; cin>>num;
        if(num<0){
            Exception e(num,"-ive value fund in getdata function");
            throw e;
        }
    }
};


int main(){
    try{
        TakeNumber tn1(40);
        TakeNumber tn2;
        tn2.getData();
    }
    catch(Exception& e){
        cout<<"-ive value : "<<e.val<<endl;
        cout<<"Location : "<<e.location<<endl;
    }
}