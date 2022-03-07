#include <iostream>

using namespace std;
/*
This is okay for small projects, as long as you write the using directive in your cpp file. 
Never write a using directive into a header file! 
This would bloat the entire namespace std into each and every cpp file 
that includes that header. For larger projects, 
it is better to explicitly qualify every name accordingly.
*/

namespace ns1   //Namespace declarations appear only at global scope
{
    // Namespace declarations don’t have visibility. (Public or private)
    int i = 10;
    
    void func()
    {
        cout << "in namespace ns1::func()" << "\n";
    }

    void display();     //only declare in namespace, define outside the namespace
    class Coutsidens;   //only delcare in namespace, define outside the namespace

    class Ctest // Class define in namespace
    {
        public: 
            int i = 99; //c++11 才允许这么做，如果编译器是之前版本，会有编译告警
            
            void display2()
            {
                cout << "in namespace ns1::Ctest::dispaly2()" << endl;
            }
    };
}   //No need to give semicolon after the closing brace of definition of namespace.

// Defining func outside namespace
void ns1::display()
{
    cout << "in ns1:: display(). func declared outside the namespace" << endl;
}

// Defining class outside namespace
class ns1::Coutsidens
{
    public:
    void display()
    {
        cout << "in namespace ns1::Coutsidens::display()" << endl;
    }
};

// Extending namespaces (Using the same name)
// 例如下面的三个namespace，没有本质区别，只是同一个namespace分不同的part来定义。（什么场景下使用？）
namespace ns1
{
    int i2 = 20;
}
namespace ns1
{
    int i3 = 30;
}

namespace ns2
{
    int gj = 1002;
}

// nested namespace
namespace level1
{
    int i = 88;
    namespace level2
    {
        int i = 77;
    }
}
int main()
{
    /* Different ways to access namespace */
    // 1. Normal way
    cout << "1. Normal way to access namespace:------------------" << endl;
    cout << "ns1::i = " << ns1::i << endl;
    cout << "ns1::i2 = " << ns1::i2 << endl;
    cout << "ns1::i3 = " << ns1::i3 << endl;
    ns1::func();

    ns1::Ctest obj;
    obj.display2();
    cout << "ns1::Ctest obj.i = " << obj.i << endl;

    ns1::Coutsidens obj2;
    obj2.display();

    // 2. use "using namespace" way 
    using namespace ns2;
    cout << "2. using namespace xxx to access namespace------" << endl;
    cout << "gj = " << gj << endl;

    /*nested namespace*/
    cout << "nested namespace-----------------------------" << endl;
    cout << "in ns level 1: i = " << level1::i << endl;
    cout << "in ns level 2: i = " << level1::level2::i << endl;

    cout << ::ns1::i << endl;

    return 0;
}

