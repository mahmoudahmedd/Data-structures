#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    cout << endl << "SIZE = " << q.size() << endl << endl;

    q.push(4);
    q.push(5);
    q.push(6);

    cout << q.front() << endl;

    return 0;
}
