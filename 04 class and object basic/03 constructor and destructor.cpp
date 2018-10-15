#include <iostream>
using namespace std;

class Box
{
    private:
        int length;
        int width;
        int height;
    public:
        Box()   //构造函数和类名同名，无返回类型，也无需返回void
        {
            cout << "in constructor: Box()" << endl;
        }
        /*
        Box(int l, int w, int h)
        {
            cout << "in constructor: Box(int, int, int)" << endl;
            length = l;
            width = w;
            height = h;
        }
        */
        //带初始化列表的构造函数，等同于上面的构造函数。
        Box (int l, int w, int h) : length(l), width(w), height(h)
        {
            cout << "in constructor with initial list" << endl;
        }
        ~Box()
        {
            cout << "in destructor ~Box()" << endl;
        }
};

int main(int argc, char const *argv[])
{
    Box box1;   //构造函数在创建对象时自动调用

    //constructor overloading
    Box box2(10,20,30); 
    //等同于下面的方式
    Box box3 = Box(10,20,30);

    return 0;
}
