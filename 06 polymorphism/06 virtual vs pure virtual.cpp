#include <iostream>
#include <string>

using namespace  std;
// <string.h> is the old C header. C++ provides <string>, and then it should be referred to as std::string

class Parent{
    private:
    string m_description;

    public:
    Parent(string s):m_description(s){
        cout << "in Parent()" << endl;
    }

    string getDescription(){
        return m_description;
    }

    virtual int getType() = 0;

};

class Child :public Parent{
    public:
    Child(string s): Parent(s){
        cout << "in Child()" << endl;
    }
    //virtual string getDescription() = 0;

    // 继承时可以不用实现getType()吗？在下面的子子类中实现。
};

class SubChild: public Child{
    public:
    SubChild(string s): Child(s){
        cout << "in SubChild()" << endl;
    }
    string getDescription(){
        return Parent::getDescription() + " SubChild";
    }

    virtual int getType(){
        cout << "in SubChild::getType()" << endl;
        return 0;
    }
};

int main(){
    // Parent parent("Parent");
    // cout << parent.getDescription()<< endl;

    //Child c = SubChild("SubChild");   // compile error: object of abstract class type "Child" is not allowed: -- function "Child::getDescription" is a pure virtual function
    Child* pchild = new SubChild("SubChild");  // but we can define a base class pointer which points to the instance of the derived class.
    cout << pchild->getDescription() << endl;

    SubChild sc("Hello");
    cout << sc.getDescription() << endl;



    delete pchild;
    return 0;
}