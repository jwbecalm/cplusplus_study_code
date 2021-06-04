/*
https://stackoverflow.com/questions/4549151/c-double-address-operator
&& is new in C++11. 
int&& a means "a" is an r-value reference. 
&& is normally only used to declare a parameter of a function. 
And it only takes a r-value expression. 
If you don't know what an r-value is, the simple explanation is that 
it doesn't have a memory address. E.g. the number 6, and character 'v' are both r-values. 
int a, a is an l-value, however (a+2) is an r-value.
*/


#include <iostream>
using namespace std;

void foo(int&& a)
{
    //Some magical code...
}

int main()
{
    int b;
    foo(b); //Error. An rValue reference cannot be pointed to a lValue.
    foo(5); //Compiles with no error.
    foo(b+3); //Compiles with no error.

    int&& c = b; //Error. An rValue reference cannot be pointed to a lValue.
    int&& d = 5; //Compiles with no error.
}