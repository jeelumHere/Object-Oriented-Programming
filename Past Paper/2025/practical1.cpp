// Marks You are building a Student Attendance System that stores attendance records 
// in a text file called attendance.txt.
// Each line of the file follows this format and store data in the form of object :
// StudentID, Name, Date, Present/Absent
// Assuming class is already there, you are only required to define following C++ 
// functions within class:
// A.	Add a new attendance record to attendance.txt without deleting the existing data.
// B.	Read and display all records for a given date (format: 01-06-2025) received in function parameter

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

class Student{
    int id;
    char name[20];
    Date d;
    char attendance[20];

    public :
    void getData(){
        cout<<"Enter student id : "; cin>>id;
        cout<<"Enter student name : ";cin>>name;
        cout<<"Enter Date : "<<endl;
        cout<<"Day : ";cin>>d.day;
        cout<<"Month : ";cin>>d.month;
        cout<<"Year : ";cin>>d.year;
        cout<<"Enter Present/Absent : ";cin>>attendance;
    }

    void showData(){
        cout<<"Id     : "<<id<<endl;
        cout<<"Name   : "<<name<<endl;
        cout<<"Date   : "<<d.day<<":"<<d.month<<":"<<d.year<<endl;
        cout<<"Attend : "<<attendance<<endl;
    }

    void writeData(){
        fstream file;
        file.open("attendance.txt",ios::out | ios::app | ios::binary);
        if(!file){
            cout<<"File does not exist"<<endl;
            return;
        }
        else{
            Student obj;
            obj.getData();
            file.write(reinterpret_cast<char*>(&obj),sizeof(Student));
            obj.showData();
        }
        file.close();
    }

    void searchData(Date &d1){
        fstream file;
        file.open("attendance.txt",ios::binary | ios::in);
        if(!file)
        {
            cout<<"File does not exist"<<endl;
            return ;
        }
        else{
            Student obj;
            while(file.read(reinterpret_cast<char*>(&obj),sizeof(Student))){
                if(obj.d.day==d1.day && obj.d.month==d1.month && obj.d.year==d1.year){
                    obj.showData();
                }
                else{
                    cout<<"Data not found"<<endl;
                }
            }
        } 
        file.close();
    }
};

int main(){
    Student s1;
    Date bd;
    bd.day = 14;
    bd.month = 2;
    bd.year = 2007;
    s1.searchData(bd);
}