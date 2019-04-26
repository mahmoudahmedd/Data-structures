#include <iostream>
#include <string>
#include "unordered_map.h"

using namespace std;

int main()
{
    UnorderedMap<string, int> h;

	h.insert("Mahmoud", 1);
	h.insert("Ahmed", 2);
	h.insert("Tawfik", 3);

	h["Ahmed"]= 4;

	h.print();
	cout << "SIZE = " << h.size() << endl << endl;
	
	h.remove("Mahmoud");

	h.print();
	cout << "SIZE = " << h.size() << endl << endl;
	
    return 0;
}
