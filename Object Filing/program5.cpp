#include<iostream>
#include<string>
#include<fstream>
using namespace std;
// reading a whole line at once from a file.
int main(){
    ofstream file;
    file.open("file.txt");

    file<<"My self syed sharjeel ahmed."<<endl;
    file<<"I am a computer science student."<<endl;
    file<<"Currently I am practicing File handling in oops."<<endl;

    file.close();

    ifstream fileRead;
    fileRead.open("file.txt");
    
    string line;
    while(getline(fileRead,line))
        cout<<line<<endl;

    file.close();
}
