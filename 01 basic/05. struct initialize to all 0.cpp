#include <iostream>
using std::cout;
using std::endl;

struct sSub {
    int c;
    double d;
};
struct sTest {
    int a;
    float b;
    sSub s;
};

int main(){
    sTest x;        // receives no initialization,  leaves them at unspecified values
    sTest y = {};   // make all members zero, Note that it is recursive
    cout << x.a << '\t'<< x.b << '\t'<< x.s.c << '\t'<< x.s.d << endl;
    cout << y.a << '\t'<< y.b << '\t'<< y.s.c << '\t'<< y.s.d << endl;
    return 0;
}