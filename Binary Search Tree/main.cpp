#include <iostream>
#include "binary_search_tree.h"

using namespace std;

int main()
{
    BinarySearchTree<int> b;

	b.insert(1);
	b.insert(2);

	cout << "SIZE = " << b.size() << endl << endl;
	
    return 0;
}
