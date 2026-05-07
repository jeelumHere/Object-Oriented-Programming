// Question #1:	(Approximate time to solve: 35min)			       (Covering CLO: 3,4)          12 Marks 
// You are required to develop a User Registration Validation System that takes input from the user, including a username, and password. Each of these fields needs its own checking rules, but they should all follow the same basic format. So, you should create a class called Validator that force other classes of handling validation using two functions: validate(string) and suggestFixes(string). The separate child classes for username, and password should define their own version of these functions. You must also add exception class in the Username class so that when an input is invalid, an error message is shown and a suggestion is provided to help the user fix the input.
// The validation rules for each field are as follows:
// Username
// Must start with a letter (A–Z or a–z) 
// Must be between 6 and 12 characters long
// Password
// Must be at least 8 characters long
// Must contain at least one special character (!@#$%^&*)

#include<iostream>
#include<cstring>
using namespace std;

class Exception{
    public : 
    string err;
    string fix;

    Exception(string err,string fix):err(err),fix(fix){}
};

class Validate{

    public : 
    void virtual validate() = 0;
    void virtual suggestFixes() = 0;

};

class Username : public Validate{
    string user;

    public :
    void  validate() override {
        cout<<"Enter User name : ";
        cin.ignore();
        getline(cin,user);
    }

    void  suggestFixes() override {
        int len = user.length();
        if(len<6)
        throw Exception("user name is less than 6 characters","It should be between 6 and 12 charcters");
        else if(len>12)
        throw Exception("user name is more than 12 characters","It should be between 6 and 12 charcters");
        else if((user[0]>= 'A' && user[0]<='Z') || user[0]>= 'a' && user[0]<='a')
        throw Exception("User name does not star with alphabet","Start the name with alphabet(a-z)");
        else
        cout<<"Username has benn validated"<<endl;
    }

};

class Password : public Validate{
    string pass;
    public :
    void  validate() override {
        cout<<"Enter User name : ";
        cin.ignore();
        getline(cin,pass);
    }

    void  suggestFixes() override {
        int len = pass.length();
        if(len<8)
        {
            throw Exception("password is less than 8 characters","It should be atleast charcters");
            return;
        }
            for(int n=0;n<pass.length(); n++){
                if((pass[n]=='!' || pass[n]=='@' || pass[n]=='#' || pass[n]=='$' || pass[n]=='%' || pass[n]=='^' || pass[n]=='&') && (pass.length()>=8))
                cout<<"PASSWORD IS SETTLED"<<endl;
                else
                throw Exception("it does not have a special charcter","should atleats contain one special character(!,@,#,$,%,^,&)");
            }
        }
        
    
};

int main(){
    Validate *ptr;
    Username u;
    Password p;
    
    do{
        cout<<"Press 1 to input username."<<endl;
        cout<<"Press 2 to input password."<<endl;
        cout<<"Press 3 to check username validation."<<endl;
        cout<<"Press 4 to check password validation."<<endl;
        int ch;
        cout<<"Enter choice : "; cin>>ch;
        switch(ch){
            case 1:
                ptr = &u;
                ptr->validate();
                break;

            case 2:
            ptr = &p;
            ptr->validate();
            break;

            case 3:
            try{
                ptr = &u;
                ptr->suggestFixes();
            }
            catch(Exception e){
                cout<<"Error: "<<e.err<<endl;
                cout<<"Suggextion : "<<e.fix<<endl;
            }
            break;

            case 4:
            try{
                ptr = &p;
                ptr->suggestFixes();
            }
            catch(Exception e){
                cout<<"Error: "<<e.err<<endl;
                cout<<"Suggextion : "<<e.fix<<endl;
            }
            break;
        }
    }
    while(true);
}