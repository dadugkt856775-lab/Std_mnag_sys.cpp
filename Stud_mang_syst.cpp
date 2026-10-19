
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float marks;

    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
    }

    void display() {
        cout << "\nRoll Number: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks;
        cout << "\n----------------------\n";
    }
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int roll;
            string name;
            float marks;

            cout << "Enter roll number: ";
            cin >> roll;

            cout << "Enter name (one word): ";
            cin >> name;

            cout << "Enter marks: ";
            cin >> marks;

            students.emplace_back(roll, name, marks);
            cout << "Student added successfully!\n";
        }
        else if (choice == 2) {
            if (students.empty()) {
                cout << "No student records available.\n";
            } else {
                for (Student &s : students) {
                    s.display();
                }
            }
        }
        else if (choice == 3) {
            int roll;
            bool found = false;

            cout << "Enter roll number to search: ";
            cin >> roll;

            for (Student &s : students) {
                if (s.rollNo == roll) {
                    s.display();
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student not found!\n";
            }
        }
        else if (choice == 4) {
            cout << "Exiting program...\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
