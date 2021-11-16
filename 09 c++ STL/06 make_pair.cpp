/*
https://www.geeksforgeeks.org/pair-in-cpp-stl/
make_pair() : This template function allows to create a value pair without writing the types explicitly. 
Syntax :
Pair_name = make_pair (value1,value2);
*/

#include <iostream>
#include <utility>
using namespace std;
 
int main()
{
    pair <int, char> PAIR1 ;
    pair <string, double> PAIR2 ("GeeksForGeeks", 1.23) ;
    pair <string, double> PAIR3 ;
 
    PAIR1.first = 100;
    PAIR1.second = 'G' ;
 
    PAIR3 = make_pair ("GeeksForGeeks is Best",4.56);
 
    cout << PAIR1.first << " " ;
    cout << PAIR1.second << endl ;
 
    cout << PAIR2.first << " " ;
    cout << PAIR2.second << endl ;
 
    cout << PAIR3.first << " " ;
    cout << PAIR3.second << endl ;
 
    return 0;
}