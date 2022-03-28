/*If a class or struct is marked as final then it becomes non inheritable 
and it cannot be used as base class/struct. */

#include <iostream>

class Base 
{
};
 
class Derived final : public Base     
{
};
 
class SecondDerived :public Derived{    // compile error:  error: cannot derive from 'final' base 'Base' in derived type 'Derived'

};

int main()
{
    Derived d;
    SecondDerived sd;
    return 0;
}