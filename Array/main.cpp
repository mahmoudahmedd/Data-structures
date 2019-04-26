#include <iostream>
#include "array.h"

using namespace std;

int main()
{
    Array<int> a;

    int sum = 0;

    a.push_back(100);
    a.push_back(200);
    a.push_back(300);

    while (!a.empty())
    {
        sum += a.back();
        a.pop_back();
    }

    cout << "The elements of (a) add up to " << sum << endl;
    cout << "my array stores " << a.size() << " numbers." << endl;

    a.push_back(1);
    a.push_back(2);

    int *p = a.data();
    *p = 10;
    ++p;
    *p = 20;

    cout << "(a) contains:";
    for (int i = 0; i < a.size(); ++i)
        cout << ' ' << a[i];
    cout << endl;

    return 0;
}
