#include <iostream>
using namespace std;

class Parent 
{
public:
    int p;
    void setup(){
        cout << "in Parent::setup()" << endl;
    }
};

class Child : public Parent //通过public的方式继承
{
public:
    int c;
    void setup(){
        cout << "in Child::setup()" << endl;
        Parent::setup();   // 在子类中调用父类的成员方法：因为子类自动获得父类的public成员方法。
    }
    void test(){
        cout << "in Child::test()" << endl;
        Parent::setup();    //在子类中调用父类的成员方法：因为子类自动获得父类的public成员方法。
    }
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

    co.setup();
    co.test();

    return 0;
}
