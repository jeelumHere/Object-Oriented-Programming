#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;

// sorting already presenddata in the file 
int main(){
    int arr[10];

    fstream file;
    file.open("file.txt",ios::in); // raeding the file

    if(!file){
        cout<<"File not found"<<endl;
        return 0;
    }
    int n=0;
    while(n<10 && file>>arr[n])
    n++;
    file.close();
    file.open("file.txt",ios::out); // opening file for writing into it.

    sort(arr , arr + n);
    file<<"Sorted Array : "<<endl;
    for(int i=0;i<n;i++){
        file<<arr[i]<<" ";
    }

    file.close();

}