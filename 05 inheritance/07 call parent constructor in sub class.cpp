#include <iostream>
using namespace std;

class Parent {
    int p;
    int x;
public:
    Parent() = default;
    Parent(int p_): x(99), p(p_){
    }

    int getP()
    {
        return p;
    }
    int getX()
    {
        return x;
    }
};

class Child : public Parent {
    int c;
public:
    //Child(int c_): Parent(1001),c(c_){    // 子类初始化父类的私有成员， 只能在初始化列表中进行
    Child(int c_): c(c_){
    }
    int getC(){
        return c;
    }

};

int main()
{
    
    Parent pObj1(10);
    cout << "Parent:: p = " << pObj1.getP() << endl;
    cout << "Parent:: x = " << pObj1.getX() << endl;

    Parent pObj2(20);
    cout << "Parent:: p = " << pObj2.getP() << endl;
    cout << "Parent:: x = " << pObj2.getX() << endl;
    
    Child cObjct(55);
    cout << "Child:: c = " << cObjct.getC() << endl;
    cout << "Parent:: p = " << cObjct.getP() << endl;
    cout << "Parent:: x = " << cObjct.getX() << endl;
    return 0;
}
