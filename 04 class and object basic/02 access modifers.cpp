/*
Public: All the class members declared under public will be available to everyone. 
The data members and member functions declared public can be accessed by other classes too. 
The public members of a class can be accessed from anywhere in the program using 
the direct member access operator (.) with the object of that class.

Private: The class members declared as private can be accessed only by the functions inside the class. 
They are not allowed to be accessed directly by any object or function outside the class. 
Only the member functions or the friend functions are allowed to access the private data members of a class.

Protected: Protected access modifier is similar to that of private access modifiers, 
the difference is that the class member declared as Protected are inaccessible outside the class 
but they can be accessed by any subclass(derived class) of that class.
*/

#include <iostream>

using namespace std;

class Test
{
    public:
        int pub = 10;
    private:
        int pri = 20;
    protected:
        int pro = 30;
        int getPro3()
        {
            return pro;
        }
    public:
        void setPub(int i)
        {
            pub = i;    //public在任何地方都可以访问： inside the class
        }
        // private的成员，只能通过提供成员函数的方式进行访问
        void setPri(int i)
        {
            pri = i;
        }
        int getPri()
        {
            return pri;
        }
        int getPro()
        {
            return pro;
        }
};

class SubTest : public Test
{
    public: 
        int getPro2()
        {
            return pro;
        }
        void setPro2(int i)
        {
            pro = i;
        }

};

int main(int argc, char const *argv[])
{
    Test t;
    // public 在任何地方都可以访问：outside the class
    cout << "pub = " << t.pub << endl;
    t.pub = 11; //public可以通过对象.成员直接访问
    cout << "pub = " << t.pub << endl;
    t.setPub(12);   //public还可以通过对象的成员方法去访问
    cout << "pub = " << t.pub << endl;

    cout << "pri = " << t.getPri() << endl; //private只能通过对象.成员方法去访问
    //private can not acceess outside the class 
    //t.pri = 21; //compile error， 不能通过对象.成员的方式访问
    t.setPri(22);
    cout << "pri = " << t.getPri() << endl;

    // protected 和private类似，但是可以在子类中访问——也只能通过对象.成员方法去访问
    //t.pro = 31; // compile error，基类中无法访问
    //t.getPro3();    //proteced 的方法也无法直接访问
    // but can access in subclass(derived class)
    SubTest  st;
    //st.pro = 32;    //继承类对象，也无法通过.成员的方式去访问
    cout << "pro = " << st.getPro2() << endl;   //通过继承类自己的成员函数进行访问
    st.setPro2(33);
    cout << "pro = " << st.getPro2() << endl;

    
    return 0;
}
