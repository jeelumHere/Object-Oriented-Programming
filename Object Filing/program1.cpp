#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // first open the file
    // then use the file
    fstream file; 

    file.open("Object_Filing.txt",ios::out); // if this filw won't be present it will create and open the file

    file<<"This is a object filing file smjh gye!!"<<endl;

    file.close(); // file is closed to lock the resources of the file.
}