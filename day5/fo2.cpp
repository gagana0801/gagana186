#include <iostream>
using namespace std;

class InvoiceGenerator {
public:
    
    void generateInvoice(int productID) {
        cout << "Generating invoice for Product ID: " << productID << endl;
        cout << "Quantity: 1" << endl;
        cout << "Discount: 0%" << endl;
        cout << "--------------------------" << endl;
    }

    
    void generateInvoice(int productID, int quantity) {
        cout << "Generating invoice for Product ID: " << productID << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Discount: 0%" << endl;
        cout << "--------------------------" << endl;
    }

    
    void generateInvoice(int productID, int quantity, float discount) {
        cout << "Generating invoice for Product ID: " << productID << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Discount: " << discount << "%" << endl;
        cout << "--------------------------" << endl;
    }
};

int main() {
    InvoiceGenerator invoice;

    invoice.generateInvoice(101);                  
    invoice.generateInvoice(102, 3);               
    invoice.generateInvoice(103, 5, 10.5);         

    return 0;
}

