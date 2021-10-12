// 转载：
// http://blog.csdn.net/iicy266/article/details/11906457

/*
直接的讲，C++中基类采用virtual虚析构函数是为了防止内存泄漏。
具体地说，如果派生类中申请了内存空间，并在其析构函数中对这些内存空间进行释放。
假设基类中采用的是非虚析构函数，当删除基类指针指向的派生类对象时就不会触发动态绑定，
因而只会调用基类的析构函数，而不会调用派生类的析构函数。
那么在这种情况下，派生类中申请的空间就得不到释放从而产生内存泄漏。
所以，为了防止这种情况的发生，C++中基类的析构函数应采用virtual虚析构函数。

*/


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