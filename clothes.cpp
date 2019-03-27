#include <iostream>

#include <cstdlib>

using namespace std;

int findMaxElement(long int* arr, int n)
{
    int maxElementIdx = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[maxElementIdx] < arr[i])
        {
            maxElementIdx = i;
        }
    }

    return maxElementIdx;
}

bool f(long int* arr, int n, long int t, long int k)
{
    long int arr_copy[n];
    for(int i = 0; i< n; i++)
    {
        arr_copy[i] = arr[i];
    }
    int j = 0;
    int maxElementIdx = findMaxElement(arr_copy, n);
    while(j < t)
    {
        for(int i = 0; i < n; i++)
        {
            if(i == maxElementIdx)
            {
                arr_copy[i]-=k;
            } else
            {
                if(arr_copy[i] != 0)
                {
                    arr_copy[i]--;
                }
            }
        }

        maxElementIdx = findMaxElement(arr_copy, n);
        j++;

        if(arr_copy[maxElementIdx] <= 0)
        {
           return true;
        }
    }
    return false;

}

int binarySearch(long int* interval, int low, int high, long int* arr, int n, long int k)
{
    int minMinutes = -1;
    while(low <= high)
    {
        int middle = low + (high - low)/2;
        if(f(arr, n, interval[middle], k))
        {
            minMinutes = interval[middle];
            high = middle - 1;
        } else
        {
            low = middle + 1;
        }
    }
  return minMinutes;
}

int main()
{
    int n;
    cin >> n;
    long int arr[n];
    int k;
    cin >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

   long int maxElementIdx=findMaxElement(arr, n);

    if(k == 1)
    {
        cout << arr[maxElementIdx];
    } else
    {
        long int interval[arr[maxElementIdx]];
        for(int i = 0; i < arr[maxElementIdx]; i++)
        {
            interval[i] = i + 1;
        }

       cout << binarySearch(interval, 0, arr[maxElementIdx] - 1, arr, n, k);

    }

    return 0;
}
