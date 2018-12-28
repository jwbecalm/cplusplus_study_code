#include <iostream>
using namespace std;

// base class
class Vehicle
{
  int x;
  public:
    Vehicle()   //base class constructor
    {
        cout << "This is a Vehicle" << endl;
    }

    Vehicle(int x_): x(x_){
        cout << "in Vehicle::Vehicle(int x_)" << endl;
    }
};

// sub class derived from two base classes
class Car : public Vehicle
{
    //  sub class has no explict constructor
};

// main function
int main()
{
    // creating object of sub class will
    // invoke the constructor of base classes
    Car obj;
    return 0;
}