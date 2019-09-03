// https://www.geeksforgeeks.org/vector-assign-in-c-stl/

// vector:: assign() is an STL in C++ which assigns new values to the vector elements
// by replacing old ones. It can also modify the size of the vector if necessary.

#include <vector>
#include <iostream>
using namespace std;

int main() 
{ 
    /*Program 1: The program below shows how to assign constant values to a vector*/
    vector<int> v1; 
    v1.assign(7, 100); 
  
    cout << "Size of v1: " << int(v1.size()) << '\n'; 
  
    cout << "Elements are\n"; 
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << endl;
    }
    
    /*Program 2: The program below shows how to assign values from an array or list*/
    vector<int> v2;
    int a[] = {1,2,3};

    // assign firt two value
    v2.assign(a,a+2);
    cout << "Elements are\n"; 
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << endl;
    }

    // assign first three value
    int array_length = sizeof(a)/sizeof(a[0]);
    v2.assign(a,a + array_length );
    cout << "Elements are\n"; 
    for (int i = 0; i < v2.size(); i++) {
        cout << v2[i] << endl;
    }

    /*Program 3: The program below shows how to assign values from an array to a vector ptr*/
    typedef vector<int> testIntVector;
    typedef testIntVector * testIntVectorPtr;

    //v3->assign(a, a + array_length);
    //cout << "v3->size() = " << v3->size() << endl; 
    // for (int i = 0; i < v3->size(); i++) {
    //     cout << (*v3)[i] << endl;
    // }
    return 0; 
} 