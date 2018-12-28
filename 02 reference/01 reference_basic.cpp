/*
C++ 引用
引用变量是一个别名，也就是说，它是某个已存在变量x的另一个名字。
一旦把引用初始化为某个变量x，就可以使用该引用名称来指向变量x。
引用可以理解为一个常量指针，编译器会自动添加取内容符号*

C++ 引用 vs 指针
不存在空引用。引用必须连接到一块合法的内存。
引用必须在创建时被初始化。指针可以在任何时间被初始化.
一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向到另一个对象；
指针可以做++操作;引用不可以
引用只有一级的概念，没有指针的指针这种多级概念

引用通常用于函数参数列表和函数返回值, 参见本目录其他文件

*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int i = 2;
    double d = 1.34;

    int& ri = i;    //声明ri是一个指向i的引用，存储的是变量i的地址
    double &rd = d; //声明rd是一个指向d的引用, 存储的是变量d的地址

    cout << "i = " << i <<endl;
    cout << "ri = " << ri <<endl;

    cout << "d = " << d << endl;    //使用时编译器会自动添加取内容符号*
    cout << "rd = " << rd << endl;

    ri = 10;    //改变引用的值，即改变了i的值
    cout << "i = " << i <<endl;
    cout << "ri = " << ri <<endl;


    return 0;
}


