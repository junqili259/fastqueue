#include"FastQueue.h"
#include<iostream>
using std::cout;
using std::endl;

int main()
{
	FastQueue<int> obj;
	//cout << obj.size() << endl;
	//cout << obj.head() << endl;
	//cout << obj.tail() << endl;
	//cout << obj.capacity() << endl;
	//obj.dequeue();

	obj.enqueue(1);
	cout << "Size: " << obj.size() << endl;

	obj.enqueue(2);
	cout << "Size: " << obj.size() << endl;

	obj.enqueue(3);
	cout << "Size: " << obj.size() << endl;

	obj.enqueue(4);
	cout << "Size: " << obj.size() << endl;

	obj.enqueue(5);
	cout << "Size: " << obj.size() << endl;

	obj.enqueue(6);
	cout << "Size: " << obj.size() << endl;

	obj.enqueue(7);
	obj.enqueue(8);
	obj.enqueue(9);
	obj.enqueue(10);

	obj.print();

	obj.enqueue(11);
	cout << "Size: " << obj.size() << endl;
	cout << "Capacity: " << obj.capacity() << endl;
	
	obj.print();

	return 0;
}