#include "student.h"
#include <iostream>

using namespace std;

int main() {
    int choice, id;

    while (true) {
        cout << "\n--- Student Record Management ---\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                cout << "Enter ID to search: ";
                cin >> id;
                searchStudent(id);
                break;
            case 4:
                cout << "Enter ID to delete: ";
                cin >> id;
                deleteStudent(id);
                break;
            case 5:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
