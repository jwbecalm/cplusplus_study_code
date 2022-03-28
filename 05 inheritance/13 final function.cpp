/*Sometimes you don’t want to allow derived class to override the base class’ virtual function. 
C++ 11 allows built-in facility to prevent overriding of virtual function using final specifier. */

#include <iostream>
using namespace std;
 
class Base
{
public:
    virtual void myfun() final
    {
        cout << "myfun() in Base";
    }
};
class Derived : public Base
{
    void myfun()    // compile error:  error: virtual function 'virtual void Derived::myfun()' overriding final function
    {
        cout << "myfun() in Derived\n";
    }
};
 
int main()
{
    Derived d;
    Base &b = d;
    b.myfun();
    return 0;
}