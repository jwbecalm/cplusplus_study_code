#include<iostream>
using namespace std;
int main() {
    int a = 1, b = 3;
    
    // a right now is 00000001
    // Left shifting it by 3 will make it 00001000, ie, 8
    // a = a << 3;
    a << 3;
    cout << a << endl;
        
    // b right now is 00000011
    // Right shifting a by 2 will make it 00000001, ie, 1
    // b = b >> 1;
    b >> 1;
    cout << b << endl;
    return 0;
}