#ifndef UE_CP_UPLINK_SINR_BASED_RELEASE_WITH_REDIRECT_H_
#define UE_CP_UPLINK_SINR_BASED_RELEASE_WITH_REDIRECT_H_

#include <iostream>
using namespace std;

class Point 
{
    int x;
    int y;

public:
    Point(int x, int y)
    {
        cout << "in Point(int x, int y)" <<endl;
        this->x = x;
        this->y = y;
    }
    Point() = default;  // defaulted constructor
    /*
    为了解决没有默认构造函数的问题：
    1. 减轻程序员的编程工作量；
    2. 获得编译器自动生成的默认特殊成员函数的高的代码执行效率，
    C++11 标准引入了一个新特性：defaulted 函数。程序员只需在函数声明后加上“=default;”，就可将该函数声明为 defaulted 函数，
    编译器将为显式声明的 defaulted 函数自动生成函数体。
    */
};

typedef enum checkReslut
{
    COMPLETE,
    PEND
}checkReslut;

struct sttype 
{
    checkReslut cr;
    //st() = default;
};

int main()
{
    Point p1;   // if no defaulted constructor, compile error: no default constructor exist
    
    //enum type test
    checkReslut cr;     // define a enum type variable
    cr = COMPLETE;      // give value to the variable
    cout << "cr = " << cr << endl;

    sttype st;
    st.cr = PEND;
    cout << "st.cr = " << st.cr << endl;
    return 0;
}
#endif