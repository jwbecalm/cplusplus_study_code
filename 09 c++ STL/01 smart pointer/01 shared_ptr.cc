/*
优点和使用场景：
1、自动释放内存
2、程序需要在多个对象间共享数据
3、多线程场景
---------------------
多线程程序经常会遇到在某个线程A创建了一个对象,这个对象需要在线程B使用,
在没有shared_ptr时,因为线程A,B结束时间不确定,即在A或B线程先释放这个对象都有可能造成另一个线程崩溃,
所以为了省时间一般都是任由这个内存泄漏发生.当然也可以经过复杂的设计,由一个监控线程来统一删除,
但这样会增加代码量和复杂度.这下好了,shared_ptr 可以方便的解决问题,因为它是引用计数和线程安全的
--------------------- 
作者：infoworld 
来源：CSDN 
原文：https://blog.csdn.net/infoworld/article/details/50738494 
版权声明：本文为博主原创文章，转载请附上博文链接！
*/
#include<iostream> 
#include<memory> 
using namespace std; 
  
class A 
{ 
public: 
    void show() 
    { 
        cout<<"A::show()"<<endl; 
    } 
}; 
  
int main() 
{ 
    shared_ptr<A> p1 (new A); 
    cout <<"p1 = " << p1 << endl;
    cout << "p1.get()= " << p1.get() << endl; 
    p1->show(); 
    shared_ptr<A> p2 (p1); 
    p2->show(); 
    cout << p1.get() << endl; 
    cout << p2.get() << endl; 
  
    // Returns the number of shared_ptr objects 
    //referring to the same managed object. 
    cout << p1.use_count() << endl; 
    cout << p2.use_count() << endl; 
  
    // Relinquishes ownership of p1 on the object 
    //and pointer becomes NULL 
    p1.reset(); 
    cout << p1.get() << endl; 
    cout << p1.use_count() << endl; 
   
    cout << p2.use_count() << endl; 
    cout << p2.get() << endl; 

    p2.reset(); 
    cout << p2.get() << endl; 
    cout << p2.use_count() << endl; 

  
    return 0; 
} 