#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

// writing original then sorted data in the file.

int main(){
    int arr[10];
    cout<<"Enter data : "<<endl;
    for(int n=0;n<10;n++)
    cin>>arr[n];

    fstream file;
    file.open("file.txt",ios::out);

    file<<"Original Data"<<endl;
    for(int n=0;n<10;n++)
    file<<arr[n]<<" ";

    file<<endl;
    file<<"Sorted Data"<<endl;
    sort(arr , arr + 10);  // use algorith library for this function.

    for(int n=0;n<10;n++)
    file<<arr[n]<<" ";

    file<<endl;

    file.close();
}