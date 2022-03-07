
/*声明一个成员函数的时候用const关键字是用来说明这个函数是 “只读(read-only)”函数，也就是说明这个函数不会修改任何数据成员(object)。 为了声明一个const成员函数， 把const关键字放在函数括号的后面。声明和定义的时候都应该放const关键字。

任何不会修改数据成员的函数都应该声明为const类型。如果在编写const成员函数时，不慎修改了数据成员，或者调用了其它非const成员函数，编译器将指出错误，这无疑会提高程序的健壮性。
————————————————
版权声明：本文为CSDN博主「caimagic」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/caimagic/article/details/51496666
*/


#include <iostream>

using namespace std;


class temp
{
public:
    temp(int age);
    int getAge() const;
    void setNum(int num);
private:
    int age;
};

temp::temp(int age)git 
{
    this->age = age;
}

int temp::getAge() const
{
    //age+=10; // #Error...error C2166: l-value specifies const object #
    return age;
}

int main()
{
    temp a(22);
    std::cout << "age= " << a.getAge() << endl;
    return 0;
}