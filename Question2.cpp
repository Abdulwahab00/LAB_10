#include<iostream>
using namespace std;

class MaxHeap
{
	int* nw;
	int size;
	int no;
public:
	MaxHeap(int s)
	{
		size = s;
		nw = new int[size];
		no = 0;
	}
	void insertInArray(int key)
	{
		if (no < size)
		{
			nw[no++] = key;
		}
		else cout << "out of size\n";
	}
	void heapify(int x)
	{
		int l, r;
		int h = x;
		l = 2 * x + 1;
		r = 2 * x + 2;
		if (l < no && nw[l] > nw[h])
			h = l;
		if (r < no && nw[r] > nw[h])
			h = r;
		if (h != x)
		{
			int temp = nw[x];
			nw[x] = nw[h];
			nw[h] = temp;

			heapify(h);
		}
	}
	void Display()
	{
		for (int i = 0; i < size; i++)
			cout << nw[i] << " ";
		cout << endl;
	}
	void createHeap()
	{
		for (int i = size - 1; i >= 0; i--)
		{

			heapify(i);
		}
	}
};
int main()
{
	int x=0;
	cout << "Enter the size of heap: ";
	cin >> x;
	MaxHeap obj(x);

	while (x != -222)
		        {
		        cout << "Enter the Element You want to insert OR Press -222 to Exit" << endl;
		        if (x != -222)
		        {
		            cin >> x;
		            obj.insertInArray(x);
		
		        }
		        }
	
	cout << "Before Heap: ";
	obj.Display();
	obj.createHeap();
	cout << "After heap ";
	obj.Display();

}
