 // 3. For initialization of member objects which do not have default constructor: 

 #include <iostream>
using namespace std;
 
class A {
    int i;
public:
    A(int );
};
 
A::A(int arg) {
    i = arg;
    cout << "A's Constructor called: Value of i: " << i << endl;
}
 
// Class B contains object of A
class B {
    A a;
    int i;
public:
    B(int , int);
};
 
B::B(int x, int y):a(x), i(y) {  //Initializer list must be used
    cout << "B's Constructor called" << endl;
}
 
int main() {
    B obj(10, 100);

    A a(99);
    return 0;
}
/* OUTPUT:
    A's Constructor called: Value of i: 10
    B's Constructor called
*/