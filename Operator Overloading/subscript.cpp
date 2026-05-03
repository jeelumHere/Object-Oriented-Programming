// subscript overloading

#include<iostream>
using namespace std;

class SafeArray{
    int arr[5];

    public : 
    SafeArray(){
        for(int n=0;n<5;n++)
        arr[n] = n * 10;
    }

    void show() const{
        cout<<"Array Display."<<endl;

        for(int n=0;n<5;n++)
        cout<<arr[n]<<" , ";

        cout<<endl;
    }

    int operator [] (int index){
        if(index<0 || index>=5){
            cout<<"Array out of bounds"<<endl;
        }
        return arr[index];
    }

};

int main(){
    SafeArray obj1;
    for(int n=0;n<5;n++)
    cout<<obj1[n]<<" , ";
    
    cout<<endl;
}