/*
Modes of Inheritance
Public mode: public->public, protected-->protected 
Protected mode: public-->protected, protected-->protected.
Private mode: public-->private, protected-->private.

The private members in the base class cannot be directly accessed in the derived class, 
while protected members can be directly accessed
*/

#include <iostream>
using namespace std;

class A 
{
    public:
        int x;
    protected:
        int y;
    private:
        int z;
};

class B : public A 
{
    // x is public
    // y is protected
    // z is not accessible from B
};

class C : protected A 
{
    // x is protected
    // y is protected
    // z is not accessible from C
};

class D : private A 
{
    // x is private
    // y is private
    // z is not accessible From D
};
