// https://www.geeksforgeeks.org/override-keyword-c/
/*
It helps to check if :

There is a method with the same name in the parent class.
The method in the parent class is declared as “virtual” which means it was intended to be rewritten.
The method in the parent class has the same signature as the method in the subclass.
*/


// A CPP program without override keyword. Here
// programmer makes a mistake and it is not caught.
#include <iostream>
using namespace std;
  
class Base {
public:
  
    // user wants to override this in
    // the Derived class
    virtual void func() {
        cout << "I am in base" << endl;
    }
    // pure virtual function
    virtual void pureFunc() = 0;
   
};
  
class Derived : public Base {
public:
    // did a silly mistake 
    void fun() override {      // if delete override, it will compile successfully.
        cout << "I am in Derived class" << endl;
    }

    // for pure virtual function, refer to "11 pure virtual function override"
    void pureFun()  {   //  cannot declare variable 'd' to be of abstract type 'Derived', because the following virtual functions are pure within 'Derived'
///             ^ mistake with name       
        cout << "in Derived::pureFunc()" << endl;
    }
};
  
// Driver code
int main()
{
    //Base b;
    Derived d;
    cout << "Compiled successfully" << endl;
    return 0;
}

/*
Here the user intended to override the function func() in the Derived class 
but did a silly mistake and redefined the function with different signature. 
Which was not detected by the compiler. However, the program is not actually what the user wanted. 
So, to get rid of such silly mistake to be in safe side, override keyword can be used.
*/