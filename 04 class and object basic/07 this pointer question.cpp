#include <iostream>
using namespace std;

/* Question 2----------------------------------------------------
class Test
{
  private:
    int x;
    int y;

  public:
    Test(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    static void fun1() { cout << "Inside fun1()" << endl; }
    static void fun2()  //should be void fun2()
    {
        cout << "Inside fun2()" << endl;
        this->fun1();
    }
};

int main()
{
    Test obj;
    obj.fun2();
    return 0;
}
*/

/* question 3-------------------------------------------------------------
class Test
{
  private:
    int x;
    int y;

  public:
    Test(int x = 0, int y = 0)
    {
        this->x = x;
        this->y = y;
    }
    Test setX(int a)    //should be Test&
    {
        x = a;
        return *this;
    }
    Test setY(int b)    //shoule be Test&
    {
        y = b;
        return *this;
    }
    void print() { cout << "x = " << x << " y = " << y << endl; }
};

int main()
{
    Test obj1;
    obj1.setX(10).setY(20);
    obj1.print();
    return 0;
}
*/

