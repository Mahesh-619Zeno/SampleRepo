#include "student.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Student::Student() {
    id = 0;
    strcpy(name, "");
    gpa = 0.0;
}

void Student::input() {
    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(name, 50);
    cout << "Enter GPA: ";
    cin >> gpa;
}

void Student::display() const {
    cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
}

int Student::getID() const {
    return id;
}

void addStudent() {
    Student s;
    s.input();

    ofstream file("students.dat", ios::binary | ios::app);
    file.write(reinterpret_cast<char*>(&s), sizeof(s));
    file.close();
    cout << "Student added.\n";
}

void viewStudents() {
    Student s;
    ifstream file("students.dat", ios::binary);
    if (!file) {
        cout << "No records found.\n";
        return;
    }
    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        s.display();
    }
    file.close();
}

void searchStudent(int searchId) {
    Student s;
    bool found = false;
    ifstream file("students.dat", ios::binary);
    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.getID() == searchId) {
            s.display();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Student not found.\n";
    file.close();
}

void deleteStudent(int deleteId) {
    Student s;
    ifstream inFile("students.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary);

    bool deleted = false;

    while (inFile.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.getID() != deleteId) {
            outFile.write(reinterpret_cast<char*>(&s), sizeof(s));
        } else {
            deleted = true;
        }
    }

    inFile.close();
    outFile.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (deleted)
        cout << "Student deleted.\n";
    else
        cout << "Student ID not found.\n";
}
