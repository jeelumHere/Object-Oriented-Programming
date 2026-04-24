#include<iostream>
#include<fstream>
using namespace std;


int main(){
    fstream file;
    file.open("file.txt",ios::in);

    char c;
    while(file.get(c)){
        cout<<c;
    }

    file.close();
}