#include <iostream>
using namespace std;

class SIBCtxtBase {
public:
    int mapped = 100;

};


class RRCSIB1Ctxt : public SIBCtxtBase {
public:
    void setInitialCtxt() {
        mapped = 1;      // 子类在继承父类的同时，拥有了父类的public成员; 修改子类的成员不影响父类的成员
    }
};

class RRCSIB2Ctxt : public SIBCtxtBase {
public:
    void setInitialCtxt() {
        mapped = 2;      // 子类在继承父类的同时，拥有了父类的public成员； 修改子类的成员不影响父类的成员
    }
};

class Ctxt {
public:
    RRCSIB1Ctxt sib1ctxt;
    RRCSIB2Ctxt sib2ctxt;
};


int main(){ 
    SIBCtxtBase base;
    cout << "SIBCtxtBase::mapped = " << base.mapped << endl;   // base class mapped value

    Ctxt ctxt;
    ctxt.sib1ctxt.setInitialCtxt();
    cout << "RRCSIB1Ctxt::mapped = " << ctxt.sib1ctxt.mapped << endl;   // sib1 mapped value
    cout << "SIBCtxtBase::mapped = " << base.mapped << endl;   // base class mapped value

    ctxt.sib2ctxt.setInitialCtxt();
    cout << "RRCSIB2Ctxt::mapped = " << ctxt.sib2ctxt.mapped << endl;   // sib2 mapped value
    cout << "SIBCtxtBase::mapped = " << base.mapped << endl;   // base class mapped value


}
