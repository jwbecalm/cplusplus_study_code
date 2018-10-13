
#include <iostream>
using namespace std;

class Animal 
{
public:
    Animal()
    {
        cout << "constructing an Animal" << endl;
    }
    ~Animal()
    {
        cout << "deconstructing an Animal" << endl;
    }
    /*
    without virtual keyword, we get early binding
    even though you're assigning the subclassed object (Cat), 
    the method being invoked is based on the pointer type (Animal) 
    not the type of object it is point to
    */
    virtual void eat()  // with virtual keyword make this func late binding
    {
        cout << "eat a generic food" << endl;
    }
};

class Cat : public Animal 
{
public:
    Cat()
    {
        cout << "constructing a Cat" << endl;
    }
    ~Cat()
    {
        cout << "deconstructing a Cat" << endl;
    }
    void eat()
    {
        cout << "eat a cat food" << endl;
    }
};

class Dog : public Animal 
{
public:
    Dog()
    {
        cout << "constructing a Dog" << endl;
    }
    ~Dog()
    {
        cout << "deconstructing a Dog" << endl;
    }
    void eat()  //overload the eat() function
    {
        cout << "eat a dog food" << endl;
    }
};

// this function can be reuesed/no neeed modify when new animals are created.
void funcOfEat(Animal *animal)  //the input parameter is a base class type, 
                                // can accpet all animal sub class
{
    animal->eat();
}

int main(int argc, char const *argv[])
{
    Animal *pa = new Animal;
    //Cat    *pc = new Cat; // new Class way can't trigger constructor and deconstructor
    Cat objectC;
    Cat *pc = &objectC;

    funcOfEat(pa);
    funcOfEat(pc);

    // we can add a new animal, call the same function
    Dog *pd = new Dog;
    funcOfEat(pd);

    //Dog objectD;    // this way can triger deconstructor auto
    return 0;
}
