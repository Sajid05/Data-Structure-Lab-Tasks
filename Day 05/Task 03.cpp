#include<bits/stdc++.h>

using namespace std;

void buildMinHeap(int A[], int N);
void minHeapify(int A[], int N, int i);

void heapSort(int A[], int N);
void showHeap(int A[], int N);

int heapMinimum(int A[], int N);
int extractMinimum(int A[], int *N);
void minHeapInsert(int A[], int *N, int size, int value);
void heapDecreaseKey(int A[], int N);


int main()
{
    int N, size;
    cout << "Enter maximum size of heap: ";
    cin >> size;
    cout << "Enter number of elements : " ;
    cin >> N;

    int *a = new int[size + 1]; // Indexing starts from 1
    for(int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    buildMinHeap(a, N);
//    for(int i = 1; i <= N; i++)
//    {
//        cout << a[i] << " ";
//    }

    //heapSort(a, N);
    for(int i = 1; i <= N; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    int options;
    do
    {
        cout << "1. Heap Minimum\n2. Heap_extract_min\n3. Min_heap_insert\n4. Heap_decrease_key\n5. Show Heap\n6. Exit\n";
        cin >> options;
        switch(options)
        {
        case 1:
            cout << heapMinimum(a, N) << endl;
            break;
        case 2:
            cout << extractMinimum(a, &N) << endl; // Call by address as number of elements (N) will decrease
            break;
        case 3:
            int value;
            cout << "Enter value to be inserted : ";
            cin >> value;
            minHeapInsert(a, &N, size, value); // Call by address as number of elements (N) will increase
            break;
        case 4:
            heapDecreaseKey(a, N);

            break;
        case 5:
            showHeap(a, N);
            break;



        }
    }
    while(options != 6);
    delete []a;
    return 0;
}

void buildMinHeap(int A[], int N)
{
    for(int i = N / 2; i >= 1; i--)
    {
        minHeapify(A, N, i);
    }
    return;
}

void minHeapify(int A[], int N, int i)
{
    //if(i > N / 2) return;
    int parent = i;
    int largest = parent;
    int left = 2 * i;
    int right = left + 1;
    if(!(left > N))
    {
        if(A[left] < A[largest]) largest = left;
    }
    if(!(right > N))
    {
        if(A[right] < A[largest]) largest = right;
    }
    if(largest != parent)
    {
        swap(A[parent], A[largest]);
        minHeapify(A, N, largest);
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
        minHeapify(A, heapSize, 1);
    }
}

void showHeap(int A[], int N)
{
    for(int i = 1; i <= N; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;

}

int heapMinimum(int A[], int N)
{
    return A[1];
}

int extractMinimum(int A[], int *N)
{
    int ans = A[1];
    for(int i = 1; i < *N; i++)
    {
        A[i] = A[i + 1]; // Shift all the elements to it's left
    }
    (*N)--; // Decrease number of elements
    buildMinHeap(A, *N); // Again build min heap for the modified array
    return ans; // return the min from initial heap
}

void minHeapInsert(int A[], int *N, int size, int value)
{
    if((*N) == size)
    {
        cout << "Heap is completely occupied! Extract elements to insert more!" << endl; // N can't exceed size
    }
    else
    {

        (*N)++;
        A[*N] = value; // Add new value to the last position of A
        buildMinHeap(A, *N); // Build new min heap for the modified array
    }
}

void heapDecreaseKey(int A[], int N)
{
    showHeap(A, N);
    cout << "Which position you want to modify? (Indexing starts from 1)" << endl;
    int position, modified_value;
    cin >> position;
    cout << "What is the modified value?" << endl;
    cin >> modified_value;
    A[position] = modified_value; // Chang the position
    buildMinHeap(A, N); // Build new min heap for the modified array
}





