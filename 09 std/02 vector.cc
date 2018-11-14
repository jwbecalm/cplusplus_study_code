/*
Introduced in C++03, std::vector provides dynamic array functionality 
that handles its own memory management. 
This means you can create arrays that have their length set at runtime, 
without having to explicitly allocate and deallocate memory using new and delete.
*/

#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    //Note that in both the uninitialized and initialized case, 
    //you do not need to include the array length at compile time. 
    //This is because std::vector will dynamically allocate memory for its contents as requested
    vector<int> array;                  // no need to specify length at initialization
    vector<int> array2 = {9,7,5,3,1};   // use initializer list to initialize array
    vector<int> array3{9,7,5,3,1};      // use uniform initialization to initialize array (C++11 onward)

    array = { 0, 1, 2, 3, 4 }; // okay, array length is now 5

    //vector keeps track of its length. We can ask for the vector’s length via the size() function
    std::cout << "The length is: " << array.size() << '\n';

    array.resize(10);   //Resizing the vector
    std::cout << "After resize, the length is: " << array.size() << '\n';
    //when we resized the array, the existing element values were preserved! 
    //Second, new elements are initialized to the default value for the type (which is 0 for integers)
    for (auto const &element: array)
        std::cout << element << ' ';
    cout << endl;

    return 0;
}
