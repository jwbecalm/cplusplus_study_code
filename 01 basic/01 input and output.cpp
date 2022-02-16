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

    // C++中不同类型的变量，在输出时无需向C语言那样指定不同的类型：%d, %f, %s
    cout << "i = " << i << "\n";
    cout << "j = " << j << "\n";
    cout << "d = " << d << endl;    //endl 等同于"\n"
    cout << "s = " << s << "\n";

    // test for self set value
    int threshold = 2;
    int size = 400;
    if (size <= 600){
        threshold = threshold;
    }
    cout << "threshold = " << threshold << endl;
    return 0;
}


