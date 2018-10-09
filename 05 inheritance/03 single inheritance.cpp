#include <iostream>
using namespace std;

// base class
class Vehicle
{
  public:
    Vehicle()   //base class constructor
    {
        cout << "This is a Vehicle" << endl;
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