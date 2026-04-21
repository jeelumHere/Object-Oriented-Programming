#include<iostream>
using namespace std;

template <class t>
class Array{
    t array[5];
    int top;
    public : 

    Array(){
        top = -1;
    }
    int giveTop(){
        return top;
    }

    void push(t val){
        top++;
        top>=0 && top<5 ? array[top] = val : throw "Array is full";
    }

    void pop(){
        if(top>=0 && top<5)
        top--;
        else
        throw "nothing to remove";
    }

    void display(){
        if(top>=0 && top<5) 
        {
            for(int n=0; n<=top;n++){
            cout<<"Value at index "<<n<<" is "<<array[n]<<endl;
            } 
            throw array;
        }
        else{
            throw "No assighned values";
        }
    }
};

int main(){
    Array <int> a1;
    try{
        a1.push(10);
        a1.push(20);
        a1.push(30);
        a1.push(40);
        a1.display();
    }
    catch(const char* err){
        cout<<"exception : "<<err<<endl;
    }
    catch(int arr[]){
        int count = a1.giveTop();
        cout<<"Array values ";
        for(int n=0;n<=count;n++){
            cout<<"  "<<arr[n];
        }
    }
    catch(...){
        cout<<"Exception : Default catch executed."<<endl;
    }
}
