#include<iostream>
#include<string>
using namespace std;

class String{
    string name;

    public :
    void setName(){
        cout<<"Enter name : ";getline(cin,name);
    }
    char getName(int index)
    {
        if(index>=0 && index<name.length())
        return name[index];
        else{
            return '0';
        }
    }
};

int main(){
    String s1;
    s1.setName();
    cout<<"Chracter : " <<s1.getName(5);
}