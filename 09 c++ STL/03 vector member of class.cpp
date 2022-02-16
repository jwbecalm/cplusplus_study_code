#include <vector>
#include <iostream>
using namespace std;

const int test = 0;

class Sig {
    int intMember;
    std::vector<unsigned int> vMember;

    public:
    Sig();
    Sig(int intMember_,
        const std::vector<unsigned int>& vMember_);

    int getIntMember() const{   // 如果函数返回值采用“值传递方式”，由于函数会把返回值复制到外部临时的存储单元中，加 const 修饰没有任何价值
        return intMember;
    }
    const std::vector<unsigned int>& getVMember() const{
        return vMember;     // Return reference to a vector member variable. https://stackoverflow.com/questions/8384234/return-reference-to-a-vector-member-variable
    }

};

Sig::Sig()
    :intMember(test),
    vMember(std::vector<unsigned int> ())    
{
}

Sig::Sig(int intMember_, const std::vector<unsigned int>& vMember_)
    :
        intMember(intMember_),
        vMember(vMember_)
{
}


class SigMgr{
    public:

    Sig Create(){
        int pdu = 99;

        std::vector<unsigned int> list;
        list.push_back(1);
        list.push_back(2);
        list.push_back(3);

        return Sig(pdu,list);
    }

};

int main()
{
    // Sig sig;
    // cout << "Sig.GetIntMember()= " << sig.getIntMember() << endl;
    // cout << "-------------------" << endl;
    // std::vector<unsigned int>vec = sig.getVMember();
    // // 用auto自动推导变量类型，使用auto替代vector<int>::iterator
    // for (auto a = vec.begin(); a != vec.end(); a++) {
    //     cout << *a << endl;
    // }
    
    SigMgr sigMgr;
    //Sig sig2(sigMgr.Create());
    Sig sig2 = sigMgr.Create();
    cout << "Sig.GetIntMember()= " << sig2.getIntMember() << endl;
    cout << "-------------------" << endl;
    std::vector<unsigned int> vec2 = sig2.getVMember();
    // 用auto自动推导变量类型，使用auto替代vector<int>::iterator
    for (auto a = vec2.begin(); a != vec2.end(); a++) {
        cout << *a << endl;
    }
    return 0;
}