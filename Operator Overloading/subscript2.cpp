// [] subscript operator overloading
// subscript opertor overloading dels with arrays.

#include<iostream>
using namespace std;

class Subscript{
    double arr[10];

    public :
    Subscript(){
        for(int n=0;n<10;n++){
            arr[n] = n * 10.12;
        }
    }

    void show(){
        for(int n=0;n<10;n++){
            cout<<arr[n]<<" , ";
        }
        cout<<endl;
    }

    // subscript operator overloading
    // reading
    double& operator [] (int index){
        if(index<0 || index>=10){
            cout<<"Array out of bound"<<endl;
        }
        return arr[index];
    }
};

int main(){
    Subscript s1;
    s1.show();
    s1[7] = 700;
    cout<<s1[7]<<endl;
    cout<<s1[8]<<endl;
    cout<<s1[9]<<endl;
}

