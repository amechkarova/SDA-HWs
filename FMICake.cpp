#include <iostream>
#include <cstdlib>

using namespace std;

int daysToEat(int* arr, int low, int high)
{
    int k = 0;
    while(low <= high)
    {
        k++;
        int middle = low + (high - low)/2;
        int sum = low + high;
        if(sum%2==0)
        {
            high = middle - 1;
        } else
        {
            low = middle + 1;
        }

    }

    return k;
}

int main()
{
    int tests;
    cin >> tests;
    int n;
    for(int i = 0; i < tests; i++)
    {
        cin >> n;
        int biscuits[n];
        for(int j = 0; j < n; j++)
        {
            biscuits[j] = j + 1;
        }
       cout << daysToEat(biscuits, 0, n-1) << endl;
    }

    return 0;
}
