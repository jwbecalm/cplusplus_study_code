// https://www.geeksforgeeks.org/map-find-function-in-c-stl/

#include <iostream>
#include <map>
using namespace std;


int main()
{
 
    // Initialize container
    map<int, int> mp;
 
    // Insert elements in random order
    mp.insert({ 2, 30 });
    mp.insert({ 1, 40 });
    mp.insert({ 3, 20 });
    mp.insert({ 4, 50 });
    // insert a new pair of value by value_type
    mp.insert(map<int,int>::value_type(5,100));
 
    cout << "Elements from position of 3 in the map are : \n";
    cout << "KEY\tELEMENT\n";
 
    // find() function finds the position
    // at which 3 is present
    for (auto itr = mp.find(3); itr != mp.end(); itr++) {
       
        cout << itr->first << '\t' << itr->second << '\n';
    }
    
    // try to find 1
    std::map<int, int>::iterator iter = mp.find(1);
    if (iter != mp.end()){  // find it!
        cout <<"find it! iter->first = " << iter->first <<", iter->second =" << iter->second << endl;
    }
    else{
        cout << "cannot find it.." << endl;
    }
    
    // the other way to find key
    if (mp.count(1))
        cout << "The key 1 is present\n";
    else
        cout << "The key 1 is not present\n";

    /*
    In general, both count and find will use the container-specific lookup methods (tree traversal or hash table lookup),
     which are always fairly efficient. 
     It's just that count has to continue iterating until the end of the equal-range, 
     whereas find does not. Moreover, your code should document intent, so if you want to find something, use find.
    */

   /*
   If you just want to find whether the key exists or not, 
   and don't care about the value, it is better to use map::count as it returns only an integer. 
   map::find returns an iterator, thus by using count, you will save the construction of an iterator
   */

    return 0;
}