#include<iostream>
#include<fstream>
using namespace std;

int main(){
    // Working with arrays in file handling

    int arr[10];
    fstream file;
    file.open("file.txt",ios::out);  // ios::out writing into the file

    for(int n=0;n<10;n++)
    {
        arr[n] = n+1;
        file<<arr[n]<<endl;
    }

    file.close();

    file.open("file.txt",ios::in); // opening it again for reading this time;

    int num;
    if(!file){
        cout<<"file not found"<<endl;
        return 0;
    }
    while(file>>num){
        cout<<num;
    }
    
    file.close();
}