#include <iostream>
#include <memory>
using namespace std;


class Cells{
    public:
    int i;
    Cells();
};

Cells::Cells(){
        cout << "Cells()" << endl;
}

class EnodeB{
    public:
    int id;
    int xx;
    EnodeB();
};

EnodeB::EnodeB():
    id(100),
    xx(1){
    cout << "EnodeB()" << endl;
}


class ConfigurationImpl{
    public:
    Cells cells;
    std::shared_ptr<EnodeB> eNodeB;
    ConfigurationImpl();
};

ConfigurationImpl::ConfigurationImpl():
    cells(),
    eNodeB(std::make_shared<EnodeB>()){
        cout << "ConfigurationImpl()" << endl;
}

int main (){
    ConfigurationImpl conf;
    cout << "conf.cells.i = " << conf.cells.i << endl;
    cout << "conf.eNodeB->id = " << conf.eNodeB->id << endl;
    cout << "conf.eNodeB->xx = " << conf.eNodeB->xx<< endl;

    return 0;
}
