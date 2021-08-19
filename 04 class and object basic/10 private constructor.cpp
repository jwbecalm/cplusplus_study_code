// https://blog.csdn.net/eric491179912/article/details/6708379


#include <iostream>
using namespace std;


class Test
{
    public:
        static Test* makeAnObject()     // statci成员函数，在不创建对象前也可以调用
        {
            if (m_pInstance == nullptr){
                // 创建一个Test对象并返回其指针
                m_pInstance = new Test();   // 在堆上创建对象，确保在makeAnObject函数结束后也能使用   
            }
            return m_pInstance;          
        }
    private:
        Test() {}  // 构造函数被设置为private, 无法在类外部创建对象
        static Test *m_pInstance;
};

int main()
{
    Test *p1 = Test::makeAnObject();     // 通过使用类名加范围解析运算符 :: 调用静态成员函数
    Test *p2 = Test::makeAnObject();
    // 使用*p...
    delete p1;  // Not neccesary here, but it's a good habit.
    delete p2;
    return 0;
}