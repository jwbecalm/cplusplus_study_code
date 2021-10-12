// When do we use Initializer List in C++?
// https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/

/* c++ primer the fifth edition
We must use the constructor initializer list to provide values for members that
are const, reference, or of a class type that does not have a default
constructor.
*/

/*
When we define variables, we typically initialize them immediately rather than defining
them and then assigning to them:

string foo = "Hello World!"; // define and initialize
string bar; // default initialized to the empty string
bar = "Hello World!"; // assign a new value to bar

*/

#include <iostream>

using std::cout;
using std::endl;

class ConstRef {
public:
    ConstRef(int ii);
private:
    int i;
    const int ci;   // 常量在定义时没有赋值，编译时会报错：error: uninitialized const member
    int &ri;        // 引用在定义时没有赋值，编译时会报错：error：uninitialized reference member 
};

// ConstRef::ConstRef(int ii){     // By the time the body of the constructor begins executing, initialization is complete.
//                                 // Our only chance to initialize const or reference data members is in the constructor initializer
//                 // assignments
//     i = ii;     // ok
//     ci = ii;    // compile error: uninitialized const member
//     ri = i;     // 引用在定义后不能改变指向
// }

ConstRef::ConstRef(int ii):i(ii),ci(ii),ri(i){}

// 初始化的顺序和list里的顺序无关，只和成员变量的声明顺序有关。
class X {
    public:
    int i;
    int j;
    // undefined: i is initialized before j
    X(int val): j(val), i(j) { }
};



int main(){
    ConstRef obj(100);

    X x(200);
    cout <<"x.i=" << x.i<< endl;
    cout <<"x.j=" << x.j << endl;
    return 0;
}