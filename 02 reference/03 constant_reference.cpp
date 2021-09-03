// 初始化常量引用时允许用任意表达式作为初始值
int i = 42;  
const int& r1 = i;       //正确：允许将const int & 绑定到一个普通int对象上  
const int& r2 = 42;      //正确  
const int& r3 = r1 * 2;  //正确  
int& r4 = r1 * 2;        //错误  

void f(int&) {}

void g(const int&){}

int main(){
    int m = 1;
    f(m);       // compile ok
    f(1);       // compile error
    g(1);       // 参数是常量，可以确保g函数在任何情况下使用。特别是在单元测试时，给函数直接输入一个值。
}