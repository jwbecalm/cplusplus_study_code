/*
A name that begins with the scope resolution operator (::) 
is looked up in the global namespace. 

using :: at the beginning allows you to spell 
the full name of a global something. 
This also allows you to distinguish between local and global variables
*/

#include <iostream>
using namespace std;

void bar();    // this is a global function

class foo {
    void some_func() { ::bar(); }    // this function is calling the global bar() and not the class version
    void bar();                      // this is a class member
};
//if you need to call the global bar() function from within a class member function, 
//you should use ::bar() to get to the global version of the function.

namespace x {
    const int i = 1;
}

namespace y {
    namespace x {
        const int i = 2;
    }

    void func()
    {
        std::printf("x::i   = %d\n", x::i);
        std::printf("::x::i = %d\n", ::x::i);
    }
}

int count = 0;

int main(void) {
  int count = 0;
  ::count = 1;  // set global count to 1
  count = 2;    // set local count to 2

  cout << "count  = " << count << endl;
  cout << "::cout = "<< ::count << endl;

    y::func();

  return 0;
}