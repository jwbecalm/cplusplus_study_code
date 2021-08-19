#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
 
class Singleton
{
public:
    static Singleton& getInstance();    // 构造函数为私有，通过调用Public的get函数生成并获得实例
    int getValue();
    void setValue(int iValue);
private:
    int value;
    Singleton();    //私有构造函数
    ~Singleton();   //私有析构函数
};
 
Singleton::Singleton()//构造函数
{
    cout << "构造函数执行" << endl;
}
 
Singleton::~Singleton()//析构函数
{
    cout << "析构函数执行" << endl;
}
 
// Singleton* Singleton::getInstance()
// {
//     cout << "in Singleton::getInstance" << endl;
//     static Singleton single;    // get函数中，使用局部静态变量, 实现单例（单件）
//     return &single;

// }

Singleton& Singleton::getInstance()
{
    cout << "in Singleton::getInstance" << endl;
    static Singleton single;    // get函数中，使用局部静态变量, 实现单例（单件）
    return single;

}
 
int Singleton::getValue()
{
    return value;
}
 
void Singleton::setValue(int v)
{
    value = v;
}
 
int main()
{
    cout << "单件模式" << endl;
    Singleton &p1 = Singleton::getInstance();   // 静态函数只要使用类名加范围解析运算符 :: 就可以访问
    Singleton &p2 = Singleton::getInstance();
    
    p1.setValue(123);
    cout << "p1.getValue() = " << p1.getValue() << endl;
    if (p1.getValue() == p2.getValue())
    {
        cout << "相同" << endl;     // 应用单件模式后，p1,p2指向同一个对象
    }
    else
    {
        cout << "不相同" << endl;
    }

    return 0;
}
/*
————————————————
版权声明：本文为CSDN博主「十指流玉」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_41886231/article/details/105010376
*/