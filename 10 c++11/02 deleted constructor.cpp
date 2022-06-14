// https://www.ibm.com/developerworks/cn/aix/library/1212_lufang_c11new/index.html

/*
但是在某些情况下，假设我们不允许发生类对象之间的拷贝和赋值，可是又无法阻止编译器隐式自动生成默认的拷贝构造函数以及拷贝赋值操作符.
为了能够让程序员显式的禁用某个函数，C++11 标准引入了一个新特性：delete 函数。
程序员只需在函数声明后加上“=delete;”，就可将该函数禁用。
例如，我们可以将类 X 的拷贝构造函数以及拷贝赋值操作符声明为 deleted 函数，就可以禁止类 X 对象之间的拷贝和赋值。

*/

/*https://stackoverflow.com/questions/5513881/meaning-of-delete-after-function-declaration*/


#include <iostream>
using namespace std;

class X{ 
public: 
    //X(); 
}; 
 
class Z {
public:
    Z();
    Z(const Z& other) = delete;             // 声明拷贝构造函数为 deleted 函数
    Z& operator= (const Z& in) = delete;    // 声明拷贝赋值操作符为 deleted 函数

};
int main(){ 
    X x1; 
    X x2=x1;   // 正确，调用编译器隐式生成的默认拷贝构造函数
    X x3; 
    x3=x1;     // 正确，调用编译器隐式生成的默认拷贝赋值操作符

    // Z z1;
    // Z z2(z1);  // 错误，拷贝构造函数被禁用
    // Z z3;
    // z3 = z1;   // 错误，拷贝赋值操作符被禁用
}

/*
T(void)                  = delete; // default ctor    (1)
~T(void)                 = delete; // default dtor    (2)
T(const T&)              = delete; // copy ctor       (3)
T(const T&&)             = delete; // move ctor       (4)
T& operator= (const T&)  = delete; // copy assignment (5)
T& operator= (const T&&) = delete; // move assignment (6)
*/