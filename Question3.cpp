#include<iostream>
using namespace std;
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void HeapifyDown(int a[], int i, int size)
{
    
    int l = ((2 * i) + 1);
    int r = ((2 * i) + 2);
    if ((l > 0 && l < size) && (r > 0 && r < size))
    {
        if (a[l] <= a[r]) 
        {
            if (a[l] < a[i])
            {
                swap(&a[l], &a[i]);
                HeapifyDown(a, l, size);
            }

        }
        else if (a[r] <= a[l]) 
        {
            if (a[r] < a[i])
            {
                swap(&a[r], &a[i]);
                HeapifyDown(a, r, size);
            }

        }
    }
    else if ((l > 0 && l < size) || (r > 0 && r < size)) 
    {
        if (l > 0 && l < size) 
        {
            if (a[l] <= a[i]) 
            {
                swap(&a[l], &a[i]);
                HeapifyDown(a, l, size);
            }
        }
        else
        {
            if (a[r] <= a[i])
            {
                swap(&a[r], &a[i]);
                HeapifyDown(a, r, size);
            }

        }

    }

}



void Display(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void BuildHeap(int a[], int size)
{
    for (int i = ((size / 2) - 1); i >= 0; i--)
    {
        HeapifyDown(a, i, size);
    }
}
int extractMini(int a[])
{
    return a[0];
}
void KLarge(int a[], int size, int k)
{
    BuildHeap(a, k);
    for (int i = k; i < size; i++)
    {
        if (a[0] < a[i])
        {
            swap(&a[0], &a[i]);
            BuildHeap(a, k);
        }

    }

}

int main(void)
{
    int S, ky;
    cout << "Enter the size for Array : ";
    cin >> S;
    int* Arr = new int[S];
    cout << "Enter data : " << endl;
    for (int i = 0; i < S; i++)
    {
        cin >> Arr[i];
       
    }

    cout << "Data in Array is : ";
    Display(Arr, S);
    cout << "  Enter How many largest elements want to find : ";
    cin >> ky;
    KLarge(Arr, S, ky);
    cout << "  " << ky << " largest elements is : " << endl;
    for (int i = 0; i < ky; i++)
    {
        cout << Arr[i] << " ";
    }
    cout << endl;


    system("pause");
    return 0;
}