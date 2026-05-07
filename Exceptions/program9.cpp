// exception handling


#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class A{
    int a;
    double b;
    string c;

    public :
    void getInteger(){
        cout<<"Enter integer : "; cin>>a;
        if(a<0){
            throw a;  // exception throwing or throwing an error
        }
    }

    void getDouble(){
        cout<<"Enter double : "; cin>>b;
        if(b<0){
            throw b;  // exception throwing or throwing an error
        }
    }

    void getString(){
        cout<<"Enter string : "; cin>>c;
        if(c=="no"){
            throw c;  // exception throwing or throwing an error
        }
    }
};

int main(){
    // The code inside try will be executed on default
    // The code inside catch depends ipon the error wethrow
    try{
        A abc;
        abc.getInteger();
        abc.getDouble();
        abc.getString();
    }
    catch(int err){
        cout<<"Integer Exception Found : "<<err<<endl;
    }
    catch(double err){
        cout<<"Double Exception Found : "<<err<<endl;
    }
    catch(const char* err){
        cout<<"String exception found : "<<err<<endl;
    }
}
