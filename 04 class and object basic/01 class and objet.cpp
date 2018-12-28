#include <iostream>

using namespace std;

class Box
{
    //没有修饰符时，默认是private:
    int length;
    int width;
    int height;

    
    public:
        int test;   //用于测试，在子类的构造函数中，调用父类构造函数
        Box() = default;
        Box(int test_): test(test_){
            cout << "Box: in constructor with initial list" << endl;
            cout << "Box:: test = " << test << endl;
        }   

        /*成员函数可以在类中声明，在类外面定义；或者在类里直接定义*/
        void setLength(int);
        void setWidth(int);
        void setHeight(int);
        int getVolume() //在类里直接定义
        {
            return length * width *height;
        }
};

/*在类的外部定义：使用范围解析运算符::*/
void Box::setLength(int len)
{
    length = len;
}

void Box::setWidth(int wid)
{
    width = wid;
}

void Box::setHeight(int h)
{
    height = h;
}

class SubBox : public Box {
    int ss;
public:
    SubBox(int ss_)
    :   Box(99),ss(ss_){}

    void test() {
        
    }
};

int main(int argc, char const *argv[])
{
    Box box;    //创建一个Box类的对象，名为box
    //box.length = 88;  //forbidden, lenght is priviate by default

    box.setLength(10);
    box.setWidth(20);
    box.setHeight(30);

    int volume = box.getVolume();
    cout << "box volume = " << volume << endl;

    SubBox sb(55);
    cout << "box.test = " << sb.test << endl;
    //cout << "sb.ss   = " << sb.ss << endl;

    return 0;
}
