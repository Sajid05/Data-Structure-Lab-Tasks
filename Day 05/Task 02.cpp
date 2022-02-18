#include<bits/stdc++.h>

using namespace std;

void buildMaxHeap(int A[], int N);
void maxHeapify(int A[], int N, int i);

void heapSort(int A[], int N);


int main()
{
    int N;
    cout << "Enter number of elements : " ;
    cin >> N;
    int *a = new int[N + 1]; // Indexing starts from 1
    for(int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    buildMaxHeap(a, N);
//    for(int i = 1; i <= N; i++)
//    {
//        cout << a[i] << " ";
//    }
    cout << endl;
    heapSort(a, N); // sorts array in ascending order
    for(int i = 1; i <= N; i++)
    {
        cout << a[i] << " ";
    }

    delete []a;

    return 0;
}

void buildMaxHeap(int A[], int N)
{
    for(int i = N / 2; i >= 1; i--)
    {
        maxHeapify(A, N, i);
    }
    return;
}

void maxHeapify(int A[], int N, int i)
{
    //if(i > N / 2) return;
    int parent = i;
    int largest = parent;
    int left = 2 * i;
    int right = left + 1;
    if(!(left > N))
    {
        if(A[left] > A[largest]) largest = left;
    }
    if(!(right > N))
    {
        if(A[right] > A[largest]) largest = right;
    }
    if(largest != parent)
    {
        swap(A[parent], A[largest]);
        maxHeapify(A, N, largest);
    }
    return;
}


void heapSort(int A[], int N)
{
    int heapSize = N;
    while(heapSize)
    {
        swap(A[1], A[heapSize]);
        //cout << A[heapSize] << " ";
        heapSize--;
        maxHeapify(A, heapSize, 1);
    }
}








