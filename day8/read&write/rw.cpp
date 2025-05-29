#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Writing to a file
    std::ofstream outFile("data.txt");
    outFile << "C++ File I/O";
    outFile.close();

    // Reading from a file
    std::ifstream inFile("data.txt");
    std::string content;
    inFile >> content;
    inFile.close();

    std::cout << "Read from file: " << content << "\n";
    return 0;
}