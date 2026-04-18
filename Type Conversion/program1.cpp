#include<iostream>
using namespace std;

int main(){
    int a1;
    float b1;
    a1 = 10;
    b1 = (float)(a1); // explicit cobversion to float data type

    float a2 = 12.856;
    int b2 = (int)(a2);  // explicit conversion to int data type


    float a3 = 123.456;
    int b3 = a3 ; // implicit conversion to float data type.

    cout<<b1<<" , "<<b2<<" , "<<b3<<endl;

}