/*--------------------- 
作者：wolf-langz 
来源：CSDN 
原文：https://blog.csdn.net/lz_obj/article/details/77435491 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/

#include <iostream>
using namespace  std;

class SimpleTestClass
{
public:
    SimpleTestClass()
    {
        std::cout<<"the SimpleTestClass creates"<<std::endl;
    }
    SimpleTestClass(int id):m_id(id)
    {
        std::cout<<"the SimpleTestClass(int id) creates"<<std::endl;
        std::cout<<"the value of the private member m_id is : "<<m_id<<std::endl;
    }
    ~SimpleTestClass()
    {
        std::cout<<"the SimpleTestClass destroys"<<std::endl;
        std::cout<<"the value of the private member m_id is : "<<m_id<<std::endl;
    }  
    void TestRun()
    {
        std::cout<<"the SimpleTestClass public function is running."<<std::endl;
        std::cout<<"the value of the private member m_id is : "<<m_id<<std::endl;
        cout << "\n";
    }
private:
    int m_id;
};

int main()
{
    SimpleTestClass object(1);
    object.TestRun();

    {
        cout << "enter code block\n";
        /// 代码块内旧的object在内部代码块和外部代码块都是可见的，而新的object就只在内部代码块中可见。
        /// 两个同名对象（一个位于外部代码块中，一个位于内部代码块中），程序执行内部代码块中的语句时，
        /// 将新的object解释为局部代码块变量，新的定义隐藏了以前的定义，新定义可见，旧定义暂时不可见。
        SimpleTestClass object(2);
        object.TestRun();
        SimpleTestClass myobject(3);
        myobject.TestRun();
        /// 代码块内执行完成时，myobject和object对象析构函数被调用，资源被回收。
        cout <<"exit code block\n\n";
    }
    cout << endl;
    /// 在程序离开该代码块时，旧的定义又重新可见。
    object.TestRun();

    return 0;
}
