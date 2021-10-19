// https://www.geeksforgeeks.org/override-keyword-c/

// A CPP program without override keyword. Here
// programmer makes a mistake and it is not caught.
#include <iostream>
using namespace std;
  
class Base {
public:
  
    // user wants to override this in
    // the derived class
    virtual void func() {
        cout << "I am in base" << endl;
    }
   
};
  
class derived : public Base {
public:
    // did a silly mistake by putting
    // an argument "int a"
    void func(int a) override{      // if delete override, it will compile successfully.
        cout << "I am in derived class" << endl;
    }
};
  
// Driver code
int main()
{
    Base b;
    derived d;
    cout << "Compiled successfully" << endl;
    return 0;
}

/*
Here the user intended to override the function func() in the derived class 
but did a silly mistake and redefined the function with different signature. 
Which was not detected by the compiler. However, the program is not actually what the user wanted. 
So, to get rid of such silly mistake to be in safe side, override keyword can be used.
*/