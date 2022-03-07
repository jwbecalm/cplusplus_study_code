#include <iostream>
using namespace std;

class Parent {
protected:
    unsigned char* buf;
    unsigned int bufLenght;

public:
     void Setup()
    {
        buf = nullptr;
        bufLenght = 0;
        cout << "in Parent class Setup()" << endl;
    }
    virtual void TearDown() 
    {
        delete[] buf;
    }
    void test()
    {
        cout << "in Parent test()" << endl;
    }
};

class Child : public Parent{
public:
    virtual void Setup2()
    {
        test();
        Setup();
        Parent::Setup();    // access Parent method without a parent's object? --这里Parent::是作用域，在子类中访问父类方法
        cout << "in Child class Setup()" << endl;
    }
};

int main()
{
    Child co;
    co.Setup2();

    return 0;
}
