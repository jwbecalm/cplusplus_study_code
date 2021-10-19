// A class is abstract if it has at least one pure virtual function
// 针对接口编程，而不针对具体的实现编程 todo

#include <iostream>
 
using namespace std;
 
// 基类
class Shape 
{
public:
   
   virtual int getArea() = 0; // 提供接口框架的纯虚函数, 没有实现代码。通过多态进行运行时绑定，程序可以在运行时传入不同的子类对象，灵活调用不同子类的方法。
   void setWidth(int w)
   {
      width = w;
   }
   void setHeight(int h)
   {
      height = h;
   }
protected:
   int width;
   int height;
};
 
// 派生类
class Rectangle: public Shape
{
public:
   int getArea()                //在继承类中，实现不同的功能
   { 
      return (width * height); 
   }
};
class Triangle: public Shape
{
public:
   int getArea()                //在继承类中，实现不同的功能
   { 
      return (width * height)/2; 
   }
};
 
int main(void)
{
   Rectangle Rect;
   Triangle  Tri;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
   // 输出对象的面积
   cout << "Total Rectangle area: " << Rect.getArea() << endl;
 
   Tri.setWidth(5);
   Tri.setHeight(7);
   // 输出对象的面积
   cout << "Total Triangle area: " << Tri.getArea() << endl; 
 
   return 0;
}