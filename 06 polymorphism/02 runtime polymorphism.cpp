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
    virtual void test()
    { cout<< "Base::test()" <<endl; } 

    virtual void print () 
    { cout<< "Base::print()" <<endl; } 
   
    virtual void printData() const{
        cout<< "Base::printData()" <<endl;
    }

    virtual void build(){
        cout << "Base::build()" << endl;
    }

    void show ()    // non virtual method
    { cout<< "Base::show()" <<endl; } 

    void setup(){   // in Base class method, invoke subClass method in runtime
        //build();
        // build() equal to:
        this->build();
    }
    

}; 
   
class Derived : public Base 
{ 
public: 
    virtual void test() override /*final*/;
    void print () override  //print () is already virtual function in Derived class, we could also declared as virtual void print () explicitly 
    { cout<< "Derived::prinit()" <<endl; } 
   
    void show () 
    { cout<< "Derived::show()" <<endl; } 

    void printData() const override;

    void build(){
        cout << "Derived::build()" << endl;
    }
}; 

void Derived::printData() const{
    cout << "Derived::printData()" << endl;
}

void Derived::test() /*override*/ {     // error: virt-specifiers in 'test' not allowed outside a class definition
    cout << "Derived::test()" << endl;
}
  

class SecondDerived: public Derived{
    public:
    virtual void test() override;   // compile error the parent class function is final, so cannot override by child.
};
void SecondDerived::test(){
    cout << "SecondDerived::test()" << endl; 
}

//main function 
int main()  
{ 
    Base *bptr;     // 创建一个指向Base对象的指针变量
    Derived d;      // 创建一个Derived类的对象d
    bptr = &d;      // 子类对象的地址，赋值给父类指针变量
       
    //virtual function, binded at runtime (Runtime polymorphism) 
    bptr->print();  
    bptr->test();
    bptr->printData();
    bptr->setup();
       
    // Non-virtual function, binded at compile time 
    bptr->show();  

    Derived *d2;
    SecondDerived sd;
    d2 = &sd;
    d2->test();

    return 0; 
}  