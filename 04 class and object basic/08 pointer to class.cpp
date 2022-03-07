#include <iostream>
using namespace std;

class Box{
    int length;
    int width;
    int height;
public:
    Box(int l, int w, int h)
    {
        length = l;
        width  = w;
        height = h;
    }
    int getVolume()
    {
        return length * width *height;
    }
};

int main()
{
    Box b1(1,2,3);
    Box b2(3,4,5);
    
    Box *pb = NULL;
    pb = &b1;   //pb指向对象b1的地址

    //cout << "b1  = " << b1 << endl; //compile error
    cout << "&b1 = " << &b1 << endl;
    cout << "pb  = " << pb << endl;
    cout << "&pb = " << &pb << endl;

    cout << "b1 volume = " << pb->getVolume() << endl;  //通过指针的方式访问对象的成员函数

    pb = &b2;   //改变pb，使其指向对象b2的地址；
    cout << "b2 volume = " << pb->getVolume() << endl;  //此时pb已指向对象b2，调用得到b2的volume


    return 0;
}