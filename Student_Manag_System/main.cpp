
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

    void setName(string n) {
        this->name = n;
    }

    int getage() {
        return age;
    }

    void setAge(int a) {
        this->age = a;
    }

    double getgrade() {
        return grade;
    }

    void setGrade(double g) {
        this->grade = g;
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

    void deleteStudent(int id) {

        bool isFound = false;
        for(auto it = students.begin(); it != students.end(); ++it) {
            
            if(id == it->getid()) {
                isFound = true;
                it = students.erase(it);
                cout<< "Student deleted" << endl;
                break;
            }

        }
        if(!isFound) {
            cout << "Student not found" <<endl;
        }
    }


    void updateDetails(int id) {

        bool isFound = false;

        for(Student &student: students) {

            if(id == student.getid()) {

                isFound = true;
                string newName;
                int newAge;
                double newGrade;

                cout << "Enter New Name: " ;
                getline(cin, newName);
                student.setName(newName);
                cout << "Enter New Age: ";
                cin >> newAge;
                student.setAge(newAge);
                cout << "Enter New Grade: ";
                cin >> newGrade;
                student.setGrade(newGrade);

                cout<< "Student Updated!"<< endl;
                break;
            }
        }

        if(!isFound) {
            cout<< "Student not Found"<< endl;
        }
    }


};

int main() {

    Student s1(01, "Humayun", 21, 92.0);
    Student s2(02, "Usman", 20, 91.5);

    StudentManager manager;

    manager.addStudent(s1);
    manager.addStudent(s2);

    manager.displayStudents();
    // manager.searchStudent(2);
    // manager.deleteStudent(1);
    manager.updateDetails(2);
    manager.displayStudents();
}

