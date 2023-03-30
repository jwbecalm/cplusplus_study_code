
#include <iostream>

using namespace std;

class TestDataD{
    public:
    int i;
    int j;
};

bool buildData(TestDataD& td){
    td.i = 100;
    td.j = 99;
    return 0;
}
int main(){
    TestDataD td;
    bool result = buildData(td);
    cout << td.i << endl;
    cout << td.j << endl;
    return 0;
}
