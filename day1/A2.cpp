#include <iostream>
using namespace std;


class FIR {
public:
    virtual void registerCase() = 0; 
    virtual ~FIR() {}
};


class Theft : public FIR {
public:
    void registerCase() override {
        cout << "Registering a Theft case.\n";
        cout << "Collecting details about stolen items.\n";
    }
};


class Accident : public FIR {
public:
    void registerCase() override {
        cout << "Registering an Accident case.\n";
        cout << "Collecting details about people involved and location.\n";
    }
};


class MissingPerson : public FIR {
public:
    void registerCase() override {
        cout << "Registering a Missing Person case.\n";
        cout << "Collecting physical description and last seen location.\n";
    }
};


void bookFIR(FIR* fir) {
    fir->registerCase();
}

int main() {
    FIR* fir;

    Theft theftCase;
    Accident accidentCase;
    MissingPerson missingCase;

    cout << "FIR Booking System:\n\n";

    fir = &theftCase;
    bookFIR(fir);

    cout << "\n";

    fir = &accidentCase;
    bookFIR(fir);

    cout << "\n";

    fir = &missingCase;
    bookFIR(fir);

    return 0;
}

