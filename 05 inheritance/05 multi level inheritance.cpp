#include <iostream> 
using namespace std; 
  
// base class 
class Vehicle  
{ 
  public: 
    Vehicle() 
    { 
      cout << "This is a Vehicle" << endl; 
    } 
    void displayVehicle()
    {
        cout << "displayVehicle" << endl;
    }
}; 
class fourWheeler: public Vehicle 
{  public: 
    fourWheeler() 
    { 
      cout<<"Objects with 4 wheels are vehicles"<<endl; 
    } 
    void displayFourWheeler()
    {
        cout << "displayFourWheeler" << endl;
    }
}; 
// sub class derived from two base classes 
class Car: public fourWheeler{ 
   public: 
     Car() 
     { 
       cout<<"Car is a fourWheeler type and also a Vehicle type"<<endl; 
     } 
}; 
  
// main function 
int main() 
{    
    //creating object of sub class will 
    //invoke the constructor of base classes 
    Car obj; 

    //use the base classes methods
    obj.displayVehicle();
    obj.displayFourWheeler();
    return 0; 
} 