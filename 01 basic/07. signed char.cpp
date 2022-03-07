#include <iostream>

using namespace std;

signed char Convert(int prachCelevel){
    if (prachCelevel >= 1 && prachCelevel <= 3){
        return prachCelevel - 1;
    }
    else{
        return 0;
    }
}

int main(){
    unsigned int prachCelevel = 1;
    unsigned int nbCeLevel = Convert(prachCelevel);
    cout << "unsigned int nbCelLevel = " << nbCeLevel << endl;

    signed char ceLevel = Convert(prachCelevel);
    cout << "signed char ceLevel = " << (unsigned int)ceLevel << endl;

    switch (ceLevel){
        case 0:
            cout << "ceLevel_0 = " << (unsigned int)ceLevel << endl;
            break;
        case 1:
            cout << "ceLevel_1 = " << (unsigned int)ceLevel << endl;
            break;
        case 2:
            cout << "ceLeve_2 = " << (unsigned int)ceLevel << endl;
            break;
        default:
            cout << "error" << endl;
    }
}