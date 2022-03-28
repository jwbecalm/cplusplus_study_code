// https://stackoverflow.com/questions/46446652/is-there-any-point-in-using-override-when-overriding-a-pure-virtual-function

/*Consider a redesign when the author of the Base decides that 
my_function should no longer be a pure virtual, and also that it should take a new parameter. 
With override in place the compiler will catch this problem; without an override your Derived class would continue to compile.*/

#include <iostream>
using namespace std;

class Base {
  public:
  virtual void my_function() = 0;
};

class Derived : Base {
  //void my_function(int) override;
//                 ^^^ mistake!, accidentally wrote an overload instead, if no override keyword, compile will success
  int i ;

  // 一级继承中，可以不实现Base中的纯虚函数， Derived仍然是接口类，不能实例化。
};

class Third : Derived {
  public:
  // 在二级继承中实现
  void my_function() override {
    cout << "Third:: my_function()" << endl;
  }
};

int main(){
  Third obj;
  obj.my_function();

  Derived d;  //Derived类由于没有实现接口， 仍然是Abstract class，不能实例化。object of abstract class type "Derived" is not allowed
  return 0;
}