
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {

    int id;
    string name;
    int age;
    double grade;

public:

    Student(int id, string name, int age, double grade) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->grade = grade;
    }

    void studentDetails() {
        cout<< "ID: " << getid() << endl;
        cout<< "Name: " << getname() << endl;
        cout<< "Age: " << getage() << endl;
        cout<< "Grade: " << getgrade() << endl;
    }

    int getid() {
        return id;
    }

    string getname() {
        return name;
    }

    int getage() {
        return age;
    }

    double getgrade() {
        return grade;
    }
};

class StudentManager{

    vector<Student> students;

public: 

    void addStudent(Student s) {
        students.push_back(s);
    }

    void displayStudents() {
        
        for(Student &student: students) {
            student.studentDetails();
        }
    }

    void searchStudent(int id) {

        bool isFound = false;

        for(Student &student : students) {

            if(id == student.getid()) {
                isFound = true;
                student.studentDetails();
                break;
            }
        }

        if (!isFound) {
            cout<< "Student not found" << endl;
        }
    }

    
};

int main() {

    Student s1(01, "Humayun", 21, 92.0);
    Student s2(02, "Usman", 20, 91.5);

    StudentManager manager;

    manager.addStudent(s1);
    manager.addStudent(s2);

    // manager.displayStudents();
    manager.searchStudent(2);
    
}

