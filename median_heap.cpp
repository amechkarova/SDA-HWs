#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;


void minHeapInsert(int val, int* minHeap, int& minHeapSize)
{
    minHeap[minHeapSize] = val;
    minHeapSize++;
    int i = minHeapSize - 1;
    while(i > 0 && minHeap[i] < minHeap[(i-1)/2])
    {
        int tmp = minHeap[i];
        minHeap[i] = minHeap[(i-1)/2];
        minHeap[(i-1)/2] = tmp;
        i = (i-1)/2;
    }
}

void maxHeapInsert(int val, int* maxHeap, int& maxHeapSize)
{
    maxHeap[maxHeapSize] = val;
    maxHeapSize++;
    int i = maxHeapSize - 1;
    while(i > 0 && maxHeap[i] > maxHeap[(i-1)/2])
    {
        int tmp = maxHeap[i];
        maxHeap[i] = maxHeap[(i-1)/2];
        maxHeap[(i-1)/2] = tmp;
        i = (i-1)/2;
    }
}


void MinHeapify(int i, int* minHeap, int minHeapSize)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int smallest = i;
    if(l < minHeapSize && minHeap[l] < minHeap[smallest])
    {
        smallest = l;
    }

    if(r < minHeapSize && minHeap[r] < minHeap[smallest])
    {
        smallest = r;
    }

    if(smallest != i)
    {
        int tmp = minHeap[i];
        minHeap[i] = minHeap[smallest];
        minHeap[smallest] = tmp;
        MinHeapify(smallest, minHeap, minHeapSize);
    }

}

void MaxHeapify(int i, int* maxHeap, int maxHeapSize)
{
    int l = 2*i + 1;
    int r = 2*i + 2;
    int largest = i;

    if(l < maxHeapSize && maxHeap[l] > maxHeap[largest])
    {
        largest = l;
    }
    if(r < maxHeapSize && maxHeap[r] > maxHeap[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        int tmp = maxHeap[i];
        maxHeap[i] = maxHeap[largest];
        maxHeap[largest] = tmp;
        MaxHeapify(largest, maxHeap, maxHeapSize);
    }

}

int extractMax(int* maxHeap, int& maxHeapSize)
{
    int res = maxHeap[0];
    maxHeap[0] = maxHeap[maxHeapSize-1];
    maxHeap[maxHeapSize-1] = 0;
    --maxHeapSize;
    MaxHeapify(0, maxHeap, maxHeapSize);
    return res;
}

int extractMin(int* minHeap, int& minHeapSize)
{
    int res = minHeap[0];
    minHeap[0] = minHeap[minHeapSize-1];
    minHeap[minHeapSize - 1] = 0;
    --minHeapSize;
    MinHeapify(0, minHeap, minHeapSize);
    return res;
}


int main()
{
    int n;
    cin >> n;
    int* minHeap = new int[n];
    int* maxHeap = new int[n];
    int maxHeapSize = 0;
    int minHeapSize = 0;
    double currentMedian = 0.0;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if(val < currentMedian)
        {
            maxHeapInsert(val, maxHeap, maxHeapSize);
        } else
        {
            minHeapInsert(val , minHeap, minHeapSize);
        }

        if(abs(maxHeapSize - minHeapSize) > 1)
        {
            if(maxHeapSize > minHeapSize)
            {
                int maxEl = extractMax(maxHeap, maxHeapSize);
                minHeapInsert(maxEl, minHeap, minHeapSize);
            } else if(maxHeapSize < minHeapSize)
            {
                int minEl = extractMin(minHeap, minHeapSize);
                maxHeapInsert(minEl, maxHeap, maxHeapSize);
            }
        }

        if(maxHeapSize == minHeapSize)
        {

            double maxx= maxHeap[0];
            currentMedian = (maxx + minHeap[0])/2;
        } else if(maxHeapSize > minHeapSize)
        {
            currentMedian = maxHeap[0];
        } else if(maxHeapSize < minHeapSize)
        {
            currentMedian = minHeap[0];
        }
        cout << fixed << setprecision(1) << currentMedian << endl;

    }

    delete[] maxHeap;
    delete[] minHeap;

    return 0;
}
