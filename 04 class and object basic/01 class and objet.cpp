#include <iostream>

using namespace std;

class Box
{
    //没有修饰符时，默认是private:
    int length;
    int width;
    int height;

    public:
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

int main(int argc, char const *argv[])
{
    Box box;    //创建一个Box类的对象，名为box
    //box.length = 88;  //forbidden, lenght is priviate by default

    box.setLength(10);
    box.setWidth(20);
    box.setHeight(30);

    int volume = box.getVolume();
    cout << "box volume = " << volume << endl;

    return 0;
}
