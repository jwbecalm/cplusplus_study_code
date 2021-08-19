// from thinking in c++ chapter 5 and ex06

/**
Create a Hen class. Inside this, nest a Nest class. Inside Nest, place an Egg class.
Each class should have a display( ) member function. In main( ), create an instance
of each class and call the display( ) function for each one.
**/

/**
Nest and Egg are just like normal classes except they reside in the scope of other classes 
instead of the global scope, which explains the need for the explicit qualification 
via the scope resolution operator. Also, Hen has no access rights to any private members 
of Nest or Egg, nor does Nest have any rights to Egg’s private members.
**/
#include <iostream>

using namespace std;


class Hen {
public:
    void display(){cout  << "in Hen::display()" << endl;}

    class Nest{
    public:
        void display(){cout  << "in Hen::Nest::display()" << endl;}

        class Egg {
        public:
            void display(){cout  << "in Hen::Nest::Egg:display()" << endl;}
        };
    }; 
};

int main(){
    Hen n;
    Hen::Nest h;
    Hen::Nest::Egg e;

    n.display();
    h.display();
    e.display();
    
    return 0;
}