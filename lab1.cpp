// lab1.cpp - convert this code to C11

/*
 *  This code should compile cleanly with the following options:
 *
 
    C:   -std=c11   -g -Wall -Wextra -Wpedantic

    C++: -std=c++11 -g -Wall -Wextra -Wpedantic

 */

#include <iostream>
#include <string>

using namespace std;

void bump(int& i, int amount=1)
{
    i += amount;
}

void bump(string& s, char c='o')
{
    s.push_back(c);
}

int main()
{
    int i = 1;

    cout << i << endl;
    bump(i);
    cout << i << endl;
    bump(i, 2);
    cout << i << endl;

    string s = "foo";

    cout << s << endl;
    bump(s);
    cout << s << endl;
    bump(s, 'x');
    cout << s << endl;

    return 0;
}

