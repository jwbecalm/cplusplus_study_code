#include <iostream>

using namespace std;

int main(){
    unsigned int uiLevel = 2;
    cout << "unsigned int uiLevel = " << uiLevel << endl;

    signed char scLevel = static_cast<signed char>(uiLevel);
    cout << "signed char scLevel = " << (unsigned int)scLevel << endl;

    return 0;
}