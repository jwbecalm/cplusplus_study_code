#include <iostream>
using namespace std;

class Cells{
    public:
    int id;
    int pci;
    float frequency;
    Cells(){
        cout << "in Cells()" << endl;
    }
};

class Box
{
    private:
        int length;
        int width;
        int height;
        
    public:
        Cells cells;
        Box(): cells()   //构造函数和类名同名，无返回类型，也无需返回void
        {
            cout << "in default constructor: Box()" << endl;
        }
        /*
        Box(int l, int w, int h)    //构造函数可以重载
        {
            cout << "in constructor: Box(int, int, int)" << endl;
            length = l;
            width = w;
            height = h;
        }
        */
        //带初始化列表的构造函数，等同于上面的构造函数。
        Box (int l, int w, int h) : length(), width(), height()
        {
            cout << "in constructor with initial list" << endl;
        }
        ~Box()
        {
            cout << "in destructor ~Box()" << endl;
        }
        int getLen(){
            return length;
        }
        int getWidth(){
            return width;
        }
        int getHeight(){
            return height;
        }

};

int main()
{
    Box box1;   //构造函数在创建对象时自动调用
    cout << "len, width, height is: " << box1.getLen() << endl << box1.getWidth()  << endl << box1.getHeight() << endl;
    cout << "cells parameter: " <<  box1.cells.id << endl << box1.cells.pci  << endl  << box1.cells.frequency << endl;

    //constructor overloading
    Box box2(10,20,30); 
    //等同于下面的方式
    Box box3 = Box(40,50,60);

    cout << "pass self object as parameter to construct a new object" << endl;
    Box box4(box3);
    cout << box4.getLen() << endl << box4.getWidth()  << endl << box4.getHeight() << endl;

    return 0;
}
