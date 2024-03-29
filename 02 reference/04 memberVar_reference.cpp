// 成员变量是引用的情况（转载）
// https://blog.csdn.net/lazyq7/article/details/48186291

#include <iostream>
using namespace std;

/*
不能有默认构造函数, 必须提供构造函数
构造函数的形参必须为引用类型
初始化必须在成员初始化列表内完成
*/

class MemberRef {
    int& m_rfData;

    public:
    MemberRef(int &initValue): m_rfData(initValue){}

    void print(){
        cout << "m_rfData = " << m_rfData << endl;
    }
};

int main(){
    int i = 99;
    int& value = i;

    MemberRef m1(value);
    m1.print();
    return 0;
}
