/*
Class Templates Like function templates, 
class templates are useful when a class defines something 
that is independent of data type. Can be useful for classes like 
LinkedList, BinaryTre, Stack, Queue, Array, etc.
*/

#include <iostream> 
using namespace std; 
  
template <typename T> 
class Array { 
private: 
    T *ptr; 
    int size; 
public: 
    Array(T arr[], int s); 
    void print(); 
}; 
  
template <typename T> 
Array<T>::Array(T arr[], int s) { 
    ptr = new T[s]; 
    size = s; 
    for(int i = 0; i < size; i++) 
        ptr[i] = arr[i]; 
} 
  
template <typename T> 
void Array<T>::print() { 
    for (int i = 0; i < size; i++) 
        cout<<" "<<*(ptr + i); 
    cout<<endl; 
} 
  
int main() { 
    int arr1[5] = {1, 2, 3, 4, 5}; 
    Array<int> o1(arr1, 5); 
    o1.print(); 

    char arr2[5] = {'i','r', 'w','i','n'};
    Array<char> o2(arr2,5);
    o2.print();

    return 0; 
} 