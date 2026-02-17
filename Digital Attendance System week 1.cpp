
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Student class
class Student {
public:
    string name;
    string indexNumber;

    // Constructor
    Student(string n, string i) {
        name = n;
        indexNumber = i;
    }

    // Display student
    void display() {
        cout << "Name: " << name << " | Index Number: " << indexNumber << endl;
    }
};

// Global student list
vector<Student> students;

// Function to add student
void addStudent() {
    string name, index;

    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter index number: ";
    cin >> index;

    students.push_back(Student(name, index));
    cout << "Student added successfully!\n";
}

// Function to view students
void viewStudents() {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (int i = 0; i < students.size(); i++) {
        cout << i + 1 << ". ";
        students[i].display();
    }
}

// Save students to file
void saveToFile() {
    ofstream file("students.txt");

    for (auto &s : students) {
        file << s.name << "," << s.indexNumber << endl;
    }

    file.close();
}

// Load students from file
void loadFromFile() {
    ifstream file("students.txt");

    string line;
    while (getline(file, line)) {
        int comma = line.find(",");
        string name = line.substr(0, comma);
        string index = line.substr(comma + 1);

        students.push_back(Student(name, index));
    }

    file.close();
}

int main() {
    int choice;

    loadFromFile(); // load existing data

    do {
        cout << "\n===== DIGITAL ATTENDANCE SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addStudent();
            saveToFile();
            break;
        case 2:
            viewStudents();
            break;
        case 3:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}