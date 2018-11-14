/*
This type of polymorphism is achieved by Function Overriding.
Function overriding on the other hand occurs 
when a Derived class has a definition for one of the member functions 
of the Base class. That Base function is said to be overridden.

the biggest benefit of virtual functions -- 
the ability to structure your code in such a way that 
newly derived classes will automatically work with the old code without modification!

*/
#include <iostream>
using namespace std; 
  
class Base 
{ 
public: 
    virtual void test();
    virtual void print () 
    { cout<< "print Base class" <<endl; } 
   
    void show () 
    { cout<< "show Base class" <<endl; } 
}; 
   
class Derived : public Base 
{ 
public: 
    virtual void test();
    void print () //print () is already virtual function in Derived class, we could also declared as virtual void print () explicitly 
    { cout<< "print Derived class" <<endl; } 
   
    void show () 
    { cout<< "show Derived class" <<endl; } 
}; 

void Derived::test() {
    cout << "in void Derived::test()" << endl;
}
  
//main function 
int main()  
{ 
    Base *bptr;     // 创建一个指向Base对象的指针变量
    Derived d;      // 创建一个Derived类的对象d
    bptr = &d;      // 子类对象的地址，赋值给父类指针变量
       
    //virtual function, binded at runtime (Runtime polymorphism) 
    bptr->print();  
       
    // Non-virtual function, binded at compile time 
    bptr->show();  
  
    return 0; 
}  