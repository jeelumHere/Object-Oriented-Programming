#include<iostream>
using namespace std;

int main(){
    float a1;
    int b1;
    a1 = 10.56;
    b1 = a1; // implicit cobversion to int data type

    float a2 = 12.856;
    int b2 = (int)(a2);  // explicit conversion to int data type


    float a3 = 123.456;
    int b3 = a3 ; // implicit conversion to int data type.

    cout<<b1<<" , "<<b2<<" , "<<b3<<endl;

}