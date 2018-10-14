/*
重载的运算符是带有特殊名称的函数，
函数名是由关键字 operator 和其后要重载的运算符符号构成的。
与其他函数一样，重载运算符有一个返回类型和一个参数列表。
Box operator+(const Box&);
声明加法运算符用于把两个 Box 对象相加，返回最终的 Box 对象。
大多数的重载运算符可被定义为普通的非成员函数或者被定义为类成员函数。
如果我们定义上面的函数为类的非成员函数，那么我们需要为每次操作传递两个参数，如下所示：
Box operator+(const Box&, const Box&);


*/
#include <iostream>
using namespace std;
 
class Box
{
   public:
   Box operator+(const Box&);    //declaration
   Box ()
   {
       cout << "in Box constructor" << endl;
   }
   //copy constructor, the input parameter is a reference of Box
   
   Box (Box& b)     // may not be triggered, compiler will optimize
   {
       cout << "in Box copy constructor" << endl;
   }
   
    ~Box()
    {
        cout << "in Box desconstructor: getVolume() = ";
        cout << this->getVolume() << endl;
    }
      inline double getVolume(void)
      {
         return length * breadth * height;
      }
      void setLength( double len )
      {
          length = len;
      }
      void setBreadth( double bre )
      {
          breadth = bre;
      }
      void setHeight( double hei )
      {
          height = hei;
      }
      
   private:
      double length;      // 长度
      double breadth;     // 宽度
      double height;      // 高度
};

// 重载 + 运算符，用于把两个 Box 对象相加
Box Box::operator+(const Box& b)    //definition outside the class
{
    cout << "enter Box::operator+ func" << endl;
    Box box;    //construct a temp obj;
    // inside the class, private member(length, breadth, height) can access directly.
    box.length  = length + b.length;            //without this keyword
    box.breadth = this->breadth + b.breadth;    //with this keyword
    box.height  = this->height + b.height;
    
    cout << "before func return" << endl;
    return box;     // Returning an object invokes the copy constructor
}

// 程序的主函数
int main( )
{
   Box Box1;                // 声明 Box1，类型为 Box
   Box Box2;                // 声明 Box2，类型为 Box
   Box Box3;                // 声明 Box3，类型为 Box
   double volume = 0.0;     // 把体积存储在该变量中
 
   // Box1 详述
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);
 
   // Box2 详述
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);
 
   // Box1 的体积
   volume = Box1.getVolume();
   cout << "Volume of Box1 : " << volume <<endl;
 
   // Box2 的体积
   volume = Box2.getVolume();
   cout << "Volume of Box2 : " << volume <<endl;
 
   // 把两个对象相加，得到 Box3
   Box3 = Box1 + Box2;      // Box3 = Box1.add(Box2);
 
   // Box3 的体积
   volume = Box3.getVolume();
   cout << "Volume of Box3 : " << volume <<endl;
 
   return 0;
}