#include <iostream>
#include <cstdlib>

using namespace std;


int firstOccurrence(long long* arr, int low, int high, long long x)
{
    int firstOccurIdx = -2;
    while(low <= high)
    {
        int middle = low + (high - low)/2;

        if(arr[middle] == x)
        {
            firstOccurIdx = middle;
            high = middle - 1;
        }
        if(arr[middle] > x)
        {
            high = middle - 1;
        }
        if(arr[middle] < x)
        {
            low = middle + 1;
        }
    }
    return ++firstOccurIdx;
}

int lastOccurrence(long long* arr, int low, int high, long long x)
{
    int lastOccurIdx = -2;
    while(low <= high)
    {
        int middle = low + (high - low)/2;

        if(arr[middle] == x)
        {
            lastOccurIdx = middle;
            low = middle + 1;
        }
        if(arr[middle] > x)
        {
            high = middle - 1;
        }
        if(arr[middle] < x)
        {
            low = middle + 1;
        }
    }
    return ++lastOccurIdx;
}

void mergeArrs(long long* arr, int left, int middle, int right)
{
    int size1 = middle - left + 1;
    int size2 = right - middle;
    int i, j, k;
    long long L[size1];
    long long R[size2];

    for(i = 0; i < size1; i++)
    {
        L[i] = arr[left + i];
    }
    for(j = 0; j < size2; j++)
    {
        R[j] = arr[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while(i < size1 && j < size2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
            k++;
        } else
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    while(i < size1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < size2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(long long* arr, int left, int right)
{
    if(left < right)
    {
        int middle = (left + right)/2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        mergeArrs(arr, left, middle, right);
    }
}
int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        long long p;
        cin >> p;
        cout << firstOccurrence(arr, 0, n-1, p) << " ";
        cout << lastOccurrence(arr, 0, n-1, p) << endl;

    }
  /* long long numbers[4] = {3000000000, 250000000, 2000000000, 3000000000};
   mergeSort(numbers, 0, 3);
    for(int i = 0; i < 4; i++)
    {
        cout << numbers[i] << " ";
    }
    long long p = 2000000000;
cout << firstOccurrence(numbers, 0, 3, p) << " ";
cout << lastOccurrence(numbers, 0, 3, p);*/

    return 0;
}
