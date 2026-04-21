#include<iostream>
#include<string>
using namespace std;

class ExamPortal{
    public :
    string username;
    int password;
    void login(string username,int password){
        this->username = username;
        this->password = password;
    }
};

int main(){
    ExamPortal ep;
    ep.login("",9900);
    try{
        try{
            if(ep.username=="")
            throw "no username assighned";
            else if(ep.password<1000)
            throw -1;
        }
        catch(int err1){
            cout<<"Exception int : "<<err1<<endl;
        }
    }
    catch(const char* err){
        cout<<"Exception charcter : "<<err<<endl;
    }
}