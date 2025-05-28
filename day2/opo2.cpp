#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Item {
private:
    int quantity;
    double price;

public:

    Item(int q = 0, double p = 0.0) : quantity(q), price(p) {}

    Item operator+(const Item& other) {
        return Item(this->quantity + other.quantity, this->price); 
    }

    bool operator==(const Item& other) {
        return (this->quantity == other.quantity && this->price == other.price);
    }

    friend ostream& operator<<(ostream& os, const Item& item) {
        os << "Item -> Quantity: " << item.quantity 
           << ", Price: $" << fixed << setprecision(2) << item.price;
        return os;
    }
};

int main() {
    Item item1(10, 350.75);
    Item item2(5, 350.75);

    Item item3 = item1 + item2;

    cout << item3 << endl;

    if (item1 == item2) {
        cout << "item1 and item2 are same in quantity and price." << endl;
    } else {
        cout << "item1 and item2 are not the same." << endl;
    }

    return 0;
}