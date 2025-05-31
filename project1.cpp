#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

const int MAX_STUDENTS = 25;

struct Student {
    string name;
    string regNumber;
    string phone;
    string email;
    string category;
    string gender;
    bool present;
    int physics, chemistry, math;
    int totalMarks;
    int rank;
};

void inputStudent(Student &s, int index) {
    cin.ignore();
    cout << "\nEnter details for student " << index + 1 << ":\n";
    cout << "Name: ";
    getline(cin, s.name);
    cout << "Registration number: ";
    getline(cin, s.regNumber);
    cout << "Phone: ";
    getline(cin, s.phone);
    cout << "Email: ";
    getline(cin, s.email);
    cout << "Category (GEN/OBC/SC/ST): ";
    getline(cin, s.category);
    cout << "Gender (M/F): ";
    getline(cin, s.gender);

    char ch;
    cout << "Is the candidate present? (Y/N): ";
    cin >> ch;
    s.present = (ch == 'Y' || ch == 'y');

    if (s.present) {
        cout << "Enter marks out of 100:\n";
        cout << "  Physics: "; cin >> s.physics;
        cout << "  Chemistry: "; cin >> s.chemistry;
        cout << "  Math: "; cin >> s.math;
        s.totalMarks = s.physics + s.chemistry + s.math;
    } else {
        s.physics = s.chemistry = s.math = s.totalMarks = 0;
    }
}

void assignRanks(vector<Student> &students) {
    sort(students.begin(), students.end(), [](Student a, Student b) {
        return a.totalMarks > b.totalMarks;
    });

    int rank = 1;
    for (auto &s : students) {
        if (s.present)
            s.rank = rank++;
        else
            s.rank = -1;
    }
}

void displayStudent(const Student &s) {
    cout << "\nName: " << s.name
         << "\nReg. No: " << s.regNumber
         << "\nPhone: " << s.phone
         << "\nEmail: " << s.email
         << "\nCategory: " << s.category
         << "\nGender: " << s.gender
         << "\nPresent: " << (s.present ? "Yes" : "No");

    if (s.present) {
        cout << "\nMarks - Physics: " << s.physics
             << ", Chemistry: " << s.chemistry
             << ", Math: " << s.math
             << "\nTotal Marks: " << s.totalMarks
             << "\nRank: " << s.rank;
    }
    cout << "\n-----------------------------------";
}

void displayAll(const vector<Student> &students) {
    cout << "\n======= All Registered Students =======\n";
    for (const auto &s : students) {
        displayStudent(s);
    }
}

void searchStudent(const vector<Student> &students) {
    string key;
    cin.ignore();
    cout << "Enter student name or registration number to search: ";
    getline(cin, key);
    bool found = false;

    for (const auto &s : students) {
        if (s.name == key || s.regNumber == key) {
            displayStudent(s);
            found = true;
        }
    }

    if (!found) cout << "Student not found.\n";
}

void deleteStudent(vector<Student> &students) {
    string regNo;
    cin.ignore();
    cout << "Enter registration number to delete: ";
    getline(cin, regNo);

    auto it = remove_if(students.begin(), students.end(),
        [&regNo](Student &s) { return s.regNumber == regNo; });

    if (it != students.end()) {
        students.erase(it, students.end());
        cout << "Student deleted successfully.\n";
    } else {
        cout << "Student not found.\n";
    }
}

void displayTopRankers(const vector<Student> &students, int N) {
    cout << "\n======= Top " << N << " Rankers =======\n";
    int count = 0;
    for (const auto &s : students) {
        if (s.present && s.rank != -1) {
            cout << "Rank " << s.rank << ": " << s.name << " - " << s.totalMarks << " marks\n";
            if (++count == N) break;
        }
    }
}

int main() {
    vector<Student> students;
    int choice;

    // Input data for 25 students
    cout << "\nEnter details for 25 students:\n";
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        Student s;
        inputStudent(s, i);
        students.push_back(s);
    }

    assignRanks(students);

    do {
        cout << "\n======= JEE Main Registration Menu =======\n";
        cout << "1. Display all students\n";
        cout << "2. Search a student\n";
        cout << "3. Delete a student\n";
        cout << "4. Show top N rankers\n";
        cout << "5. Display particular student details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayAll(students);
            break;
        case 2:
            searchStudent(students);
            break;
        case 3:
            deleteStudent(students);
            assignRanks(students); // reassign ranks after deletion
            break;
        case 4: {
            int n;
            cout << "Enter number of top rankers to display: ";
            cin >> n;
            displayTopRankers(students, n);
            break;
        }
        case 5:
            searchStudent(students);
            break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
