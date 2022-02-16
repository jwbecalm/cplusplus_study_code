//轉載 https://blog.csdn.net/lijinqi1987/article/details/79092897

#include <iostream>
#include <memory>   //使用shared_ptr需要include它
using std::endl;
using std::cout;

int main() {
    //通过make_shared创建shared_ptr
    std::shared_ptr<int> p1 = std::make_shared<int>();
    std::shared_ptr<float>p11 = std::make_shared<float>(3.14);
    // create p12, point to 3.14 's store address
    std::shared_ptr<float>p12 = std::make_shared<float>(*p11);    

    *p1 = 78;
    std::cout << "*p1 = " << *p1 << std::endl;
    std::cout << "*p11 = " << *p11 << std::endl;
    std::cout << "*p12 = " << *p12 << std::endl;

    cout << "p1 = " << p1 << endl;
    cout << "p11 = " << p11 << endl;
    cout << "p12 = " << p12<< endl;

    cout << "p1.get() = " << p1.get() << endl;
    cout << "p11.get() = " << p11.get() << endl;
    cout << "p12.get() = " << p12.get() << endl;
    
    //查看引用计数
    std::cout << "p1 Reference count = " << p1.use_count() << std::endl;
    
    //第二个shared_ptr也将在内部指向相同的指针
    //这将会使引用计数变为2
    std::shared_ptr<int> p2(p1);
    
    //查看引用计数
    std::cout << "p2 Reference count = " << p2.use_count() << std::endl;
    std::cout << "p1 Reference count = " << p1.use_count() << std::endl;
    
    //比较智能指针
    if (p1 == p2) {
        std::cout <<"p1= " << p1 << endl;
        std::cout << "p1 and p2 are pointing to same pointer\n";

    }
    
    std::cout << "Reset p1" << std::endl;
    
    //重置shared_ptr，在这种情况下，其内部不会指向内部的任何指针
    //因此其引用计数将会变为0
    p1.reset();
    std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;
    
    //重置shared_ptr，在这种情况下，其内部将会指向一个新的指针
    //因此其引用计数将会变为1
    p1.reset(new int(100));
    std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;
    
    //分配nullptr将取消关联指针并使其指向空值
    p1 = nullptr; 
    std::cout << "p1 Reference Count = " << p1.use_count() << std::endl;
    
    if (!p1) {
        std::cout << "p1 is NULL" << std::endl;
    }
 
  return 0;
}