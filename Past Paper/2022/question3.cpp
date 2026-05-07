// You are going to develop an application for arid university, consider the following scenario and
//  write the necessary code to implement the scenario:		   
// A university offers degrees to students. 
// The university consists of one or more departments. 
// Each degree is administered by a single department.
// Each student is studying towards a single degree. 
// Each degree requires one to 20 courses. 
// A student enrolls in 1-6 courses (per semester) 
// A course can be either graduate or undergraduate, but not both.

#include<iostream>
#include<cstring>
#include<string>
using namespace std;

// ✅ Correct order: Course → Department → Degree → Student → University

class Course {
public:
    char name[20];
    char courseType[50];

    void selectCourse() {
        cout << "Enter course name: "; cin >> name;
        cout << "Press 1 for Undergraduate, 2 for Graduate: ";
        int ch; cin >> ch;
        if (ch == 1) strcpy(courseType, "Undergraduate");
        else if (ch == 2) strcpy(courseType, "Graduate");
        else cout << "Invalid choice" << endl;
    }
};

class Department {
public:
    char name[50];  // ✅ char array instead of string for consistency
};

class Degree {
public:
    char name[20];
    Department dpt;
    Course crs[20];
    int countd;  // tracks if department is assigned
    int countc;  // tracks course count

    Degree() : countd(0), countc(0) {}

    void addDepartment() {
        if (countd == 0) {  // ✅ Fixed: was using undeclared 'count'
            cout << "Enter Department of degree: "; cin >> dpt.name;
            countd++;
        } else {
            cout << "The degree already has department: " << dpt.name << endl;
        }
    }

    void addCourse() {
        if (countc < 20) {
            cout << "Enter course no " << countc + 1 << ": ";  // ✅ Fixed: was 'count'
            cin >> crs[countc].name;
            countc++;
        } else {
            cout << "Degree already has 20 courses" << endl;
        }
    }
};

class Student {
public:
    char name[20];
    int count;
    Degree d1;
    Course crs[6];

    Student() : count(0) {}

    void selectDegree() {
        cout << "Enter degree name to enroll: "; cin >> d1.name;
    }

    void selectCourses() {
        if (count < 6) {
            cout << "Enter course " << count + 1 << " out of 6: ";
            cin >> crs[count].name;  // ✅ Fixed: was crs.name[count]
            count++;
        } else {
            cout << "6 courses already enrolled for this semester" << endl;
        }
    }
};

class University {
public:
    Student s[100];      // ✅ Fixed: was Student s[] — invalid
    Department dpt[3];
    int deptCount;
    int studentCount;

    University() : deptCount(0), studentCount(0) {}

    void addDepartment() {
        if (deptCount < 3) {
            cout << "Enter Department: ";
            cin >> dpt[deptCount].name;  // ✅ Fixed: was dpt[n] — n undefined
            deptCount++;
        } else {
            cout << "University has reached department limit" << endl;
        }
    }

    void addStudent() {
        if (studentCount < 100) {
            cout << "Enter Student name: ";
            cin >> s[studentCount].name;
            studentCount++;
        } else {
            cout << "University is full" << endl;
        }
    }
};

int main() {
    University u;
    u.addDepartment();
    u.addStudent();
    return 0;
}