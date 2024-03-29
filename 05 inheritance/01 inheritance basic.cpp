#include <iostream>
using namespace std;

class Parent 
{
public:
    int p;
    Parent(){
        p = 100;
    }
    virtual void setup(){
        cout << "in Parent::setup()" << endl;
    }
};

class Child : public Parent //通过public的方式继承
{
public:
    int c;
    void setup() override {
        cout << "in Child::setup()" << endl;
        Parent::setup();   // 在子类中调用父类的成员方法：因为子类自动获得父类的public成员方法。
    }
    void test(){
        cout << "in Child::test()" << endl;
        Parent::setup();    //在子类中调用父类的成员方法：因为子类自动获得父类的public成员方法。
    }
};

int main()
{
    Child co;
    co.p = 10;  //Child 也拥有了父类的public成员
    co.c = 20;
    cout << "Child::p = " << co.p << endl;
    cout << "Child::c = " << co.c << endl;

    Parent po;
    cout << "Parent::p = " << po.p << endl;

    co.setup();     // 子类自动获得父类的Public成员方法。如果要调用父类的方法，需要在子类中使用Parent::setup()
    co.test();

    return 0;
}
