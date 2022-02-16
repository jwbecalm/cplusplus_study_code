// make_shared example
#include <iostream>
#include <memory>

class Test{
    int i;
    int j;
    Test(int i_, int j_):i(_i), j(_j){
        
    }


};

int main () {

    //-------------------------------------------------------------
    std::shared_ptr<int> foo = std::make_shared<int> (10);
    // same as:
    std::shared_ptr<int> foo2 (new int(10));

    auto bar = std::make_shared<int> (20);

    auto baz = std::make_shared<std::pair<int,int>> (30,40);

    std::cout << "*foo: " << *foo << '\n';
    std::cout << "*foo2: " << *foo2 << '\n';
    std::cout << "*bar: " << *bar << '\n';
    std::cout << "*baz: " << baz->first << ' ' << baz->second << '\n';

    //-------------------------------------------------------------


    return 0;


}