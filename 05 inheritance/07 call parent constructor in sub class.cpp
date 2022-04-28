#include <iostream>
using namespace std;
// https://www.tutorialspoint.com/what-are-the-rules-for-calling-the-superclass-constructor-cplusplus
// https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/


/*output:
Constructor of base class
Constructor of derived class
*/
class MyBaseClass {
   public:
      MyBaseClass() {
         cout << "Constructor of base class" << endl;
      }
};
class MyDerivedClass : public MyBaseClass {
   public:
      MyDerivedClass() {
         cout << "Constructor of derived class" << endl;
      }
};


/*output:
Constructor of base class: 50
Constructor of derived class: 100
*/
class MyBaseClass2 {
   public:
   MyBaseClass2(int x) {
      cout << "Constructor of base class: " << x << endl;
   }
};
class MyDerivedClass2 : public MyBaseClass2 { //base constructor as initializer list
   public:
      MyDerivedClass2(int y) : MyBaseClass2(50) {
         cout << "Constructor of derived class: " << y << endl;
      }
};


int main() {
   MyDerivedClass derived;
   MyDerivedClass2 derived2(100);
}