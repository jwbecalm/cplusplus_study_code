/*
static_cast can perform conversions between pointers to related classes, 
not only upcasts (from pointer-to-derived to pointer-to-base),
 but also downcasts (from pointer-to-base to pointer-to-derived). 
 No checks are performed during runtime to guarantee that 
 the object being converted is in fact a full object of the destination type. 
 Therefore, it is up to the programmer to ensure that the conversion is safe. 
 On the other side, it does not incur the overhead of the type-safety checks of dynamic_cast.
*/


//This would be valid code, although b would point to an incomplete object 
//of the class and could lead to runtime errors if dereferenced
class Base {};

class Derived: public Base {};

int main()
{
    Base * a = new Base;
    Derived * b = static_cast<Derived*>(a);
    return 0;
}

