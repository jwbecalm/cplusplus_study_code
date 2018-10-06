// 静态成员在类的所有对象中是共享的，不和任何对象关联
// 无论创建多少个类的对象，静态成员都只有一个副本。

//静态成员函数即使在类对象不存在的情况下也能被调用
//静态函数只要使用类名加范围解析运算符 :: 就可以访问
//静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）
//普通成员函数有 this 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针
#include <iostream>
using namespace std;

class Point{
    int x;
    int y;

public:
    static int objcount;    // 静态数据成员在类中只声明; 需要在类外面显示定义
    Point()
    {   
        objcount++;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
        objcount++;
    }
    void display()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
    static int getCount()   //静态成员函数，可以在类中直接定义
    {
        return objcount;
    }
};

int Point::objcount = 0;      // 静态数据成员在类外面，利用范围解析运算符 :: 定义和初始化

int main(int argc, char const *argv[])
{   
    //在创建对象之前，可以直接调用静态成员和静态成员函数
    cout << "before create object, getCount() = " << Point::getCount() << endl;
    cout << "before create object, objcount   = " << Point::objcount << endl;

    Point p1(3,4);
    Point p2(5,6);
    Point p3;
    cout << "total objects count = " << Point::objcount << endl;
    cout << "after create object, objcount = " << Point::getCount() << endl;

    return 0;
}

