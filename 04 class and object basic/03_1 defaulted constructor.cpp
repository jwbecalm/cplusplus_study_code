#include <iostream>
using namespace std;

class Point 
{
    int x;
    int y;

public:
    Point(int x, int y)
    {
        cout << "in Point(int x, int y)" <<endl;
        this->x = x;
        this->y = y;
    }
    Point() = default;  // defaulted constructor
};

typedef enum checkReslut
{
    COMPLETE,
    PEND
}checkReslut;

struct sttype 
{
    checkReslut cr;
    //st() = default;
};

int main(int argc, char const *argv[])
{
    Point p1;   // if no defaulted constructor, compile error: no default constructor exist
    
    //enum type test
    checkReslut cr;     // define a enum type variable
    cr = COMPLETE;      // give value to the variable
    cout << "cr = " << cr << endl;

    sttype st;
    st.cr = PEND;
    cout << "st.cr = " << st.cr << endl;
    return 0;
}
