/*
https://www.ibm.com/developerworks/cn/aix/library/1212_lufang_c11new/index.html

*/

#include <iostream>
using namespace std;


class X { 
private: 
    int x; 
public:
    X (){
        cout << "X::X()" << endl;
    }
    // ~X (){
    //     cout << "X:: ~X()" << endl;
    // }
   
    /*
    因此，一般情况下我们需要将基类的析构函数定义为虚函数，
    当利用 delete 语句删除指向派生类对象的基类指针时，
    系统会调用相应的派生类的析构函数（实现多态性），从而避免内存泄露。
    但是编译器隐式自动生成的析构函数都是非虚函数，这就需要由程序员手动的为基类 X 定义虚析构函数
    */
    virtual ~X (){
        cout << "X:: ~X()" << endl;
    }
}; 
 
class Y: public X { 
private: 
    int y; 
public:
    Y (){
            cout << "Y::Y()" << endl;
        }
    ~Y () {
        cout << "Y:: ~Y()" << endl;
    }
}; 
 
int main(){ 
    X* x = new Y; 
    // 删除指向子类对象的基类指针
    //delete x;   //如果基类的析构函数不是virtual，则只会调用父类X的析构函数。导致内存泄漏。
    cout << "after call delete x." << endl;

    Y y1;
}