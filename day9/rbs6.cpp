#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int marks;
};

// Bubble Sort students by marks (ascending)
void bubbleSort(Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].marks > arr[j + 1].marks) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) 
            break;
    }
}

// Linear Search student by name
int linearSearchByName(Student arr[], int n, const string &target) {
    for (int i = 0; i < n; i++) {
        if (arr[i].name == target)
            return i;  // return index if found
    }
    return -1;  // not found
}

// Binary Search for marks (array must be sorted by marks)
int binarySearchByMarks(Student arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].marks == target)
            return mid;
        else if (arr[mid].marks < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;  // not found
}

// Display list of students
void displayStudents(Student arr[], int n) {
    cout << "\nStudents List:\n";
    for (int i = 0; i < n; i++) {
        cout << (i + 1) << ". " 
             << arr[i].name 
             << " — " 
             << arr[i].marks 
             << " marks\n";
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();  // flush newline

    // Dynamically allocate array of Students
    Student *students = new Student[n];

    // Input student data
    for (int i = 0; i < n; i++) {
        cout << "Enter name of student " << (i + 1) << ": ";
        getline(cin, students[i].name);
        cout << "Enter marks of student " << (i + 1) << ": ";
        cin >> students[i].marks;
        cin.ignore();
    }

    // Show original list
    cout << "\nOriginal student list:";
    displayStudents(students, n);

    // Sort by marks ascending
    bubbleSort(students, n);
    cout << "\nStudents sorted by marks (ascending):";
    displayStudents(students, n);

    // Linear search by name
    string searchName;
    cout << "\nEnter student name to search (Linear Search): ";
    getline(cin, searchName);
    int idxName = linearSearchByName(students, n, searchName);
    if (idxName != -1) {
        cout << "Found " << students[idxName].name 
             << " with marks: " << students[idxName].marks << "\n";
    } else {
        cout << "Student with name \"" << searchName 
             << "\" not found.\n";
    }

    // Binary search by marks
    int searchMarks;
    cout << "\nEnter marks to search (Binary Search): ";
    cin >> searchMarks;
    int idxMarks = binarySearchByMarks(students, n, searchMarks);
    if (idxMarks != -1) {
        cout << "Found student " << students[idxMarks].name 
             << " with marks: " << students[idxMarks].marks << "\n";
    } else {
        cout << "No student found with marks " 
             << searchMarks << ".\n";
    }

    delete[] students;
    return 0;
}