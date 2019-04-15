#include <iostream>
#include <vector>
#include "priority_queue.h"

using namespace std;

int main()
{
	//vector<int> *v = new vector<int>[5];
    PriorityQueue<string> q;

	q.enqueue("Ahmed", 2);
	q.enqueue("Mahmoud",5);
	q.enqueue("Tawfik", 1);
	
    while(!q.empty())
    {
        cout << q.dequeue() << endl;
    }

    cout << endl << "SIZE = " << q.size() << endl << endl;

    return 0;
}
