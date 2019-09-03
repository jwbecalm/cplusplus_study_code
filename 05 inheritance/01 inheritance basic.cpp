#include <iostream>
using namespace std;

class Parent 
{
public:
    int p = 9;
};

class Child : public Parent //通过public的方式继承
{
public:
    int c;
};

int main(int argc, char const *argv[])
{
    Child co;
    co.p = 10;  //Child 也拥有了父类的public成员
    co.c = 20;
    cout << "co.p = " << co.p << endl;
    cout << "co.c = " << co.c << endl;

    Parent po;
    cout << "Parent::p = " << po.p << endl;

    return 0;
}
