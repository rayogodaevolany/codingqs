#include <iostream>
#include <string>
using namespace std;

// Make a class of automobiles


class Automobile {
    public:
        Automobile();
        Automobile(string manufacturer, string model, int modelYear);
        string getManufacturer();
        void setManufacturer(string manufacturer);
        string getModel();
        void setModel(string model);
        int getModelYear();
        void setModelYear(int year);
        string description();
        int age();
    private:
        string _manufacturer;
        string _model;
        int _modelYear;
};
Automobile::Automobile(){
    _manufacturer = "N/A";
    _model = "N/A";
    _modelYear = -1;
}

Automobile::Automobile(string manufacturer, string model, int modelYear){
    _manufacturer = manufacturer;
    _model = model;
    _modelYear = modelYear;
}

string Automobile::getManufacturer(){
    return _manufacturer;
}

void Automobile::setManufacturer(string manufacturer){
    _manufacturer = manufacturer;
}

string Automobile::getModel(){
    return _model;
}

void Automobile::setModel(string model){
    _model = model;
}

int Automobile::getModelYear(){
    return _modelYear;
}

void Automobile::setModelYear(int year){
    _modelYear = year;
}

string Automobile::description(){
    string description = "";
    description= to_string(_modelYear) 
        + " " 
        + _manufacturer 
        + " " 
        + _model;
    return description;
}

int Automobile::age(){
    // current year - model year
    int age = 2025 - _modelYear;
    return age;
}


int main(){
    Automobile car("Chevrolet", "Impala", 1957);
    cout << car.description() << endl;
    cout << car.age() << endl;
    return 0;
}
