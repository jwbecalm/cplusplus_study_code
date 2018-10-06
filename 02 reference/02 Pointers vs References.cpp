/*
When to use What
Overall, Use references when you can, and pointers when you have to.

The performances are exactly the same, as references are implemented internally 
as pointers. But still you can keep some points in your mind to decide when to use what :

Use references
    In function parameters and return types.

Use pointers:
    To implement data structures like linked list, tree, etc and their algorithms.
    Use pointers if  pointer arithmetic or passing NULL-pointer is needed. 
    For example for arrays (Note that array access is implemented using pointer arithmetic).

*/

#include <iostream>
using namespace std;

//通过指针传递参数
void swapByPointer(int* x, int* y)
{
    int z = *x;
    *x = *y;
    *y = z;
}

//通过引用传递参数
void swapByRef(int& x, int& y)
{
    int z = x;
    x = y;
    y = z;
}

struct demo
{
    int a;
};

int main(int argc, char const *argv[])
{
    int a = 45, b= 35;
    cout << "swap by pointer--------------------------------" << endl;
    cout << "before swap, a = " << a << ", b = " << b << endl;
    swapByPointer(&a, &b);
    cout << "after swap,  a = " << a << ", b = " << b << endl;


    int c = 11, d = 22;
    cout << "swap by reference------------------------------" << endl;
    cout << "before swap, c = " << c << ", d = " << d << endl;
    swapByRef(c, d);
    cout << "after swap,  c = " << c << ", d = " << d << endl;
    cout << "-----------------------------------------------" << endl;

    int x = 5;
    int y = 6;
    int *p = NULL;  //指针可以初始化为NULL
    //int &r = NULL;  //compile error: 引用不能初始化为NULL

    p = &x;
    cout << "&x = " << &x << endl;
    cout << "p  = " << p << endl;        //x的地址和p指向的地址相同
    cout << "&p = " << &p << endl;       //&p是指针变量自身的地址， 在main函数的栈中不会改变
    p = &y; //指针可以重新指向另外一个地址
    cout << "p  = " << p << endl;        //此时的p和y的地址相同
    cout << "&y = " << &y << endl;
    cout << "------------------------------------------------" << endl;

    int &r = x; //引用在创建时必须初始化
    //&r = y;   //compile error： 引用一旦创建后，就不能改变其指向
    cout << "r = " << r << endl;
    r = y;      // x value becomes 6: r相当于x的别名，所以这里相当于把x重新赋值为y;
    cout << "r = " << r << endl;
    cout << "------------------------------------------------" << endl;

    p++;    //指针按照int大小移动
    r++;    //r引用的内存单元+1，=7，
    cout << "&p = " << &p << endl;      //&p指针变量本身不会变化
    cout << "p  = " << p << endl;       //p的地址在y的地址基础上+4个字节(int)
    cout << "&x = " << &x << endl;      //&x地址不变
    cout << "&r = " << &r << endl;      //r为指向x的引用，所以r和x的地址相同

    cout << "r = " << r << endl;        //r = 7
    cout << "x = " << x << endl;        //x = 7


    demo st;         // define a struct: st
    demo *pst = &st;    
    demo &rst = st;

    pst->a = 77;    // 指针访问结构成员，必须使用->
    //pst.a = 77;   // compile error

    rst.a = 88;     // 引用访问结构成员，必须使用.
    //rst->a = 88;  // compile error

    return 0;
}
