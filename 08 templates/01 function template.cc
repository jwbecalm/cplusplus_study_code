/*
https://www.geeksforgeeks.org/templates-cpp/

The simple idea is to pass data type as a parameter 
so that we don’t need to write same code for different data types. 

C++ adds two new keywords to support templates: 
‘template’ and ‘typename’. The second keyword can always be replaced 
by keyword ‘class'

Templates are expanded at compiler time. This is like macros. 
The difference is, compiler does type checking before template expansion.
 The idea is simple, source code contains only function/class, 
 but compiled code may contain multiple copies of same function/class
*/
#include <iostream>
using namespace std;

// One function works for all data types.  This would work 
// even for user defined types if operator '>' is overloaded 
template <typename T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}

int main()
{
    cout << myMax<int>(5,10) << endl;           // call myMax for int 
    cout << myMax<double>(1.0, 4.2) << endl;    // call myMax for double
    cout << myMax<char>('e', 'f') << endl;      // call myMax for char

    return 0;
}
