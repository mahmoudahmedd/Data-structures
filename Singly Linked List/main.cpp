#include <iostream>
#include "linked_list.h"

using namespace std;

int main()
{
    LinkedList<int> l1;
	LinkedList<int> l2;

	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);

	l2 = l1;

	l2.print();
	cout << "SIZE = " << l2.size() << endl << endl;
	
    return 0;
}
