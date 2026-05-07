// A.	Count how many students were marked Present on a specific date.
// B.	Update a student attendance record to “Present” incorrectly marked as "Absent". 



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

    void searchPresentStudent(Date &d1){
        int count = 0;
        fstream file;
        file.open("attendance.txt",ios::in | ios::binary);
        if(!file){
            cout<<"File does mot exist"<<endl;
            return;
        }
        else{
            Student obj;
            while(file.read(reinterpret_cast<char*>(&obj),sizeof(Student))){
                if(obj.d.day==d1.day && obj.d.month==d1.month && obj.d.year==d1.year){
                    if (strcmp(obj.attendance, "Present") == 0 || strcmp(obj.attendance, "present") == 0)
                    count++;
                }
            }
            if(count==0)
            cout<<"No student was present on : "<<d1.day<<":"<<d1.month<<":"<<d1.year<<endl;
            else{
            cout<<"Total Student present : "<<count<<endl;
            }
        }
    }

    void markedPresent() {
    fstream file("attendance.txt", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "File does not exist" << endl;
        return;
    }

    int sid;
    cout << "Enter student id: "; cin >> sid;

    Student obj;
    bool found = false;

    while (file.read(reinterpret_cast<char*>(&obj), sizeof(Student))) {
        if (sid == obj.id) {
            found = true;
            if (strcmp(obj.attendance, "Absent") == 0 || strcmp(obj.attendance, "absent") == 0) {
                streampos reposition = file.tellg();
                file.seekp(reposition - (streampos)sizeof(Student)); // Fixed: no int cast
                strcpy(obj.attendance, "Present");
                file.write(reinterpret_cast<char*>(&obj), sizeof(Student));
                cout << "Student marked Present." << endl;            // Fixed: feedback
            } else {
                cout << "Already marked Present." << endl;            // Fixed: feedback
            }
        }
    }
    if (!found) cout << "Student ID not found." << endl;             // Fixed: feedback

    file.close();
}
};

int main(){
    Student s1;
    Date bd;
    bd.day = 14;
    bd.month = 2;
    bd.year = 2007;
    s1.writeData();
    s1.markedPresent();
}