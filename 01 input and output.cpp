#include <iostream>
#include <string>
using namespace  std;

int main(int argc, char const *argv[])
{
    int i,j ;
    double d;
    string s;   //C++新增字符串类型；C语言中没有，通常用字符数组或字符指针代替。

    i = 10;
    d = 123.45;
    s = "HelloWorld!";

    cout <<"please input a interger: ";
    cin >> j;

    cout << "i = " << i << "\n";
    cout << "j = " << j << "\n";
    cout << "d = " << d << endl;    //endl 等同于"\n"
    cout << "s = " << s << "\n";
    return 0;
}


