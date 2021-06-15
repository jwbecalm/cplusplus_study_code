#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
    vector<int> vec;    // define a int vector

    cout << "vector size = " << vec.size() << endl;

    for (int i = 0; i< 5; i++) {
        vec.push_back(i);
    }
    cout << "vector size = " << vec.size() << endl;

    // 用数组方式访问vector内容: vec[]
    for (int j = 0; j < vec.size(); j++) {
        cout << "vector[" << j << "] = " << vec[j] << endl;

    }
    // 用迭代器访问vector内容 *it
    // 定义一个迭代器，用while遍历输出
    vector<int>::iterator vi = vec.begin();
    while (vi != vec.end()) {
        cout << *vi << endl;
        vi++;
    }
    cout << "-------------------" << endl;
    // 定义一个迭代器，用for遍历输出
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++) {
        cout << *it << endl;
    }
    cout << "-------------------" << endl;
    // 用auto自动推导变量类型，使用auto替代vector<int>::iterator
    for (auto a = vec.begin(); a != vec.end(); a++) {
        cout << *a << endl;
    }
    return 0;
}
