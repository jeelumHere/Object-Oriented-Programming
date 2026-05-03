// subscript operator overloadig program 2

#include<iostream>
#include<algorithm>
using namespace std;

class Subscript{
    double arr[5];

    public :
    Subscript(){
        for(int n=0;n<5;n++)
        arr[n] = n * 10;
    }

    void show() const{
        for(int n=0;n<5;n++)
        cout<<arr[n]<<" , ";
        
        cout<<endl;
    }

    // read only
    const double& operator [] (int index) const {
        cout<<"Read only mode"<<endl;
        if(index<0 || index>=5)
        {cout<<"Index out of bound"<<endl;}
        return arr[index]; 
    }

    // read and write
    double& operator [] (int index){
        cout<<"Read and Write mode"<<endl;
        if(index<0 || index>=5)
        {cout<<"Index out of bound"<<endl;}
        return arr[index]; 
    }
};

int main(){
    Subscript obj1;
    obj1[2] = 7;
    cout<<obj1[2]<<endl;
    const Subscript obj2;
    cout<<obj2[2]<<endl;
    obj1.show();
}