#ifndef STUDENT_H
#define STUDENT_H

class Student {
private:
    int id;
    char name[50];
    float gpa;

public:
    Student();
    void input();
    void display() const;
    int getID() const;
};

// Declare functions so they are visible to main.cpp
void addStudent();
void viewStudents();
void searchStudent(int searchId);
void deleteStudent(int deleteId);

#endif
