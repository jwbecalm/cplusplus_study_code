/**/

#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    //constructor
    Point (int i, int j)
    {
        x = i;
        y = j;
    }
    // friend function
    friend void printxy(Point &p);    // 放在public和private没有区别

    // friend class
    friend class F;
};

class F
{
public:
    void func1(Point &p)
    {
        cout << "in F::func1()" << endl;
        cout << "p.x = " << p.x << endl;
    }
    void func2(Point &p)
    {
        cout << "in F::func2()" << endl;
        cout << "p.y = " << p.y << endl;

    }
};



//global friend fuction
void printxy(Point &p)
{
    // 友元函数可以直接访问类的私有成员。它是定义在类外的普通函数，它不属于任何类
    cout << "x = " << p.x << endl;
    cout << "y = " << p.y << endl;
}

int main(int argc, char const *argv[])
{
    Point p1(10,20);
    printxy(p1);    //在类的外部访问类的私有成员，函数参数中传入对象名，访问该对象的私有成员

    F f;
    f.func1(p1);
    f.func2(p1);

    return 0;
}
