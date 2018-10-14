#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(int x1, int y1)
    {
        cout << "in normal constructor" << endl;
        x = x1;
        y = y1;
    }
    
    Point(Point& p) //copy constructor. 入参是Point类的一个引用
    {
        cout << "in copy constructor" << endl;
        x = p.x;
        y = p.y;
    }
    
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};
int main(int argc, char const *argv[])
{
    Point p1(4,5);  // Normal constructor is called here
    cout << "x = " << p1.getX() << ", y = " << p1.getY() << endl;

    Point p2 = p1;  // Copy constructor is called here
    cout << "x = " << p2.getX() << ", y = " << p2.getY() << endl;

    return 0;
}
