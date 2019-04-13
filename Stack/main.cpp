#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    while(!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

    cout << endl << "SIZE = " << s.size() << endl << endl;

    s.push(4);
    s.push(5);
    s.push(6);

    cout << s.top() << endl;

    return 0;
}
