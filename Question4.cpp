#include<iostream>
using namespace std;

class maxHeap {


public:
	int* tree;
	bool isMax(int i, int no)
	{
		int l, r;
		l = 2 * i + 1;
		r = 2 * i + 2;
		if (r > no)
			return true;
		if (tree[i] > tree[l] && tree[i] > tree[r])
		{
			if (isMax(l, no) && isMax(r, no))
				return true;
		}

		return false;
	}
};

int main()
{
	maxHeap obj;
	int arr[] = { 90, 15, 10, 7, 12, 2 };
	obj.tree = arr;

	cout << "Array is ";
	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
	cout << "\n\n";

	if (obj.isMax(0, 6))
	{
		cout << "It is a max heap" << endl;
	}
	else
	{
		cout << "It is not a max heap";
	}
}