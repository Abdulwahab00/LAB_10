#include<iostream> 
using namespace std;

class MinHeap
{
    int* harr;
    int capacity; 
    int heap_size; 
public:
    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        harr = new int[cap];
    }

    int parent(int i) 
    {
        return (i - 1) / 2; 
    }

    int left(int i)
    { 
        return (2 * i + 1);
    }

    int right(int i) 
    {
        return (2 * i + 2); 
    }
    
    int getMin()
    {
        return harr[0]; 
    }

    void swap(int* x, int* y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }

   

    void insertKey(int k)
    {
        if (heap_size == capacity)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }

        heap_size++;
        int i = heap_size - 1;
        harr[i] = k;

        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    void decreaseKey(int i, int new_val)
    {
        harr[i] = new_val;
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(&harr[i], &harr[parent(i)]);
            i = parent(i);
        }
    }

    int extractMin()
    {
        if (heap_size <= 0)
            return INT_MAX;
        if (heap_size == 1)
        {
            heap_size--;
            return harr[0];
        }

        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);

        return root;
    }


    void deleteKey(int i)
    {
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i)
        {
            swap(&harr[i], &harr[smallest]);
            MinHeapify(smallest);
        }
    }

};


int main()
{
    int x;
    cout << "Enter the size of heap: " ;
    cin >> x;
    MinHeap obj(x);
    
    int opt;
    do
    {
    cout << "Press 1 insert()" << endl
        << "Press 2 Delete()"<<endl
        << "Press 3 getMini()" << endl
        << "Press 4 extractMin()" << endl
        << "Press 5 decreaseKey()" << endl
        <<"Press 0 Exit()"<<endl;
    
    cin >> opt;
    switch (opt)
    {
    case 1:
    {
        while (x!=-222)
        {
        cout << "Enter the Element You want to insert OR Press -222 to Exit" << endl;
        cin >> x;
        if (x != -222)
        {
           
            obj.insertKey(x);

        }
        }
        break;
    }
    case 2:
    {
        cout << "Enter the index Number to Delete the value" << endl;
        cin >> x;
         obj.deleteKey(x);
         cout << "********Value deleted********" << endl;
         break;
    }
    case 3:
    {
        cout << "Minimum value is " << obj.getMin() << endl;
        break;
    }
    case 4:
    {
        cout << "Minimum value " << obj.extractMin() << " is Extracted" << endl;
        break;
    }
    case 5:
    {
        int y;
        cout << "Enter the index Number" << endl;
        cin >> x;
        cout << "Enter the New value" << endl;
        cin >> y;
        obj.decreaseKey(x, y);
        cout << "Value Updated" << endl;
        break;
    }
    }
    } while (opt!=0);

    return 0;
}