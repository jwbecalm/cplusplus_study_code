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
    

    return 0;
}