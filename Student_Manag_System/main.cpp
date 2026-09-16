
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
        cout<< "Student Added successfully!" << endl;
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
                cin.ignore();
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

    
    cout<< "*****Welcome to Student Management System*****" << endl;

        StudentManager manager;
        
        while(true) {

            cout<< "1. Add Student \n2. Display Students \n3. Search Student \n4. Update Student \n5. Delete Student \n6. Exit \n";
            int choice;
            cout << "Enter choice: " << endl;
            cin >> choice;
            int id;

            switch (choice) {

                case 1: {

                    string name;
                    int age;
                    double grade;

                    cout << "Enter id: "<< endl;
                    cin >> id;

                    cin.ignore();

                    cout << "Enter Name: "<< endl;
                    getline(cin, name);

                    cout << "Enter Age: "<< endl;
                    cin >> age;

                    cout << "Enter grade: "<< endl;
                    cin >> grade;

                    Student s(id, name, age, grade);
                    manager.addStudent(s);
                    
                    break;
                }

                case 2:
                    manager.displayStudents();
                    break;
                
                case 3:
                    cout << "Enter id: " << endl;
                    cin >> id;
                    manager.searchStudent(id);
                    break;

                case 4:
                    cout << "Enter id: "<< endl;
                    cin >> id;
                    manager.updateDetails(id);
                    break;

                case 5:
                    cout << "Enter id: " << endl;
                    cin >> id;
                    manager.deleteStudent(id);
                    break;

                case 6:
                    cout << "Program Ended" << endl;
                    return 0;
                    
                default:
                    cout<< "Invalid input" << endl;
            }   


    }
}

