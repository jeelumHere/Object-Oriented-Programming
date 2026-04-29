// Exception try and catch
// try woh code jo run ho ga hi hoga
// catch woh code jo k error ki base prr run ho ga

// There are mutiple catches.
// Catch is run on the basis of data type thrown as an error

//REason to use exceptions : To control run time error
#include<iostream>
using namespace std;


class Distance{
    int meters;
    double inch;

    public : 
    Distance(int m){
        meters = m;

        if(meters<0)
        throw meters;  // since meters is an integer and we are throwing it as an error so catch with int data type will run


        // if(meters<0){
        //     cout<<"Distnac entered is negative"<<endl;
        // }
        // else{
        //     cout<<"Distance is positive or zero."<<endl;
        // }
    }

    Distance(double i){
        inch = i;
        if(inch<0)
        throw inch;  // since inch is double data type and we are throwing it as an error the catch with double parameters will receive it and execue it.
    }
};

int main(){

    try{
       // this code will be executed on default mode
        Distance d1(-10.567);
    }
    catch(int err){
        // ths code inside catch will run on error bases
        cout<<"Exception Integer : Negative value found : "<<err<<endl;
    }

    catch(double err){
        cout<<"Exception double : Negative value found : "<<err<<endl;
    }

    catch(...){
        cout<<"No error found."<<endl;
    }
}
