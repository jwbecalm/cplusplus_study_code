/*
C++11: §12.3.1
A constructor declared without the function-specifier "explicit" 
specifies a conversion from the types of its parameters to 
the type of its class. Such a constructor is called a converting constructor.

In C++, if a class has a constructor which can be called with a single argument, 
then this constructor becomes conversion constructor 
because such a constructor allows automatic conversion to the class being constructed.

Technically, a converting constructor is any constructor that doesn't have the "explicit" keyword.
"explicit" means that the types of the arguments must match the types that are specified in the parameters. 
As in: if a parameter is an int, the argument must be an int, not double or float etc.

*/


// 03_2 struct constructor.cpp 
#include <iostream>
using namespace std;

typedef struct subStruct {
    int si;
    int b;
    subStruct(const int si_) : si(si_){
    }
}SS;

struct TestStruct {
    SS  ss; 
    int i;
    //constructor and operator overload
    TestStruct(const SS ss_)  : ss(ss_) {

    }
/*
    TestStruct() = default;
    TestStruct(const TestStruct&) = default;
    TestStruct& operator=(const TestStruct&) = default;
    TestStruct(TestStruct&&) = default;
    TestStruct& operator=(TestStruct&&) = default;
*/
};

int main(int argc, char const *argv[])
{
    TestStruct ts = TestStruct(3004);
    cout << ts.ss.si << endl;
    
    return 0;
}