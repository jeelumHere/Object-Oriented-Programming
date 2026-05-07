// A user wants to buy tiles for a room. The size of a single tile is “1 feet * 10 inches”. 
// User is asked for the length and width of a room in feet’s and inches. If user 
// enter negative value for feet or inches, an exception is thrown with that negative 
// number and error string. How many tile will be required to cover the floor surface?
// Design an appropriate classes with required data members and member functions.  
#include<iostream>
#include<cstring>
using namespace std;

class Exception{
    public : 


    double val1;
    double val2;
    string err;

    Exception(string err,double val1,double val2):val1(val1),val2(val2),err(err){}
    Exception(string err,double val1):val1(val1),err(err){}
};

class Floor{
    double feetL;
    double feetW;
    int inchW;
    int inchL;

    public : 
    void getData(){
        cout<<"Enter Width in feet and inches for the room : "<<endl;
        cout<<"Feet : "; cin>>feetW;
        cout<<"Inches : ";cin>>inchW;
        while(inchW>12){
            cout<<"Enter again max(12) Inches : ";cin>>inchW;
        }
        cout<<"Enter Height in feet and inches for the room : "<<endl;
        cout<<"Feet : "; cin>>feetL;
        cout<<"Inches : ";cin>>inchL;
        while(inchL>12){
            cout<<"Enter again max(12) Inches : ";cin>>inchL;
        }
        if(feetW<0 && inchW<0){
            throw Exception("Value Enter for width is negative",feetW,inchW);
        }
        else if(feetW<0 || inchW<0){
            int negVal = feetW<0? feetW : inchW;
            throw Exception("Value Enter for width is negative",negVal);
        }
        if(feetL<0 && inchL<0){
            throw Exception("Value Enter for Length is negative",feetW,inchW);
        }
        else if(feetL<0 || inchL<0){
            int negVal = feetL<0? feetL : inchL;
            throw Exception("Value Enter for width is negative",negVal);
        }
    }

    void tileRequired(){
        int tiles;
        int inchT = inchW * inchL;
        double feetT = feetW * feetL;
        if(inchT>12){
            int inc = inchT/12;
            inchT %= 12;
            feetT += inc;
        }
        feetT = feetT + (inchT/12);
        tiles = feetT/1.1;
        cout<<"Tiles required are : "<<feetT<<endl;
    }
};

int main(){
    try{
        Floor f1;
        f1.getData();
        f1.tileRequired();
    }
    catch(Exception e){
        cout<<"Error : "<<e.err<<endl;
        cout<<"-ive Value : "<<e.val1<<endl;
    }
    catch(Exception e){
        cout<<"Error : "<<e.err<<endl;
        cout<<"-ive Value 01 : "<<e.val1<<endl;
        cout<<"-ive Value 02 : "<<e.val2<<endl;
    }
}
