/*
背景：每个对象都有一份各自data member（数据成员）的拷贝；但是共享一个member function(成员函数)
当定义了一个类的多个对象时，每个对象是如何访问和更新各自的数据成员的？
编译器提供了一个当前对象的隐式指针this，当调用该对象的成员函数时，把this作为一个隐藏参数进行传递：
这样在成员函数中就可以利用this->xx访问当前对象的数据成员。

应用场景：
1、When local variable’s name is same as member’s name(成员函数的参数名和数据成员名一样时)
2、To return reference to the calling object.
the returned reference can be used to chain function calls on a single object.
*/

#include <iostream>
using namespace std;

class Point{
    int x;
    int y;
public:
    Point()
    {
        //构造函数，默认会初始化数据成员为0
    }
    Point(int x, int y)
    {
        this->x = x;    //1、成员函数的参数名和数据成员名一样时，用this->x 调用数据成员
        this->y = y;
    }
    void displayXY()
    {
        cout << "this->x = " << x << endl;
        cout << "this->y = " << y << endl;
    }
    Point& setX(int x)
    {
        this->x = x;
        return *this;   //this为当前对象的指针变量，this取*代表 this指向的内存地址，即当前对象的地址
    }
    Point &setY(int y)
    {
        this->y = y;
        return *this;
    }
};

int main(int argc, char const *argv[])
{
    Point p1(10,20);
    p1.displayXY();

    Point p2;
    p2.displayXY();
    p2.setX(30).setY(40);   //2、返回当前对象的引用，可以使用级联的对象调用方式.xx.xx
    p2.displayXY();
    return 0;
}
