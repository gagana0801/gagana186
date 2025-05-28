#include <iostream>
#include <string>
using namespace std;

class Vehicle {
    string model;
    int year;
    string owner;

public:
    // Constructor
    Vehicle(string m, int y, string o) {
        model = m;
        year = y;
        owner = o;
    }

    // Method to display vehicle details
    void show() {
        cout << "Model: " << model
             << ", Year: " << year
             << ", Owner: " << owner << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of vehicles rented today: ";
    cin >> n;

    // Dynamic array of pointers to Vehicle
    Vehicle** fleet = new Vehicle*[n];

    // Input vehicle details
    for (int i = 0; i < n; i++) {
        string model, owner;
        int year;

        cout << "\nEnter details for vehicle " << i + 1 << ":\n";
        cout << "Model: ";
        cin.ignore(); // clear newline from buffer
        getline(cin, model);
        cout << "Year: ";
        cin >> year;
        cin.ignore(); // clear newline again
        cout << "Owner: ";
        getline(cin, owner);

        // Create new Vehicle object
        fleet[i] = new Vehicle(model, year, owner);
    }

    // Display all vehicle details
    cout << "\nFleet Details:\n";
    for (int i = 0; i < n; i++) {
        fleet[i]->show();
    }

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        delete fleet[i]; // delete each Vehicle object
    }
    delete[] fleet; // delete array of pointers

    return 0;
}